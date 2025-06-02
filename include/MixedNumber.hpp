#ifndef sdkmath_prealgebra_MixedNumber
#define sdkmath_prealgebra_MixedNumber

#include <Integer.hpp>
#include <Fraction.hpp>

#include <iostream>

namespace sdkmath {

    namespace prealgebra {

        class MixedNumber {

            Integer base;

            Fraction fraction;

            void checkProperFraction(void);

        public:

            MixedNumber(Integer base, Fraction fraction);

            MixedNumber(Integer base, Integer numerator, Integer denominator);

            Integer getBase(void) const;

            Fraction getFraction(void) const;

            bool operator==(const MixedNumber& other) const;

            bool operator!=(const MixedNumber& other) const;

        };

    };

};

#endif