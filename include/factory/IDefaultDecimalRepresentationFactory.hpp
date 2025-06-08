#ifndef sdkmath_prealgebra_factory_IDefaultDecimalRepresentationFactory
#define sdkmath_prealgebra_factory_IDefaultDecimalRepresentationFactory

#include <concrete/DefaultDecimalRepresentation.hpp>
#include <concrete/RegexDecimalStringParser.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IDefaultDecimalRepresentationFactory {

            public:

                std::unique_ptr<concrete::IDecimalStringParser> createDecimalStringParser()
                    { return std::make_unique<concrete::RegexDecimalStringParser>(); }

            };

        };

    };

};

#endif