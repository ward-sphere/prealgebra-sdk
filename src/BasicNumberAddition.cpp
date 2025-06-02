#include <BasicNumberAddition.hpp>

#include <stdexcept>

using namespace sdkmath::prealgebra;

BasicNumberAddition::BasicNumberAddition(INumberTranslator& translator) : translator(translator) {}

Integer BasicNumberAddition::add(Integer lhs, Integer rhs) {
    return lhs.getValue() * (lhs.isNegative() ? -1 : 1)
        + rhs.getValue() * (rhs.isNegative() ? -1 : 1);
}

Integer BasicNumberAddition::subtract(Integer lhs, Integer rhs) {
    return add(lhs, (rhs.isNegative() ? 1 : -1) * rhs.getValue());
}

Fraction BasicNumberAddition::add(Fraction lhs, Fraction rhs) {
    if (lhs.getDenominator() != rhs.getDenominator())
        throw std::invalid_argument("Fractions and mixed numbers must have same denominator to be added/subtracted");
    return Fraction(
        lhs.getNumerator().getValue() * (lhs.isNegative() ? -1 : 1) + rhs.getNumerator().getValue() * (rhs.isNegative() ? -1 : 1),
        lhs.getDenominator()
    );
}

Fraction BasicNumberAddition::subtract(Fraction lhs, Fraction rhs) {
    return add(
        lhs,
        Fraction(
            (rhs.isNegative() ? 1 : -1) * rhs.getNumerator().getValue(),
            rhs.getDenominator()
        )
    );
}

MixedNumber BasicNumberAddition::add(MixedNumber lhs, MixedNumber rhs) {
    return translator.getMixedNumber(
        add(
            translator.getFraction(lhs),
            translator.getFraction(rhs)
        )
    );
}

MixedNumber BasicNumberAddition::subtract(MixedNumber lhs, MixedNumber rhs) {
    return translator.getMixedNumber(
        subtract(
            translator.getFraction(lhs),
            translator.getFraction(rhs)
        )
    );
}
