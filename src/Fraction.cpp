#include <Fraction.hpp>
#include <factory/IFractionFactory.hpp>

using namespace sdkmath::prealgebra;

factory::IFractionFactory f;

std::unique_ptr<IFractionArithmetic> Fraction::arithmetic = f.createFractionArithmetic();
std::unique_ptr<IFractionSimplification> Fraction::simplification = f.createFractionSimplification();
