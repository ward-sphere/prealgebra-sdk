#include <include/Integer.hpp>

using namespace sdkmath::prealgebra;

void Integer::setValue(long value) { this->value = value; }

Integer::Integer(long value) { setValue(value); }

Integer::Integer(Integer& copy) { setValue(copy.getValue()); }

long Integer::getValue(void) { return this->value; }