#ifndef sdkmath_prealgebra_concrete_DefaultFractionArithmetic
#define sdkmath_prealgebra_concrete_DefaultFractionArithmetic

#include <Fraction.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            class DefaultFractionArithmetic : public IFractionArithmetic {

                IFractionSimplification& simplification;

            public:

                DefaultFractionArithmetic(IFractionSimplification& simplification) 
                : simplification(simplification) {}

                Fraction add(const Fraction& lhs, const Fraction& rhs) {
                    Fraction tmpL(lhs), tmpR(rhs);
                    simplification.lcd(tmpL, tmpR);
                    return simplification.simplify(Fraction(
                        tmpL.getNumerator() + tmpR.getNumerator(),
                        tmpL.getDenominator()
                    ));
                }

                Fraction subtract(const Fraction& lhs, const Fraction& rhs) {
                    Fraction tmpL(lhs), tmpR(rhs);
                    simplification.lcd(tmpL, tmpR);
                    return simplification.simplify(Fraction(
                        tmpL.getNumerator() - tmpR.getNumerator(),
                        tmpL.getDenominator()
                    ));
                }

                Fraction multiply(const Fraction& lhs, const Fraction& rhs) {
                    return simplification.simplify(Fraction(
                        lhs.getNumerator() * rhs.getNumerator(),
                        lhs.getDenominator() * rhs.getDenominator()
                    ));
                }

                Fraction divide(const Fraction& lhs, const Fraction& rhs) {
                    if (rhs.getNumerator() == 0) throw std::invalid_argument("Cannot divide by 0");

                    return simplification.simplify(Fraction(
                        lhs.getNumerator() * rhs.getDenominator(),
                        lhs.getDenominator() * rhs.getNumerator()
                    ));
                }

            };

        };

    };

};

#endif