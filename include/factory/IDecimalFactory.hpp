#ifndef sdkmath_prealgebra_factory_IDecimalFactory
#define sdkmath_prealgebra_factory_IDecimalFactory

#include <Decimal.hpp>
#include <concrete/RegexDecimalStringParser.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IDecimalFactory {

            public:

                IDecimalStringParser& createDecimalStringParser() {
                    static concrete::RegexDecimalStringParser string_parser;
                    return string_parser;
                }

            };

        };

    };

};

#endif