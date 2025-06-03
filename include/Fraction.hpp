#ifndef sdkmath_prealgebra_Fraction
#define sdkmath_prealgebra_Fraction

#include <vector>
#include <utility>

namespace sdkmath {

    namespace prealgebra {

        class Fraction {

            long numerator, denominator;

        public:
            
            static std::vector<long> getPrimaryDecomposition(long);
            
            Fraction();

            Fraction(long numerator, long denominator);

            Fraction(long integer);

            void setNumerator(long numerator) { this->numerator = numerator; }

            long getNumerator(void) const { return numerator; }

            void setDenominator(long denominator);

            long getDenominator(void) const { return denominator; }

            Fraction getSimplified(void) const;

            void simplify(void);

            static long lcd(long, long);

        };

        inline bool operator==(const Fraction& lhs, const Fraction& rhs) {
            Fraction simplified = lhs.getSimplified(), 
                    otherSimplified = rhs.getSimplified();
            
            return simplified.getNumerator() == otherSimplified.getNumerator()
                && simplified.getDenominator() == otherSimplified.getDenominator();
        }
        
        inline bool operator!=(const Fraction& lhs, const Fraction& rhs) { return !(lhs == rhs); }
        
        inline bool operator==(const long& lhs, const Fraction& rhs) { return Fraction(lhs) == rhs; }
        
        inline bool operator!=(const long& lhs, const Fraction& rhs) { return !(lhs == rhs); }
        
        inline bool operator==(const Fraction& lhs, const long& rhs) { return rhs == lhs; }
        
        inline bool operator!=(const Fraction& lhs, const long& rhs) { return !(lhs == rhs); }

        inline Fraction operator*(const Fraction&lhs, const long& rhs) { 
            return Fraction(
                rhs * lhs.getNumerator(), 
                lhs.getDenominator()
            );
        }

        inline Fraction operator*=(Fraction&lhs, const long& rhs) { lhs = lhs * rhs; }

        inline Fraction operator*(const long& lhs, const Fraction& rhs) { return rhs * lhs; }

        inline Fraction operator+(const long& lhs, const Fraction& rhs) { return rhs; }

        inline Fraction operator-(const long& lhs, const Fraction&rhs) { return lhs + -1 * rhs; }

        inline Fraction operator+(const Fraction& lhs, const long& rhs) { return rhs + lhs; }

        inline Fraction operator+=(Fraction& lhs, const long& rhs) { lhs = rhs + lhs; }

        inline Fraction operator-(const Fraction& lhs, const long&rhs) { return lhs + -1 * rhs; }

        inline Fraction operator-=(Fraction& lhs, const long& rhs) { lhs = lhs - rhs; }

        inline Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
            long lcd = Fraction::lcd(lhs.getDenominator(), rhs.getDenominator());
            return Fraction(
                (lcd / lhs.getDenominator() * lhs.getNumerator()) 
                + (lcd / rhs.getDenominator() * rhs.getNumerator())
                , lcd
            );
        }

        inline Fraction operator+=(Fraction& lhs, const Fraction& rhs) { lhs = lhs + rhs; }

        inline Fraction operator-(const Fraction& lhs, const Fraction& rhs) { return lhs + -1 * rhs; }

        inline Fraction operator-=(Fraction& lhs, const Fraction& rhs) { lhs = lhs - rhs; }

    };

};

#endif