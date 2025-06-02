#ifndef sdkmath_prealgebra_MixedNumber
#define sdkmath_prealgebra_MixedNumber

#include <Integer.hpp>
#include <Fraction.hpp>

namespace sdkmath {

    namespace prealgebra {

        class MixedNumber {

            Integer base;

            Fraction fraction;

            void checkProperFraction(void);

        public:

            MixedNumber(Integer base, Fraction fraction);

            MixedNumber(long base, long numerator, long denominator);

            Integer getBase(void) const;

            Fraction getFraction(void) const;

        };

    };

};

#endif