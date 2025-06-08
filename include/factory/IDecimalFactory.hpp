#ifndef sdkmath_prealgebra_factory_IDecimalFactory
#define sdkmath_prealgebra_factory_IDecimalFactory

#include <Decimal.hpp>
#include <concrete/DefaultDecimalRepresentation.hpp>
#include <concrete/FractionDecimalArithmetic.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IDecimalFactory {

            public:

                std::unique_ptr<IDecimalRepresentation> createDecimalRepresentation() {
                    return std::make_unique<concrete::DefaultDecimalRepresentation>();
                }

                std::unique_ptr<IDecimalArithmetic> createDecimalArithmetic() {
                    return std::make_unique<concrete::FractionDecimalArithmetic>();
                }

            };

        };

    };

};

#endif