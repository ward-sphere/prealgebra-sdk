#ifndef sdkmath_prealgebra_Fraction
#define sdkmath_prealgebra_Fraction

#include <Integer.hpp>

namespace sdkmath {

    namespace prealgebra {

        class Fraction {

            Integer numerator, denominator;

            void validateDenominator(void);

        public:

            Fraction(Integer numerator, Integer denominator);

            Fraction(long numerator, long denominator);

            Integer getNumerator(void) const;

            Integer getDenominator(void) const;

            bool operator==(const Fraction& other) const;

            bool operator!=(const Fraction& other) const;

        };

    };

};

#endif