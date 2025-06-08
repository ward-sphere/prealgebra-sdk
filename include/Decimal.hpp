#ifndef sdkmath_prealgebra_Decimal
#define sdkmath_prealgebra_Decimal

#include <memory> 
#include <stdexcept>
#include <vector>
#include <map>
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

            virtual long compare(const Decimal&, const Decimal&) = 0;

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

            /// @brief create a decimal from a place-value map
            Decimal(std::map<int, long>);

            /// @brief get decimal as string
            std::string toString() const { return decimal->toString(); }

            /// @brief get decimal as place-value vector
            std::vector<std::pair<int, long>> toPlaceValueVector() const { return decimal->toPlaceValueVector(); }

            /// @brief get the value at a specific number place
            long operator[](int place) const { return decimal->operator[](place); }

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

        inline bool operator==(const Decimal& lhs, const Decimal& rhs) { return Decimal::arithmetic->compare(lhs, rhs) == 0; }

        inline bool operator!=(const Decimal& lhs, const Decimal& rhs) { return !(lhs == rhs); }

        inline bool operator< (const Decimal& lhs, const Decimal& rhs) { return Decimal::arithmetic->compare(lhs, rhs) < 0; }

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