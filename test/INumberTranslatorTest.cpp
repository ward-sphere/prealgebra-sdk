#include <gtest/gtest.h>
#include <INumberTranslator.hpp>
#include <BasicNumberTranslator.hpp>

using namespace sdkmath::prealgebra;

INumberTranslator& translator = *new BasicNumberTranslator();

TEST(INumberTranslatorTest, TestCastFraction1) {
    Fraction input(5, 1);
    Integer expectedOutput = 5, actualOutput = translator.toInteger(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberTranslatorTest, TestCastFraction2) {
    Fraction input(7, 1);
    Integer expectedOutput = 7, actualOutput = translator.toInteger(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberTranslatorTest, TestCastFraction3) {
    Fraction input(-7, 1);
    Integer expectedOutput = -7, actualOutput = translator.toInteger(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberTranslatorTest, TestTranslateImproperFraction1) {
    Fraction input(7, 4);
    MixedNumber expectedOutput(1, Fraction(3, 4)), actualOutput = translator.getMixedNumber(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberTranslatorTest, TestTranslateImproperFraction2) {
    Fraction input(15, 3);
    MixedNumber expectedOutput(5, Fraction(0, 3)), actualOutput = translator.getMixedNumber(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberTranslatorTest, TestTranslateImproperFraction3) {
    Fraction input(-7, 4);
    MixedNumber expectedOutput(-1, Fraction(3, 4)), actualOutput = translator.getMixedNumber(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberTranslatorTest, TestTranslateImproperFraction4) {
    Fraction input(15, -3);
    MixedNumber expectedOutput(-5, Fraction(0, 3)), actualOutput = translator.getMixedNumber(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberTranslatorTest, TestTranslateMixedNumber1) {
    MixedNumber input(3, Fraction(1, 7));
    Fraction expectedOutput(22, 7), actualOutput = translator.getFraction(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberTranslatorTest, TestTranslateMixedNumber2) {
    MixedNumber input(5, Fraction(4, 5));
    Fraction expectedOutput(29, 5), actualOutput = translator.getFraction(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberTranslatorTest, TestTranslateMixedNumber3) {
    MixedNumber input(-3, Fraction(1, 7));
    Fraction expectedOutput(-22, 7), actualOutput = translator.getFraction(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberTranslatorTest, TestTranslateMixedNumber4) {
    MixedNumber input(-5, Fraction(4, 5));
    Fraction expectedOutput(29, -5), actualOutput = translator.getFraction(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}