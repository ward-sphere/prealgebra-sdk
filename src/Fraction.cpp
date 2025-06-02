#include <include/Fraction.hpp>

#include <stdexcept>

using namespace sdkmath::prealgebra;

void Fraction::validateDenominator(void) {
    if (denominator.getValue() == 0)
        throw std::invalid_argument("Denominator must be non-zero");
}

Fraction::Fraction(Integer numerator, Integer denominator) : numerator(numerator), 
        denominator(denominator) { validateDenominator(); }

Fraction::Fraction(Fraction& copy) : numerator(copy.getNumerator()), 
        denominator(copy.getDenominator()) { validateDenominator(); }

Integer Fraction::getNumerator(void) { return this->numerator; }

Integer Fraction::getDenominator(void) { return this->denominator; }
