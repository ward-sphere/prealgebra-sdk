#ifndef sdkmath_prealgebra_Translator
#define sdkmath_prealgebra_Translator

#include <Integer.hpp>
#include <Fraction.hpp>
#include <Decimal.hpp>

#include <memory>

namespace sdkmath {

    namespace prealgebra {

        class Translator;
        class IIntegerTranslator;
        class IFractionTranslator;
        class IDecimalTranslator;

        class IIntegerTranslator {

        public:

            virtual Fraction toFraction(const Integer&) = 0;

            virtual Decimal toDecimal(const Integer&) = 0;

        };

        class IFractionTranslator {

        public:

            virtual Integer toInteger(const Fraction&) = 0;

            virtual Decimal toDecimal(const Fraction&) = 0;

        };

        class IDecimalTranslator {

        public:

            virtual Integer toInteger(const Decimal&) = 0;

            virtual Fraction toFraction(const Decimal&) = 0;

        };

        class Translator {

            static std::unique_ptr<IIntegerTranslator> integer_translator;

            static std::unique_ptr<IFractionTranslator> fraction_translator;

            static std::unique_ptr<IDecimalTranslator> decimal_translator;

        public:

            static Integer ftoi(const Fraction& f) { return fraction_translator->toInteger(f); }

            static Integer dtoi(const Decimal& d) { return decimal_translator->toInteger(d); }

            static Fraction itof(const Integer& i) { return integer_translator->toFraction(i); }

            static Fraction dtof(const Decimal& d) { return decimal_translator->toFraction(d); }

            static Decimal itod(const Integer& i) { return integer_translator->toDecimal(i); }

            static Decimal ftod(const Fraction& f) { return fraction_translator->toDecimal(f); }

        };

    };

};

#endif