#ifndef sdkmath_prealgebra_DefaultFractionTranslator
#define sdkmath_prealgebra_DefaultFractionTranslator

#include <Translator.hpp>

#include <sstream>

namespace sdkmath {

    namespace prealgebra {

        class IFractionToDecimalTranslator {

        public:

            virtual Decimal toDecimal(const Fraction&) = 0;

        };

        class DefaultFractionTranslator : public IFractionTranslator {

            std::unique_ptr<IFractionToDecimalTranslator> ftod;

        public:

            DefaultFractionTranslator();

            Integer toInteger(const Fraction& f) {
                if (f.getNumerator() % f.getDenominator() == 0) return f.getNumerator() / f.getDenominator();
                throw std::invalid_argument("Cannot convert indivisble fraction to integer");
            }

            Decimal toDecimal(const Fraction& f) { return ftod->toDecimal(f); }

        };

    };

};

#endif