#ifndef sdkmath_prealgebra_factory_NumberArithmeticFactory
#define sdkmath_prealgebra_factory_NumberArithmeticFactory

#include <Number.hpp>
#include <concrete/FractionNumberArithmetic.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class NumberArithmeticFactory {

            public:

                INumberArithmetic& createNumberArithmetic() {
                    static concrete::FractionNumberArithmetic number_arithmetic;
                    return number_arithmetic;
                }

            };

        };

    };

};

#endif