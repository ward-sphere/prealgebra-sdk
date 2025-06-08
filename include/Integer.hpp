#ifndef sdkmath_prealgebra_Integer
#define sdkmath_prealgebra_Integer

#include <Number.hpp>

namespace sdkmath {

    namespace prealgebra {

        class Integer;
        /// @brief proof of concept class for interface segregation
        class Integer : public Number {

            /// @brief actual value of integer
            long value;

        public:

            /// @brief set integer value
            Integer(long value) { this->value = value; }

            /// @brief retrieve integer value
            long getValue(void) const { return value; }

            std::string toString() const { return std::to_string(value); }

            std::map<int, long> getPlaceValueMap() const {
                std::map<int, long> res;
                
                // set up values for iteration
                long tmp = value;
                bool negative = false;
                if (tmp < 0) {
                    tmp *= -1;
                    negative = true;
                }

                for (int i = 0; tmp > 0; i++) {
                    res[i] = (tmp % 10) * (negative ? -1 : 1);
                    tmp /= 10;
                }

                return res;
            }

            std::pair<long, long> toFractionalValues() const { return {value, 1}; }

        };

    };

};

#endif