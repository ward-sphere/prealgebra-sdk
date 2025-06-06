#ifndef sdkmath_prealgebra_Fraction
#define sdkmath_prealgebra_Fraction

#include <memory> 
#include <stdexcept>

namespace sdkmath {

    namespace prealgebra {

        class Fraction;
        class IFractionArithmetic;
        class IFractionSimplification;

        /// @brief basic fraction arithmetic
        class IFractionArithmetic {

        public:

            /// @brief fraction addition 
            virtual Fraction add(const Fraction&, const Fraction&) = 0;

            /// @brief fraction subtraction
            virtual Fraction subtract(const Fraction&, const Fraction&) = 0;

            /// @brief fraction multiplication
            virtual Fraction multiply(const Fraction&, const Fraction&) = 0;

            /// @brief fraction division
            virtual Fraction divide(const Fraction&, const Fraction&) = 0;

        };

        /// @brief tools for fraction simplification
        class IFractionSimplification {

        public:

            /// @brief returns a simplified version of some fraction
            virtual Fraction simplify(const Fraction&) = 0;

            /// @brief changes two fractions to the form of their gcd
            virtual void lcd(Fraction&, Fraction&) = 0;

        };

        /// @brief unit defining high-level details of fractions
        class Fraction {

            /// @brief fraction numerator
            long numerator = 0;

            /// @brief fraction denominator; non-zero
            long denominator = 1;

        protected:

            /// @brief fraction addition, multiplication, etc
            static std::unique_ptr<IFractionArithmetic> arithmetic;

            /// @brief simplify fractions; change fraction to a base
            static std::unique_ptr<IFractionSimplification> simplification;

        public:

            /// @brief copy constructor 
            Fraction(const Fraction& other) {
                this->numerator = other.getNumerator();
                this->denominator = other.getDenominator();
            }

            /// @brief basic constructor with numerator, denominator
            Fraction(long numerator, long denominator) {
                if (denominator == 0) throw std::invalid_argument("Fraction cannot have denominator 0");
                else if (denominator < 0) {
                    numerator *= -1;
                    denominator *= -1;
                }

                this->numerator = numerator;
                this->denominator = denominator;
            }

            /// @brief numerator-only constructor; denominator will be default of 1
            Fraction(long numerator) { this->numerator = numerator; }

            /// @brief numerator getter
            long getNumerator(void) const { return numerator; }

            /// @brief denominator getter
            long getDenominator(void) const { return denominator; }

            /// @brief call IFractionSimplification instance to get simplified version of this
            Fraction simplified(void) const { return simplification->simplify(*this); }

            /// @brief change this fraction into its simplified version 
            void simplify(void) {
                Fraction tmp(simplified());
                this->numerator = tmp.getNumerator();
                this->denominator = tmp.getDenominator();
            }

            /// START OPERATORS ACCESS TO STATIC ADDITION

            friend bool operator==(const Fraction&, const Fraction&);

            friend bool operator<(const Fraction&, const Fraction&);

            friend Fraction operator+(const Fraction&, const Fraction&);

            friend Fraction operator-(const Fraction&, const Fraction&);

            friend Fraction operator*(const Fraction&, const Fraction&);

            friend Fraction operator/(const Fraction&, const Fraction&);

            /// END OPERATORS ACCESS TO STATIC CLASSES

        };

        /// START OPERATORS

        inline bool operator==(const Fraction& lhs, const Fraction& rhs) {
            Fraction lS(Fraction::simplification->simplify(lhs)), 
            rS(Fraction::simplification->simplify(rhs));

            return lS.getNumerator() == rS.getNumerator()
                    && lS.getDenominator() == rS.getDenominator();
        }

        inline bool operator!=(const Fraction& lhs, const Fraction& rhs) { return !(lhs == rhs); }

        inline bool operator<(const Fraction& lhs, const Fraction& rhs) {
            Fraction tmpL = lhs.simplified(), tmpR = rhs.simplified();
            Fraction::simplification->lcd(tmpL, tmpR);

            return tmpL.getNumerator() < tmpR.getNumerator();
        }

        inline bool operator>(const Fraction& lhs, const Fraction& rhs) { return rhs < lhs; }

        inline bool operator<=(const Fraction& lhs, const Fraction& rhs) { return !(lhs > rhs); }

        inline bool operator>=(const Fraction& lhs, const Fraction& rhs) { return !(lhs < rhs); }

        inline Fraction operator+(const Fraction& lhs, const Fraction& rhs) { return Fraction::arithmetic->add(lhs, rhs); }

        inline void operator+=(Fraction& lhs, const Fraction& rhs) { lhs = lhs + rhs; }

        inline Fraction operator-(const Fraction& lhs, const Fraction& rhs) { return Fraction::arithmetic->subtract(lhs, rhs); }

        inline void operator-=(Fraction& lhs, const Fraction& rhs) { lhs = lhs - rhs; }

        inline Fraction operator*(const Fraction& lhs, const Fraction& rhs) { return Fraction::arithmetic->multiply(lhs, rhs); }

        inline void operator*=(Fraction& lhs, const Fraction& rhs) { lhs = lhs * rhs; }

        inline Fraction operator/(const Fraction& lhs, const Fraction& rhs) { return Fraction::arithmetic->divide(lhs, rhs); }

        inline void operator/=(Fraction& lhs, const Fraction& rhs) { lhs = lhs / rhs; }

        /// END OPERATORS

    };

};

#endif