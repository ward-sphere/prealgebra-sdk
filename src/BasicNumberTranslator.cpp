#include <BasicNumberTranslator.hpp>

#include <stdexcept>

using namespace sdkmath::prealgebra;

Fraction BasicNumberTranslator::toFraction(Integer i) {
    return Fraction(i, 1);
}

Integer BasicNumberTranslator::toInteger(Fraction f) {
    if (f.getDenominator() != 1)
        throw std::invalid_argument("Fraction must have denominator 1 to convert to integer");
    return f.getNumerator();
}

Fraction BasicNumberTranslator::getFraction(MixedNumber mn) {
    return Fraction(
        mn.getBase().getValue() * mn.getFraction().getDenominator().getValue() + mn.getFraction().getNumerator().getValue(),
        mn.getFraction().getDenominator()
    );
}

MixedNumber BasicNumberTranslator::getMixedNumber(Fraction f) {
    return MixedNumber(
        f.getNumerator().getValue() / f.getDenominator().getValue(),
        f.getNumerator().getValue() % f.getDenominator().getValue(),
        f.getDenominator()
    );
}