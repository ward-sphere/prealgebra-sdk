#include <Decimal.hpp>

#include <sstream>
#include <regex>
#include <iterator>
#include <cmath>

#include <iostream>

using namespace sdkmath::prealgebra;

void Decimal::convertLong(long from) {
    std::stringstream ss;
    ss << from << ".0";
    convertString(ss.str());
}

void Decimal::convertDouble(double from) {
    std::stringstream ss;
    ss << from;
    convertString(ss.str());
}

void Decimal::convertFraction(Fraction from) {
    std::stringstream quotient;

    // whole number portion
    long whole = from.getNumerator() / from.getDenominator();
    quotient << whole << '.';

    size_t before_len = quotient.str().size();

    // fractional number portion
    long dividend = from.getNumerator(),
        divisor = from.getDenominator();
    
    dividend -= whole * divisor;
    size_t max_iterations = ctx.minPlacement * -1;
    for (size_t iteration = 0; iteration < max_iterations; iteration++) {
        if (dividend == 0) break;
        dividend *= 10;

        long next = dividend / divisor;
        quotient << next;
        long remainder = dividend % divisor;
        dividend = remainder;
    }

    if (quotient.str().size() == before_len) quotient << '0';

    convertString(quotient.str());
}

void Decimal::convertString(std::string from) {
    // Ensure format
    std::regex rgx("^[-]?\\d*\\.?\\d+$");
    if (!std::regex_match(from, rgx)) {
        std::stringstream ss;
        ss << "Input " << from << " cannot be parsed as decimal";
        throw std::invalid_argument(ss.str());
    }

    // parse negative, if any
    bool negative = false;
    if (from[0] == '-') {
        negative = true;
        from = from.substr(1);
    }

    // encode
    size_t where = from.find('.');
    if (where == std::string::npos) where = from.size();
    for (int i = 0; i < from.size(); i++) {
        if (i == where) continue;
        mValues[where - i] = (from[i] - '0') * (negative ? -1 : 1);
    }
}

double Decimal::toDouble() const {
    double res = 0;
    for (auto pair : mValues)
        res += pow(10, pair.first) * pair.second;
    return res;
}

long pow10helper(int x) {
    if (x == 0) return 1;
    return 10 * pow10helper(x - 1);
}

Fraction Decimal::toFraction() const {
    Fraction res(0, 1);
    for (auto pair : mValues) {
        if (pair.first >= 0) {
            res += Fraction(pair.second * pow10helper(pair.first - 1));
        } else {
            int positive = -pair.first;
            res += Fraction(pair.second, pow10helper(positive));
        }
    }
    res.simplify();
    return res;
}