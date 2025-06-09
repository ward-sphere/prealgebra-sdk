#ifndef sdkmath_prealgebra_IFractionFactory
#define sdkmath_prealgebra_IFractionFactory

#include <Fraction.hpp>
#include <concrete/DefaultFractionSimplification.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IFractionFactory {

            public:

                IFractionSimplification& createFractionSimplification() { 
                    static concrete::DefaultFractionSimplification fraction_simplification;
                    return fraction_simplification;
                }

            };

        };

    };

};

#endif