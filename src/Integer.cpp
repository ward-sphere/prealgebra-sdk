#include <Integer.hpp>

using namespace sdkmath::prealgebra;

void Integer::setValue(long value) { 
    if (value < 0) {
        value *= -1;
        negative = true;
    }
    this->value = value; 
}

Integer::Integer(long value) { setValue(value); }

long Integer::getValue(void) const { return this->value; }

bool Integer::isNegative(void) const { return negative; }

bool Integer::operator==(const Integer& other) const { 
    return isNegative() == other.isNegative()
        && getValue() == other.getValue(); 
}

bool Integer::operator!=(const Integer& other) const { return !(*this == other); }