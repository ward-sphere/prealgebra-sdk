#ifndef sdkmath_prealgebra_Fraction
#define sdkmath_prealgebra_Fraction

#include <Number.hpp>

#include <sstream>
#include <stdexcept>

namespace sdkmath {

    namespace prealgebra {

        class Fraction;
        class IFractionSimplification;

        /// @brief tools for fraction simplification
        class IFractionSimplification {

        public:

            /// @brief returns a simplified version of some fraction
            virtual Fraction simplify(const Fraction&) = 0;

            /// @brief changes two fractions to the form of their gcd
            virtual void lcd(Fraction&, Fraction&) = 0;

        };

        /// @brief unit defining high-level details of fractions
        class Fraction : public Number {

            /// @brief fraction numerator
            long numerator = 0;

            /// @brief fraction denominator; non-zero
            long denominator = 1;

            static IFractionSimplification& simplification;

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

            /// @brief numerator getter
            long getNumerator(void) const { return numerator; }

            /// @brief denominator getter
            long getDenominator(void) const { return denominator; }

            /// @brief call IFractionSimplification instance to get simplified version of this
            Fraction simplified(void) const { return simplification.simplify(*this); }

            /// @brief change this fraction into its simplified version 
            void simplify(void) {
                Fraction tmp(simplified());
                this->numerator = tmp.getNumerator();
                this->denominator = tmp.getDenominator();
            }

            std::string toString() const {
                std::stringstream ss;
                ss << getNumerator() << "/" << getDenominator();
                return ss.str();
            }

            std::pair<long, long> toFractionalValues() const { return {numerator, denominator}; }
            
            Fraction& operator=(const Fraction& other) {
                if (this != &other) {
                    numerator = other.getNumerator();
                    denominator = other.getDenominator();
                }
                return *this;
            }

        };

    };

};

#endif