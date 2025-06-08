#include <concrete/DefaultDecimalRepresentation.hpp>
#include <factory/IDefaultDecimalRepresentationFactory.hpp>

using namespace sdkmath::prealgebra::concrete;

sdkmath::prealgebra::factory::IDefaultDecimalRepresentationFactory default_decimal_representation_factory;

DefaultDecimalRepresentation::DefaultDecimalRepresentation() {
    string_parser = default_decimal_representation_factory.createDecimalStringParser();
}