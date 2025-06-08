#ifndef sdkmath_prealgebra_factory_NumberArithmeticFactory
#define sdkmath_prealgebra_factory_NumberArithmeticFactory

#include <Number.hpp>
#include <concrete/FractionNumberArithmetic.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class NumberArithmeticFactory {

            public:

                std::unique_ptr<INumberArithmetic> createNumberArithmetic() 
                    { return std::make_unique<concrete::FractionNumberArithmetic>(); }

            };

        };

    };

};

#endif