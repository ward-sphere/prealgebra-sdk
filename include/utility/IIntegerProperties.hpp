#ifndef sdkmath_prealgebra_utility_IIntegerProperties
#define sdkmath_prealgebra_utility_IIntegerProperties

namespace sdkmath {

    namespace prealgebra {

        namespace utility {

            class IIntegerProperties {

            public:

                virtual long lcm(long, long) = 0;

                virtual long gcd(long, long) = 0;

            };

        };

    };

};

#endif