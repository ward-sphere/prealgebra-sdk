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

                utility::IIntegerProperties& createIntegerProperties() {
                    static concrete::PrimeFactorIntegerProperties integer_properties;
                    return integer_properties;
                }

            };

        };

    };

};

#endif