#ifndef sdkmath_prealgebra_Fraction
#define sdkmath_prealgebra_Fraction

#include <include/Integer.hpp>

namespace sdkmath {

    namespace prealgebra {

        class Fraction {

            Integer numerator, denominator;

            long value;

        public:

            Fraction(Integer numerator, Integer denominator);

            Fraction(Fraction& copy);

            Integer getNumerator(void);

            Integer getDenominator(void);

        };

    };

};

#endif