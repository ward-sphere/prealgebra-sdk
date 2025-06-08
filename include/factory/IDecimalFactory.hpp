#ifndef sdkmath_prealgebra_factory_IDecimalFactory
#define sdkmath_prealgebra_factory_IDecimalFactory

#include <Decimal.hpp>
#include <concrete/RegexDecimalStringParser.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IDecimalFactory {

            public:

                std::unique_ptr<IDecimalStringParser> createDecimalStringParser() {
                    return std::make_unique<concrete::RegexDecimalStringParser>();
                }

            };

        };

    };

};

#endif