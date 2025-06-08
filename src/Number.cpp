#include <Number.hpp>
#include <factory/NumberArithmeticFactory.hpp>

using namespace sdkmath::prealgebra;

factory::NumberArithmeticFactory number_factory;
std::unique_ptr<INumberArithmetic> Number::arithmetic = number_factory.createNumberArithmetic();
