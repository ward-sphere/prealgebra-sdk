#ifndef sdk_prealgebra_DefaultDecimalTranslator
#define sdk_prealgebra_DefaultDecimalTranslator

#include <Translator.hpp>

namespace sdkmath {

    namespace prealgebra {

        class DefaultDecimalTranslator : IDecimalTranslator {

        public:

            long pow10(int x) {
                if (x == 0) return 1;
                return 10 * pow10(x - 1);
            }

            Integer toInteger(const Decimal& d) {
                std::vector<std::pair<int, long>> map = d.toPlaceValueVector();
                std::sort(map.begin(), map.end());

                if (map.size() > 0 && map[0].first < 0) 
                    throw std::invalid_argument("Cannot convert decimal with fractional component to integer");
                
                long res = 0;
                for (auto pair : map) res += pow10(pair.first) * pair.second;
                return Integer(res);
        }

            Fraction toFraction(const Decimal& d) {
                std::vector<std::pair<int, long>> map = d.toPlaceValueVector();

                long whole = 0;
                Fraction f(0, 1);

                for (auto pair : map) {
                    int place = pair.first;
                    long value = pair.second;
                    if (place >= 0) {
                        whole += value * pow10(place);
                    } else {
                        f += Fraction(value, pow10(-place));
                    }
                }

                return Fraction(whole, 1) + f;
            }

        };

    };

};

#endif