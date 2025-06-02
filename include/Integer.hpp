#ifndef sdkmath_prealgebra_Integer
#define sdkmath_prealgebra_Integer

namespace sdkmath {

    namespace prealgebra {

        class Integer {

            void setValue(long);

            long value;

        public:

            Integer(long value);

            Integer(Integer& copy);

            long getValue(void);

        };

    };

};

#endif