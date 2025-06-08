#ifndef sdkmath_prealgebra_LongDivisionFractionToDecimalTranslator
#define sdkmath_prealgebra_LongDivisionFractionToDecimalTranslator

#include <concrete/DefaultFractionTranslator.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            class LongDivisionFractionToDecimalTranslator : public IFractionToDecimalTranslator {

                size_t max_division_iterations;

            public:

                LongDivisionFractionToDecimalTranslator(size_t precision) {
                    max_division_iterations = precision;
                }

                Decimal toDecimal(const Fraction& f) {
                    std::stringstream ss;

                    long num = f.getNumerator(), den = f.getDenominator();
                    if (num < 0) {
                        ss << '-';
                        num *= -1;
                    }

                    ss << num / den << '.';
                    num %= den;

                    for (size_t iteration = 0; num > 0 && iteration < max_division_iterations; iteration++) {
                        num *= 10;
                        ss << num / den;
                        num %= den;
                    }

                    return Decimal(ss.str());
                }

            };

        };

    };

};

#endif