#ifndef sdkmath_prealgebra_IFractionFactory
#define sdkmath_prealgebra_IFractionFactory

#include <Fraction.hpp>
#include <concrete/PrimeFractionSimplification.hpp>
#include <concrete/BasicFractionArithmetic.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IFractionFactory {

            public:

                std::unique_ptr<IFractionArithmetic> createFractionArithmetic() 
                        { return std::make_unique<concrete::BasicFractionArithmetic>(*std::make_unique<concrete::PrimeFractionSimplification>()); }

                std::unique_ptr<IFractionSimplification> createFractionSimplification() { return std::make_unique<concrete::PrimeFractionSimplification>(); }

            };

        };

    };

};

#endif