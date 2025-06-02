#ifndef sdkmath_prealgebra_Integer
#define sdkmath_prealgebra_Integer

namespace sdkmath {

    namespace prealgebra {

        class Integer {

            void setValue(long);

            long value;

            bool negative = false;

        public:

            Integer(long value);

            long getValue(void) const;

            bool isNegative(void) const;

            bool operator==(const Integer& other) const;

            bool operator!=(const Integer& other) const;

        };

    };

};

#endif