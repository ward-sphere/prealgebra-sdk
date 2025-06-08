#include <Translator.hpp>
#include <factory/ITranslatoryFactory.hpp>

using namespace sdkmath::prealgebra;

factory::ITranslatoryFactory translator_factory;

std::unique_ptr<IIntegerTranslator> Translator::integer_translator = translator_factory.createIntegerTranslator();
std::unique_ptr<IFractionTranslator> Translator::fraction_translator = translator_factory.createFractionTranslator();
std::unique_ptr<IDecimalTranslator> Translator::decimal_translator = translator_factory.createDecimalTranslator();