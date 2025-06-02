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

MixedNumber::MixedNumber(Integer base, Integer numerator, Integer denominator) : base(base),
        fraction(numerator, denominator) {
    checkProperFraction();
}

Integer MixedNumber::getBase() const { return this->base; }

Fraction MixedNumber::getFraction() const { return this->fraction; }
