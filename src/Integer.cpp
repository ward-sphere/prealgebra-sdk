#include <Integer.hpp>
#include <factory/IIntegerFactory.hpp>

using namespace sdkmath::prealgebra;

factory::IIntegerFactory integer_factory;

std::unique_ptr<IIntegerArithmetic> Integer::arithmetic = integer_factory.createIntegerArithmetic();