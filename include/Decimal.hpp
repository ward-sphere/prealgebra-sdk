#ifndef sdkmath_prealgebra_Decima
#define sdkmath_prealgebra_Decima

#include <Fraction.hpp>

#include <map>

namespace sdkmath {

    namespace prealgebra {

        typedef struct {

            int maxPlacement = 10;

            int minPlacement = -10;

        } DecimalContext;

        class Decimal {

            DecimalContext ctx;

            void convertLong(long);

            void convertDouble(double);

            void convertFraction(Fraction);

            void convertString(std::string);

        public:

            std::map<int, long> mValues;

            Decimal(long value) { convertLong(value); }

            Decimal(long value, DecimalContext ctx) {
                this->ctx = ctx;
                convertLong(value);
            }

            Decimal(double value) { convertDouble(value); }

            Decimal(double value, DecimalContext ctx) {
                this->ctx = ctx;
                convertDouble(value);
            }

            Decimal(Fraction value) { convertFraction(value); }

            Decimal(Fraction value, DecimalContext ctx) {
                this->ctx = ctx;
                convertFraction(value);
            }

            Decimal(std::string value) { convertString(value); }

            Decimal(std::string value, DecimalContext ctx) {
                this->ctx = ctx;
                convertString(value);
            }

            double toDouble(void) const;

            Fraction toFraction(void) const;

        };

        inline bool operator==(const Decimal& lhs, const Decimal& rhs) { return lhs.toFraction() == rhs.toFraction(); }

        inline bool operator!=(const Decimal& lhs, const Decimal& rhs) { return !(lhs == rhs); }

        inline Decimal operator+(const Decimal& lhs, const Decimal& rhs) { return Decimal(lhs.toFraction() + rhs.toFraction()); }

        inline void operator+=(Decimal& lhs, const Decimal& rhs) { lhs = lhs + rhs; }

        inline Decimal operator-(const Decimal& lhs, const Decimal& rhs) { return Decimal(lhs.toFraction() - rhs.toFraction()); }

        inline void operator-=(Decimal& lhs, const Decimal& rhs) { lhs = lhs - rhs; }

        inline Decimal operator*(const Decimal& lhs, const Decimal& rhs) { return Decimal(lhs.toFraction() * rhs.toFraction()); }

        inline void operator*=(Decimal& lhs, const Decimal& rhs) { lhs = lhs * rhs; }

        inline Decimal operator/(const Decimal& lhs, const Decimal& rhs) { return Decimal(lhs.toFraction() / rhs.toFraction()); }

        inline void operator/=(Decimal& lhs, const Decimal& rhs) { lhs = lhs / rhs; }

    };

};

#endif