#ifndef sdkmath_prealgebra_IIntegerFactory
#define sdkmath_prealgebra_IIntegerFactory

#include <Integer.hpp>
#include <concrete/DefaultIntegerArithmetic.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace factory {

            class IIntegerFactory {

            public:

                std::unique_ptr<IIntegerArithmetic> createIntegerArithmetic() { 
                    return std::make_unique<concrete::DefaultIntegerArithmetic>(); 
                }

            };

        };



    };

};

#endif