#include <Decimal.hpp>
#include <factory/IDecimalFactory.hpp>
#include <factory/IntegerPropertiesFactory.hpp>

#include <sstream>

#ifdef DDEBUG
#include <iostream>
#endif

using namespace sdkmath::prealgebra;

sdkmath::prealgebra::factory::IDecimalFactory decimal_factory;
std::unique_ptr<IDecimalStringParser> string_parser = decimal_factory.createDecimalStringParser();

Decimal::Decimal(const Decimal& other) { operator=(other); }

Decimal::Decimal(std::string s) {
#ifdef DDEBUG
    std::cout << "-> Decimal::Decimal(" << s << ")" << std::endl;
#endif
    decimal = string_parser->fromString(s);
#ifdef DDEBUG
    std::cout << "<- Decimal::Decimal: " << toString() << std::endl;
#endif
}

Decimal::Decimal(std::map<int, long> decimal) { this->decimal = decimal; }

std::string Decimal::toString() const {
    if (decimal.size() == 0) return "0";
        
        auto it = decimal.begin();
        int min = (*it).first, max = min; ++it;
        auto end = decimal.end();
        for (; it != end; ++it) {
            int curr = (*it).first;
            if (curr < min) min = curr;
            if (curr > max) max = curr;
        }

        min = -1 < min ? -1 : min;

        bool negative = decimal.at(max) < 0;
        std::stringstream ss;
        if (negative) ss << "-";
        if (max < 0) ss << "0.";
        for (int i = max; i >= min; i--) {
            ss << (decimal.count(i) == 1 ? decimal.at(i) : 0) * (negative ? -1 : 1);
            if (i == 0) ss << '.';
        }
        return ss.str();
}

long pow10helper(long x) {
    if (x < 0) return pow10helper(-x);
    if (x == 0) return 1;
    return 10 * pow10helper(x - 1);
}

std::pair<long, long> addFractionHelper(std::vector<std::pair<long, long>>& fractions) {
    if (fractions.size() == 0) return {0, 1};
    if (fractions.size() == 1) return fractions[0];
    
    factory::IntegerPropertiesFactory integer_properties_factory;
    std::unique_ptr<utility::IIntegerProperties> properties = integer_properties_factory.createIntegerProperties();

    std::pair<long, long> x = fractions.back(); fractions.pop_back();
    std::pair<long, long> y = fractions.back(); fractions.pop_back();
    long lcd = properties->lcm(x.second, y.second);

    fractions.push_back(
        {
            (
                (lcd / x.second) * x.first
            ) + (
                (lcd / y.second) * y.first
            ),
            lcd
        }
    );
    return addFractionHelper(fractions);
}

std::pair<long, long> Decimal::toFractionalValues() const {
    std::vector<std::pair<long, long>> decomposition;

    for (std::pair<int, long> pair : decimal) {
        int place = pair.first;
        long value = pair.second;
        if (place < 0) {
            decomposition.push_back(
                {
                    value,
                    pow10helper(place)
                }
            );
        } else {
            decomposition.push_back(
                {
                    value * pow10helper(place),
                    1
                }
            );
        }
    }
    
    return addFractionHelper(decomposition);
}