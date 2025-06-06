#ifndef sdkmath_prealgebra_concrete_BasicFractionArithmetic
#define sdkmath_prealgebra_concrete_BasicFractionArithmetic

#include <Fraction.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            class BasicFractionArithmetic : public IFractionArithmetic {

            public:

                Fraction add(const Fraction& lhs, const Fraction& rhs) { return lhs; }

                Fraction subtract(const Fraction& lhs, const Fraction& rhs) { return lhs; }

                Fraction multiply(const Fraction& lhs, const Fraction& rhs) { return lhs; }

                Fraction divide(const Fraction& lhs, const Fraction& rhs) { return lhs; }

            };

        };

    };

};

#endif