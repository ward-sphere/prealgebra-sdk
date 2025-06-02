#ifndef sdkmath_prealgebra_INumberTranslator
#define sdkmath_prealgebra_INumberTranslator

#include <include/Integer.hpp>
#include <include/Fraction.hpp>
#include <include/MixedNumber.hpp>

namespace sdkmath {

    namespace prealgebra {

        class INumberTranslator {

        public:

            virtual Fraction toFraction(Integer) = 0;

            virtual Integer toInteger(Fraction) = 0;
            
            virtual MixedNumber getMixedNumber(Fraction) = 0;
            
            virtual Fraction getFraction(MixedNumber) = 0;

        };

    };

};

#endif