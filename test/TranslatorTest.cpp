#include <gtest/gtest.h>
#include <Translator.hpp>

#include <sstream>

using namespace sdkmath::prealgebra;

TEST(TranslatorTest, TestTranslateInteger) {
    for (int input = -5; input <= 5; input++) {
        std::stringstream ss; ss << input;
        ASSERT_EQ(Fraction(input, 1), Translator::itof(Integer(input)));
        ASSERT_EQ(Decimal(ss.str()), Translator::itod(Integer(input)));
    }
}

TEST(TranslatorTest, TestTranslateFraction1) {
    Fraction input(3, 2);
    ASSERT_THROW(Translator::ftoi(input), std::invalid_argument);
    ASSERT_EQ(Decimal("1.5"), Translator::ftod(input));
}

TEST(TranslatorTest, TestTranslateFraction2) {
    Fraction input(2, 1);
    ASSERT_EQ(Integer(2), Translator::ftoi(input));
    ASSERT_EQ(Decimal("2"), Translator::ftod(input));
}

TEST(TranslatorTest, TestTranslateFraction3) {
    Fraction input(-70, 10);
    ASSERT_EQ(Integer(-7), Translator::ftoi(input));
    ASSERT_EQ(Decimal("-7"), Translator::ftod(input));
}

TEST(TranslatorTest, TestTranslateFraction4) {
    Fraction input(-5, 8);
    ASSERT_THROW(Translator::ftoi(input), std::invalid_argument);
    ASSERT_EQ(Decimal("-0.625"), Translator::ftod(input));
}

TEST(TranslatorTest, TestTranslateDecimal1) {
    Decimal input("51.91");
    ASSERT_THROW(Translator::dtoi(input), std::invalid_argument);
    ASSERT_EQ(Fraction(5191, 100), input);
}

TEST(TranslatorTest, TestTranslateDecimal2) {
    Decimal input("-2");
    ASSERT_EQ(Integer(-2), Translator::dtoi(input));
    ASSERT_EQ(Fraction(-2, 0), Translator::dtof(input));
}

TEST(TranslatorTest, TestTranslateDecimal3) {
    Decimal input("-87.25");
    ASSERT_THROW(Translator::dtoi(input), std::invalid_argument);
    ASSERT_EQ(Fraction(-349/4), Translator::dtof(input));
}