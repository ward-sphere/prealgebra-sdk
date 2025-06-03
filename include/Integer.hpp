#ifndef sdkmath_prealgebra_Integer
#define sdkmath_prealgebra_Integer

namespace sdkmath {

    namespace prealgebra {

        class Integer;
        class IIntegerArithmetic;

        /// @brief proof of concept class for interface segregation
        class Integer {

            /// @brief actual value of integer
            long value;

        protected:

            /// @brief get handler for generic arithmetic (add, multiply, etc); 
            /// could include any complex functionality that this not tied to an object
            static IIntegerArithmetic& arithmetic();

        public:

            /// @brief set integer value
            Integer(long) { this->value = value; }

            /// @brief retrieve integer value
            long getValue(void) const { return value; }

            /// @brief allow operator to access protected variables
            friend Integer operator+(const Integer&lhs, const Integer&rhs);

            /// @brief allow operator to access protected variables
            friend Integer operator-(const Integer&lhs, const Integer&rhs);

            /// @brief allow operator to access protected variables
            friend Integer operator*(const Integer&lhs, const Integer&rhs);

            /// @brief allow operator to access protected variables
            friend Integer operator/(const Integer&lhs, const Integer&rhs);

        };

        /// @brief interface of interface-segregatable functionality that is defined in
        /// the same compilation unit as the class it's using
        class IIntegerArithmetic {

        public:

            /// @brief add two integers 
            virtual Integer add(const Integer& lhs, const Integer& rhs) = 0;

            /// @brief subtract two integers
            virtual Integer subtract(const Integer& lhs, const Integer& rhs) = 0;

            /// @brief multiply two integers
            virtual Integer multiply(const Integer& lhs, const Integer& rhs) = 0;

            /// @brief divide two integers
            virtual Integer divide(const Integer& lhs, const Integer& rhs) = 0;

        };

        /// following in this class is just a collection of operators, each making one-
        /// liner calls to the Integer or IIntegerArithmetic classes; all implementations
        /// should be able to look like this using good enough interface segregation

        /// setting up like this allows for independent components to be independently 
        /// testable, while the larger test for integers focuses strictly on integration

        /// START OPERATORS

        inline bool operator==(const Integer& lhs, const Integer& rhs) { return lhs.getValue() == rhs.getValue(); }

        inline bool operator!=(const Integer& lhs, const Integer& rhs) { return !(lhs == rhs); }

        inline bool operator< (const Integer& lhs, const Integer& rhs) { return lhs.getValue() < rhs.getValue(); }

        inline bool operator> (const Integer& lhs, const Integer& rhs) { return rhs < lhs; }

        inline bool operator<=(const Integer& lhs, const Integer& rhs) { return !(lhs > rhs); }

        inline bool operator>=(const Integer& lhs, const Integer& rhs) { return !(lhs < rhs); }

        inline Integer operator+(const Integer& lhs, const Integer& rhs) { return Integer::arithmetic().add(lhs, rhs); }

        inline void operator+=(Integer& lhs, const Integer& rhs) { lhs = lhs + rhs; }

        inline Integer operator-(const Integer& lhs, const Integer& rhs) { return Integer::arithmetic().subtract(lhs, rhs); }

        inline void operator-=(Integer& lhs, const Integer& rhs) { lhs = lhs - rhs; }

        inline Integer operator*(const Integer& lhs, const Integer& rhs) { return Integer::arithmetic().multiply(lhs, rhs); }

        inline void operator*=(Integer& lhs, const Integer& rhs) { lhs = lhs * rhs; }

        inline Integer operator/(const Integer& lhs, const Integer& rhs) { return Integer::arithmetic().divide(lhs, rhs); }

        inline void operator/=(Integer& lhs, const Integer& rhs) { lhs = lhs - rhs; }

        /// END OPERATORS

    };

};

#endif