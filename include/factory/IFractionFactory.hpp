#ifndef sdkmath_prealgebra_IFractionFactory
#define sdkmath_prealgebra_IFractionFactory

#include <Fraction.hpp>
#include <concrete/BasicFractionSimplification.hpp>
#include <concrete/BasicFractionArithmetic.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IFractionFactory {

            public:

                std::unique_ptr<IFractionArithmetic> createFractionArithmetic() { return std::make_unique<concrete::BasicFractionArithmetic>(); }

                std::unique_ptr<IFractionSimplification> createFractionSimplification() { return std::make_unique<concrete::BasicFractionSimplification>(); }

            };

        };

    };

};

#endif