#ifndef sdkmath_prealgebra_MixedNumber
#define sdkmath_prealgebra_MixedNumber

#include <include/Integer.hpp>
#include <include/Fraction.hpp>

namespace sdkmath {

    namespace prealgebra {

        class MixedNumber {

            Integer base;

            Fraction fraction;

        public:

            MixedNumber(Integer base, Fraction fraction);

            MixedNumber(MixedNumber& copy);

            Integer getBase(void);

            Fraction getFraction(void);

        };

    };

};

#endif