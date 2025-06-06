#ifndef sdkmath_prealgebra_IFractionFactory
#define sdkmath_prealgebra_IFractionFactory

#include <Fraction.hpp>
#include <concrete/DefaultFractionSimplification.hpp>
#include <concrete/DefaultFractionArithmetic.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IFractionFactory {

            public:

                std::unique_ptr<IFractionArithmetic> createFractionArithmetic() 
                        { return std::make_unique<concrete::DefaultFractionArithmetic>(*std::make_unique<concrete::DefaultFractionSimplification>()); }

                std::unique_ptr<IFractionSimplification> createFractionSimplification() { return std::make_unique<concrete::DefaultFractionSimplification>(); }

            };

        };

    };

};

#endif