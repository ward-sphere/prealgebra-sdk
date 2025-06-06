#ifndef sdkmath_prealgebra_concrete_BasicFractionSimplification
#define sdkmath_prealgebra_concrete_BasicFractionSimplification

#include <Fraction.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            class BasicFractionSimplification : public IFractionSimplification {

            public:

                Fraction simplify(const Fraction& fraction) { return fraction; }

                void lcd(Fraction&, Fraction&) {}

            };

        };

    };

};

#endif