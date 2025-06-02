#include <MixedNumber.hpp>

using namespace sdkmath::prealgebra;

void MixedNumber::checkProperFraction() {
    long numerator = fraction.getNumerator().getValue();
    long denominator = fraction.getDenominator().getValue();
    long extra = 0;

    while (numerator >= denominator) {
        numerator -= denominator;
        extra += 1;
    }

    if (extra <= 0) return;

    this->base = Integer(base.getValue() + extra);
    this->fraction = Fraction(Integer(numerator), Integer(denominator));
}

MixedNumber::MixedNumber(Integer base, Fraction fraction) : base(base),
        fraction(fraction) {
    checkProperFraction();
}

Integer MixedNumber::getBase() { return this->base; }

Fraction MixedNumber::getFraction() { return this->fraction; }
