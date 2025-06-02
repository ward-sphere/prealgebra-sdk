#include <Integer.hpp>

using namespace sdkmath::prealgebra;

void Integer::setValue(long value) { this->value = value; }

Integer::Integer(long value) { setValue(value); }

long Integer::getValue(void) const { return this->value; }

bool Integer::operator==(const Integer& other) const { return getValue() == other.getValue(); }

bool Integer::operator!=(const Integer& other) const { return !(*this == other); }