#include <Integer.hpp>
#include <factory/IIntegerFactory.hpp>

using namespace sdkmath::prealgebra;

factory::IIntegerFactory f;

std::unique_ptr<IIntegerArithmetic> Integer::arithmetic = f.createIntegerArithmetic();