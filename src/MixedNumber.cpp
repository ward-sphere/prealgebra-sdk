#include <MixedNumber.hpp>

#include <stdexcept>

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

void MixedNumber::validateNegatives() {
    if (base.isNegative()) {
        base = -base.getValue();
        negative = true;
    }
    if (fraction.isNegative()) {
        if (base != 0)
            throw std::invalid_argument("Fraction used to construct mixed number must be positive if base is non-zero; pass negative through base only");
        fraction = Fraction(fraction.getNumerator(), fraction.getDenominator());
        negative = true;
    }
}

void MixedNumber::validateMixedNumber() {
    checkProperFraction();
    validateNegatives();
}

MixedNumber::MixedNumber(Integer base, Fraction fraction) : base(base),
        fraction(fraction) {
    validateMixedNumber();
}

MixedNumber::MixedNumber(Integer base, Integer numerator, Integer denominator) : base(base),
        fraction(numerator, denominator) {
    validateMixedNumber();
}

Integer MixedNumber::getBase() const { return this->base; }

Fraction MixedNumber::getFraction() const { return this->fraction; }

bool MixedNumber::isNegative() const { return negative; }

bool MixedNumber::operator==(const MixedNumber& other) const {
    return isNegative() == other.isNegative()
        && getBase() == other.getBase()
        && getFraction() == other.getFraction();
}

bool MixedNumber::operator!=(const MixedNumber& other) const { return !(*this == other); }
