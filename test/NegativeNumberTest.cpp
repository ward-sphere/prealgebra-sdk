#include <gtest/gtest.h>
#include <Integer.hpp>
#include <Fraction.hpp>
#include <MixedNumber.hpp>

using namespace sdkmath::prealgebra;

TEST(NegativeNumberTest, NegativeNumberTest_Test1) {
    Integer i(-5);

    ASSERT_EQ(5, i.getValue());
    ASSERT_TRUE(i.isNegative());
}

TEST(NegativeNumberTest, NegativeNumberTest_Test2) {
    Fraction f(-88, 9);

    ASSERT_EQ(88, f.getNumerator().getValue());
    ASSERT_EQ(9, f.getDenominator().getValue());
    ASSERT_TRUE(f.isNegative());
}

TEST(NegativeNumberTest, NegativeNumberTest_Test3) {
    MixedNumber mn(-5, 2, 3);

    ASSERT_EQ(5, mn.getBase().getValue());
    ASSERT_EQ(2, mn.getFraction().getNumerator().getValue());
    ASSERT_EQ(3, mn.getFraction().getDenominator().getValue());
}

TEST(NegativeNumberTest, NegativeNumberTest_Test4) {
    try {
        MixedNumber mn(5, -2, 3);
        ASSERT_TRUE(false);
    } catch (std::invalid_argument) {
        ASSERT_TRUE(true);
    }
}

TEST(NegativeNumberTest, NegativeNumberTest_Test5) {
    try {
        MixedNumber mn(5, 2, -3);
        ASSERT_TRUE(false);
    } catch (std::invalid_argument) {
        ASSERT_TRUE(true);
    }
}

TEST(NegativeNumberTest, NegativeNumberTest_Test6) {
    try {
        MixedNumber mn(0, -2, 3);
        ASSERT_TRUE(true);
    } catch (std::invalid_argument) {
        ASSERT_TRUE(false);
    }
}

TEST(NegativeNumberTest, NegativeNumberTest_Test7) {
    try {
        MixedNumber mn(0, 2, -3);
        ASSERT_TRUE(true);
    } catch (std::invalid_argument) {
        ASSERT_TRUE(false);
    }
}
