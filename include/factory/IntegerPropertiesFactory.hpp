#ifndef sdkmath_prealgebra_factory_IntegerPropertiesFactory
#define sdkmath_prealgebra_factory_IntegerPropertiesFactory

#include <concrete/PrimeFactorIntegerProperties.hpp>
#include <utility/IIntegerProperties.hpp>

#include <memory>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IntegerPropertiesFactory {

            public:

                std::unique_ptr<utility::IIntegerProperties> createIntegerProperties() {
                    return std::make_unique<concrete::PrimeFactorIntegerProperties>();
                }

            };

        };

    };

};

#endif