#ifndef sdkmath_prealgebra_Decimal
#define sdkmath_prealgebra_Decimal

#include <Number.hpp>

#include <map>

namespace sdkmath {

    namespace prealgebra {

        class Decimal;
        class IDecimalStringParser;

        class IDecimalStringParser {

        public:

            virtual void validateDecimal(std::string) = 0;

            virtual std::map<int, long> fromString(std::string) = 0;

        };

        class Decimal : public Number {

            std::map<int, long> decimal;

        public:

            /// @brief copy constructor
            Decimal(const Decimal& other);

            /// @brief create a decimal from a string
            Decimal(std::string);

            /// @brief create a decimal from a place-value map
            Decimal(std::map<int, long>);

            /// @brief get decimal as string
            std::string toString() const;
            
            Decimal& operator=(const Decimal& other) {
                if (this != &other) decimal = other.decimal;
                return *this;
            }

            std::pair<long, long> toFractionalValues() const;

            std::map<int, long> getPlaceValueMap() const { return decimal; }

        };

    };

};

#endif