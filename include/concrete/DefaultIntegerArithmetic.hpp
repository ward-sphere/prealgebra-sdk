#ifndef sdkmath_prealgebra_DefaultIntegerArithmetic
#define sdkmath_prealgebra_DefaultIntegerArithmetic

#include <Integer.hpp>

#include <stdexcept>

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            /// @brief implementing class that just does basics on longs and throws
            /// an exception for divide by 0. keeping this header-only allows for 
            /// us to make less changes to the CMakeLists when changing things out.
            /// if this had a test file, it would be used for helper functions; goal 
            /// is to decompose things as much as possible
            class DefaultIntegerArithmetic : public IIntegerArithmetic {

            public:

                Integer add(const Integer& lhs, const Integer& rhs) { return Integer(lhs.getValue() + rhs.getValue()); }

                Integer subtract(const Integer& lhs, const Integer& rhs) { return Integer(lhs.getValue() - rhs.getValue()); }

                Integer multiply(const Integer& lhs, const Integer& rhs) { return Integer(lhs.getValue() * rhs.getValue()); }

                Integer divide(const Integer& lhs, const Integer& rhs) {
                    if (rhs == 0) throw std::invalid_argument("Divide by 0");

                    return Integer(lhs.getValue() / rhs.getValue());
                }

            };

        };

    };

};

#endif