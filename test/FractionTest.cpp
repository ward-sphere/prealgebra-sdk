#include <gtest/gtest.h>
#include <Fraction.hpp>

using namespace sdkmath::prealgebra;

TEST(FractionTest, TestFractionRepresentation) {
    try {
        Fraction f(2, 0);
        ASSERT_TRUE(false);
    } catch (std::invalid_argument) {
        ASSERT_TRUE(true);
    }
}

TEST(FractionTest, TestFractionSimplification1) {
    Fraction input(14, 21);
    Fraction expected(2, 3), actual = input.getSimplified();

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionSimplification2) {
    Fraction input(15, 35);
    Fraction expected(3, 7), actual = input.getSimplified();

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionSimplification3) {
    Fraction input(20, 70);
    Fraction expected(2, 7), actual = input.getSimplified();

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionSimplification4) {
    Fraction input(7, 21);
    Fraction expected(1, 3), actual = input.getSimplified();

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionSimplification5) {
    Fraction input(15, 105);
    Fraction expected(1, 7), actual = input.getSimplified();

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionSimplification6) {
    Fraction input(35, 7);
    long expected = 5;
    Fraction actual = input.getSimplified();

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionSimplification7) {
    Fraction input(70, 10);
    long expected = 7;
    Fraction actual = input.getSimplified();

    ASSERT_EQ(expected, actual);
}
