#include <INumberSimplifier.hpp>

namespace sdkmath {

    namespace prealgebra {

        class BasicNumberSimplifier : public INumberSimplifier {

        public:

            std::vector<Integer> getPrimeFactors(Integer i);

            Fraction simplifyFraction(Fraction f);

        };

    };

};
