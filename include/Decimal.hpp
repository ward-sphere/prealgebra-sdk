#ifndef sdkmath_prealgebra_Decimal
#define sdkmath_prealgebra_Decimal

#include <memory> 
#include <stdexcept>
#include <vector>
#include <algorithm>

namespace sdkmath {

    namespace prealgebra {

        class Decimal;
        class IDecimalArithmetic;
        class IDecimalRepresentation;

        /// @brief allow for different storage strategies of decimal while ensuring
        /// key features are still available
        class IDecimalRepresentation {

        public:

            /// @brief create representation from string
            virtual void fromString(std::string) = 0;

            /// @brief turn decimal back into string
            virtual std::string toString(void) = 0;

            /// @brief get the value of decimal at a specific number place
            virtual long operator[](int) = 0;

            /// @brief return a vector of place-value pairs
            virtual std::vector<std::pair<int, long>> toPlaceValueVector(void) = 0;

            /// @brief create a representation from vector of place-value pairs
            virtual void fromPlaceValueVector(std::vector<std::pair<int, long>>) = 0;

        };

        /// @brief basic decimal arithmetic
        class IDecimalArithmetic {

        public:

            /// @brief add two decimals
            virtual Decimal add(const Decimal&, const Decimal&) = 0;

            /// @brief subtract two decimals
            virtual Decimal subtract(const Decimal&, const Decimal&) = 0;

            /// @brief multiply two decimals
            virtual Decimal multiply(const Decimal&, const Decimal&) = 0;

            /// @brief divide two decimals
            virtual Decimal divide(const Decimal&, const Decimal&) = 0;

        };

        class Decimal {

        protected:

            /// @brief object-scoped representation object
            std::unique_ptr<IDecimalRepresentation> decimal;

            /// @brief class-scoped arithmetic object
            static std::unique_ptr<IDecimalArithmetic> arithmetic;

        public:

            /// @brief copy constructor
            Decimal(const Decimal& other);

            /// @brief create a decimal from a string
            Decimal(std::string);

            /// @brief get decimal as string
            std::string toString() { return decimal->toString(); }

            /// @brief get the value at a specific number place
            long operator[](int place) { return decimal->operator[](place); }

            /// START OPERATORS ACCESS TO STATIC CLASSES

            friend bool operator==(const Decimal&, const Decimal&);

            friend bool operator<(const Decimal&, const Decimal&);

            friend Decimal operator+(const Decimal&, const Decimal&);

            friend Decimal operator-(const Decimal&, const Decimal&);

            friend Decimal operator*(const Decimal&, const Decimal&);

            friend Decimal operator/(const Decimal&, const Decimal&);

            /// END OPERATORS ACCESS TO STATIC CLASSES

            Decimal& operator=(const Decimal& other) {
                if (this == &other) return *this;

                decimal->fromPlaceValueVector(other.decimal->toPlaceValueVector());

                return *this;
            }

        };

        /// START OPERATORS

        inline bool operator==(const Decimal& lhs, const Decimal& rhs) {
            auto lhsMap = lhs.decimal->toPlaceValueVector(); std::sort(lhsMap.begin(), lhsMap.end());
            auto rhsMap = rhs.decimal->toPlaceValueVector(); std::sort(rhsMap.begin(), rhsMap.end());

            return lhsMap == rhsMap;
        }

        inline bool operator!=(const Decimal& lhs, const Decimal& rhs) { return !(lhs == rhs); }

        inline bool operator< (const Decimal& lhs, const Decimal& rhs) {
            // order maps s.t. largest place comes first
            auto lhsMap = lhs.decimal->toPlaceValueVector(); 
            std::sort(lhsMap.begin(), lhsMap.end()); 
            std::reverse(lhsMap.begin(), lhsMap.end());

            auto rhsMap = rhs.decimal->toPlaceValueVector(); 
            std::sort(rhsMap.begin(), rhsMap.end()); 
            std::reverse(lhsMap.begin(), lhsMap.end());

            // ensure maps have at least on value
            if (lhsMap.size() == 0) lhsMap.push_back({0, 0});
            if (rhsMap.size() == 0) rhsMap.push_back({0, 0});

            // iterate through list until inequality found
            auto lIt = lhsMap.begin();
            auto lEnd = lhsMap.end();
            auto rIt = rhsMap.begin();
            auto rEnd = rhsMap.end();

            while (lIt != lEnd || rIt != rEnd) {
                if (lIt == lEnd) {
                    return 0 < (*rIt).second;
                } else if (rIt == rEnd) {
                    return (*lIt).second < 0;
                } else if ( (*lIt).first != (*rIt).first ) {
                    return (*lIt).first < (*rIt).first;
                } else {
                    long tmpL = (*lIt).second;
                    long tmpR = (*rIt).second;
                    if (tmpL != tmpR) return tmpL < tmpR;
                    ++lIt;
                    ++rIt;
                }
            }

            return false;
        }

        inline bool operator> (const Decimal& lhs, const Decimal& rhs) { return rhs < lhs; }

        inline bool operator<=(const Decimal& lhs, const Decimal& rhs) { return !(lhs > rhs); }

        inline bool operator>=(const Decimal& lhs, const Decimal& rhs) { return !(lhs < rhs); }

        inline Decimal operator+ (const Decimal& lhs, const Decimal& rhs) { return Decimal::arithmetic->add(lhs, rhs); }

        inline void operator+=(Decimal& lhs, const Decimal& rhs) { lhs = lhs + rhs; }

        inline Decimal operator- (const Decimal& lhs, const Decimal& rhs) { return Decimal::arithmetic->subtract(lhs, rhs); }

        inline void operator-=(Decimal& lhs, const Decimal& rhs) { lhs = lhs - rhs; }

        inline Decimal operator* (const Decimal& lhs, const Decimal& rhs) { return Decimal::arithmetic->multiply(lhs, rhs); }

        inline void operator*=(Decimal& lhs, const Decimal& rhs) { lhs = lhs * rhs; }

        inline Decimal operator/ (const Decimal& lhs, const Decimal& rhs) { return Decimal::arithmetic->divide(lhs, rhs); }

        inline void operator/=(Decimal& lhs, const Decimal& rhs) { lhs = lhs / rhs; }

        /// END OPERATORS

    };

};

#endif