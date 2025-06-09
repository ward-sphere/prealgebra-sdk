#ifndef sdkmath_prealgebra_Number
#define sdkmath_prealgebra_Number

#include <iostream>
#include <utility>
#include <memory>
#include <string>

namespace sdkmath {

    namespace prealgebra {

        class Number;
        class INumberArithmetic;
        
        class INumberArithmetic {

        public:

            virtual long compare(const Number& lhs, const Number& rhs) = 0;

            virtual std::unique_ptr<Number> add(const Number& lhs, const Number& rhs) = 0;

            virtual std::unique_ptr<Number> subtract(const Number& lhs, const Number& rhs) = 0;

            virtual std::unique_ptr<Number> multiply(const Number& lhs, const Number& rhs) = 0;

            virtual std::unique_ptr<Number> divide(const Number& lhs, const Number& rhs) = 0;

        };

        class Number {

            static INumberArithmetic& arithmetic;

        public:

            virtual std::string toString() const = 0;

            virtual std::pair<long, long> toFractionalValues() const = 0;

            friend bool operator==(const Number&, const Number&);

            friend bool operator<(const Number&, const Number&);

            friend std::unique_ptr<Number> operator+(const Number&, const Number&);

            friend std::unique_ptr<Number> operator-(const Number&, const Number&);

            friend std::unique_ptr<Number> operator*(const Number&, const Number&);

            friend std::unique_ptr<Number> operator/(const Number&, const Number&);

        };

        inline bool operator==(const Number& lhs, const Number& rhs) { return Number::arithmetic.compare(lhs, rhs) == 0; }

        inline bool operator!=(const Number& lhs, const Number& rhs) { return !(lhs == rhs); }

        inline bool operator<(const Number& lhs, const Number& rhs) { return Number::arithmetic.compare(lhs, rhs) < 0; }

        inline bool operator>(const Number& lhs, const Number& rhs) { return rhs < lhs; }

        inline bool operator<=(const Number& lhs, const Number& rhs) { return !(lhs > rhs); }

        inline bool operator>=(const Number& lhs, const Number& rhs) { return !(lhs < rhs); }

        inline std::unique_ptr<Number> operator+(const Number& lhs, const Number& rhs) { return Number::arithmetic.add(lhs, rhs); }

        inline std::unique_ptr<Number> operator-(const Number& lhs, const Number& rhs) { return Number::arithmetic.subtract(lhs, rhs); }

        inline std::unique_ptr<Number> operator*(const Number& lhs, const Number& rhs) { return Number::arithmetic.multiply(lhs, rhs); }

        inline std::unique_ptr<Number> operator/(const Number& lhs, const Number& rhs) { return Number::arithmetic.divide(lhs, rhs); }

        inline std::ostream& operator<<(std::ostream& os, const Number& number) {
            os << number.toString();
            return os;
        }

    };

};

#endif