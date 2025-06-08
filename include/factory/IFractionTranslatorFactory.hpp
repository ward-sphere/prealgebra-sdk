#ifndef sdk_prealgebra_factory_IFractionTranslatorFactory
#define sdk_prealgebra_factory_IFractionTranslatorFactory

#include <concrete/LongDivisionFractionToDecimalTranslator.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IFractionTranslatorFactory {

            public:

                std::unique_ptr<IFractionToDecimalTranslator> createFractionToDecimalTranslator()
                    { return std::make_unique<concrete::LongDivisionFractionToDecimalTranslator>(7); }

            };

        };

    };

};

#endif