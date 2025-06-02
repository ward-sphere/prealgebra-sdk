#include <Fraction.hpp>

#include <stdexcept>

using namespace sdkmath::prealgebra;

void Fraction::validateDenominator(void) {
    if (denominator.getValue() == 0)
        throw std::invalid_argument("Denominator must be non-zero");
}

Fraction::Fraction(Integer numerator, Integer denominator) : numerator(numerator), 
        denominator(denominator) { validateDenominator(); }

Fraction::Fraction(long numerator, long denominator) : numerator(numerator),
        denominator(denominator) { validateDenominator(); }

Integer Fraction::getNumerator(void) const { return this->numerator; }

Integer Fraction::getDenominator(void) const { return this->denominator; }

bool Fraction::operator==(const Fraction& other) const {
    return getNumerator().getValue() == other.getNumerator().getValue()
        && getDenominator().getValue() == other.getDenominator().getValue();
}

bool Fraction::operator!=(const Fraction& other) const { return !(*this == other); }
