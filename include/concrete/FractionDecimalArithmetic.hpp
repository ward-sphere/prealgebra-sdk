#ifndef sdkmath_prealgebra_concrete_FractionDecimalArithmetic
#define sdkmath_prealgebra_concrete_FractionDecimalArithmetic

#include <concrete/DefaultDecimalRepresentation.hpp>
#include <Translator.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            class FractionDecimalArithmetic : public IDecimalArithmetic {

                Translator t;

            public:

                long compare(const Decimal& lhs, const Decimal& rhs) {
                    return (t.dtof(lhs) - t.dtof(rhs)).getNumerator();
                }

                Decimal add(const Decimal& lhs, const Decimal& rhs) { return t.ftod(t.dtof(lhs) + t.dtof(rhs)); }

                Decimal subtract(const Decimal& lhs, const Decimal& rhs) { return t.ftod(t.dtof(lhs) - t.dtof(rhs)); }

                Decimal multiply(const Decimal& lhs, const Decimal& rhs) { return t.ftod(t.dtof(lhs) * t.dtof(rhs)); }

                Decimal divide(const Decimal& lhs, const Decimal& rhs) { return t.ftod(t.dtof(lhs) / t.dtof(rhs)); }

            };

        };

    };

};

#endif