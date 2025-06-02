#ifndef sdkmath_prealgebra_INumberSimplifier
#define sdkmath_prealgebra_INumberSimplifier

#include <include/Integer.hpp>
#include <include/Fraction.hpp>
#include <include/MixedNumber.hpp>

#include <vector>

namespace sdkmath {

    namespace prealgebra {

        class INumberSimplifier {

        public:

            virtual std::vector<Integer> getPrimeFactors(Integer) = 0;

            virtual Fraction simplifyFraction(Fraction) = 0;

        };

    };

};

#endif