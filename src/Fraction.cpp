#include <Fraction.hpp>
#include <factory/IFractionFactory.hpp>

using namespace sdkmath::prealgebra;

factory::IFractionFactory fraction_factory;

std::unique_ptr<IFractionArithmetic> Fraction::arithmetic = fraction_factory.createFractionArithmetic();
std::unique_ptr<IFractionSimplification> Fraction::simplification = fraction_factory.createFractionSimplification();
