#ifndef sdkmath_prealgebra_Fraction
#define sdkmath_prealgebra_Fraction

#include <Integer.hpp>

namespace sdkmath {

    namespace prealgebra {

        class Fraction {

            Integer numerator, denominator;

            bool negative = false;

            void validateFraction(void);

            void validateDenominator(void);

            void validateNegatives(void);

        public:

            Fraction(Integer numerator, Integer denominator);

            Integer getNumerator(void) const;

            Integer getDenominator(void) const;

            bool isNegative(void) const;

            bool operator==(const Fraction& other) const;

            bool operator!=(const Fraction& other) const;

        };

    };

};

#endif