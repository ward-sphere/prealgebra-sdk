#include <Number.hpp>
#include <factory/NumberArithmeticFactory.hpp>

using namespace sdkmath::prealgebra;

factory::NumberArithmeticFactory number_factory;
INumberArithmetic& Number::arithmetic = number_factory.createNumberArithmetic();
