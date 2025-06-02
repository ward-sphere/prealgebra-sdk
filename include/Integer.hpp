#ifndef sdkmath_prealgebra_Integer
#define sdkmath_prealgebra_Integer

namespace sdkmath {

    namespace prealgebra {

        class Integer {

            long value;

        public:

            Integer(long value);

            Integer(Integer& copy);

            long getValue(void);

        };

    };

};

#endif