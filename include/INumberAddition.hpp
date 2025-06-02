#ifndef sdkmath_prealgebra_IAddition
#define sdkmath_prealgebra_IAddition

#include <Integer.hpp>
#include <Fraction.hpp>
#include <MixedNumber.hpp>

namespace sdkmath {

    namespace prealgebra {

        class INumberAddition {

        public:

            virtual Integer add(Integer lhs, Integer rhs) = 0;

            virtual Integer subtract(Integer lhs, Integer rhs) = 0;

            virtual Fraction add(Fraction lhs, Fraction rhs) = 0;

            virtual Fraction subtract(Fraction lhs, Fraction rhs) = 0;

            virtual MixedNumber add(MixedNumber lhs, MixedNumber rhs) = 0;

            virtual MixedNumber subtract(MixedNumber lhs, MixedNumber rhs) = 0;

        };

    };

};

#endif