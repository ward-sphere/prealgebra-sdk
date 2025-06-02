#ifndef sdkmath_prealgebra_BasicNumberTranslator
#define sdkmath_prealgebra_BasicNumberTranslator

#include <INumberTranslator.hpp>

namespace sdkmath {

    namespace prealgebra {

        class BasicNumberTranslator : public INumberTranslator {

        public:

            Fraction toFraction(Integer);

            Integer toInteger(Fraction);
            
            MixedNumber getMixedNumber(Fraction);
            
            Fraction getFraction(MixedNumber);

        };

    };

};

#endif