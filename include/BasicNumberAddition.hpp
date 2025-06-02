#ifndef sdkmath_prealgebra_BasicAddition
#define sdkmath_prealgebra_BasicAddition

#include <Integer.hpp>
#include <Fraction.hpp>
#include <MixedNumber.hpp>

#include <INumberAddition.hpp>
#include <INumberTranslator.hpp>

namespace sdkmath {

    namespace prealgebra {

        class BasicNumberAddition : public INumberAddition {

            INumberTranslator& translator;

        public:

            BasicNumberAddition(INumberTranslator& translator);

            Integer add(Integer lhs, Integer rhs);

            Integer subtract(Integer lhs, Integer rhs);

            Fraction add(Fraction lhs, Fraction rhs);

            Fraction subtract(Fraction lhs, Fraction rhs);

            MixedNumber add(MixedNumber lhs, MixedNumber rhs);

            MixedNumber subtract(MixedNumber lhs, MixedNumber rhs);

        };

    };

};

#endif