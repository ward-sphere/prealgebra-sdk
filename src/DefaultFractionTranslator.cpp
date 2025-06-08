#include <concrete/DefaultFractionTranslator.hpp>
#include <factory/IFractionTranslatorFactory.hpp>

using namespace sdkmath::prealgebra;

factory::IFractionTranslatorFactory fraction_translator_factory;

DefaultFractionTranslator::DefaultFractionTranslator() {
    ftod = fraction_translator_factory.createFractionToDecimalTranslator();
}