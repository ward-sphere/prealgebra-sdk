#ifndef sdkmath_prealgebra_factory_ITranslatorFactory
#define sdkmath_prealgebra_factory_ITranslatorFactory

#include <Translator.hpp>
#include <concrete/DefaultIntegerTranslator.hpp>
#include <concrete/DefaultFractionTranslator.hpp>
#include <concrete/DefaultDecimalTranslator.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class ITranslatoryFactory {

            public:

                std::unique_ptr<IIntegerTranslator> createIntegerTranslator()
                    { return std::make_unique<DefaultIntegerTranslator>(); }

                std::unique_ptr<IFractionTranslator> createFractionTranslator()
                    { return std::make_unique<DefaultFractionTranslator>(); }

                std::unique_ptr<IDecimalTranslator> createDecimalTranslator()
                    { return std::make_unique<DefaultDecimalTranslator>(); }

            };

        };

    };

};

#endif