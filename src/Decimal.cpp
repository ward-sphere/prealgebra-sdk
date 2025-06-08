#include <Decimal.hpp>
#include <factory/IDecimalFactory.hpp>

#ifdef DDEBUG
#include <iostream>
#endif

using namespace sdkmath::prealgebra;

sdkmath::prealgebra::factory::IDecimalFactory decimal_factory;

std::unique_ptr<IDecimalArithmetic> Decimal::arithmetic = decimal_factory.createDecimalArithmetic();

Decimal::Decimal(const Decimal& other) {
    decimal = decimal_factory.createDecimalRepresentation();
    decimal->fromPlaceValueVector(other.toPlaceValueVector());
}

Decimal::Decimal(std::string s) {
#ifdef DDEBUG
    std::cout << "-> Decimal::Decimal(" << s << ")" << std::endl;
#endif
    decimal = decimal_factory.createDecimalRepresentation();
    decimal->fromString(s);
#ifdef DDEBUG
    std::cout << "<- Decimal::Decimal: " << toString() << std::endl;
#endif
}

Decimal::Decimal(std::map<int, long> encoded) {
    decimal = decimal_factory.createDecimalRepresentation();

    std::vector<std::pair<int, long>> v;
    for (auto pair : encoded) v.push_back(pair);

    decimal->fromPlaceValueVector(v);
}