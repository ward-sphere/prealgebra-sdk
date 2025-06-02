#include <Fraction.hpp>

#include <stdexcept>

using namespace sdkmath::prealgebra;

void Fraction::validateFraction(void) {
    validateDenominator();
    validateNegatives();
}

void Fraction::validateDenominator(void) {
    if (denominator.getValue() == 0)
        throw std::invalid_argument("Denominator must be non-zero");
}

void Fraction::validateNegatives(void) {
    if (numerator.isNegative()) {
        negative = !negative;
        numerator = numerator.getValue();
    }
    if (denominator.isNegative()) {
        negative = !negative;
        denominator = denominator.getValue();
    }
}

Fraction::Fraction(Integer numerator, Integer denominator) : numerator(numerator), 
        denominator(denominator) { validateFraction(); }

Integer Fraction::getNumerator(void) const { return this->numerator; }

Integer Fraction::getDenominator(void) const { return this->denominator; }

bool Fraction::isNegative(void) const { return negative; }

bool Fraction::operator==(const Fraction& other) const {
    return isNegative() == other.isNegative()
        && getNumerator().getValue() == other.getNumerator().getValue()
        && getDenominator().getValue() == other.getDenominator().getValue();
}

bool Fraction::operator!=(const Fraction& other) const { return !(*this == other); }
