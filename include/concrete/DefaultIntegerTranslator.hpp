#ifndef sdkmath_prealgebra_DefaultIntegerTranslator
#define sdkmath_prealgebra_DefaultIntegerTranslator

#include <Translator.hpp>

#include <sstream>

namespace sdkmath {

    namespace prealgebra {

        class DefaultIntegerTranslator : public IIntegerTranslator {

        public:

            Fraction toFraction(const Integer& i) { return Fraction(i.getValue(), 1); }

            Decimal toDecimal(const Integer& i) {
                std::stringstream ss;
                ss << i.getValue();
                return Decimal(ss.str());
            }



        };

    };

};

#endif