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

TEST(FractionTest, TestPrimaryDecomposition1) {
    long input = 3;
    std::vector<long> expected = {3}, actual = Fraction::getPrimaryDecomposition(input);

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestPrimaryDecomposition2) {
    long input = 4;
    std::vector<long> expected = {2, 2}, actual = Fraction::getPrimaryDecomposition(input);

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestPrimaryDecomposition3) {
    long input = 6;
    std::vector<long> expected = {2, 3}, actual = Fraction::getPrimaryDecomposition(input);

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestPrimaryDecomposition4) {
    long input = 15;
    std::vector<long> expected = {3, 5}, actual = Fraction::getPrimaryDecomposition(input);

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestPrimaryDecomposition5) {
    long input = 27;
    std::vector<long> expected = {3, 3, 3}, actual = Fraction::getPrimaryDecomposition(input);

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestPrimaryDecomposition6) {
    long input = 18;
    std::vector<long> expected = {2, 3, 3}, actual = Fraction::getPrimaryDecomposition(input);

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestLcd1) {
    long input1 = 3, input2 = 4;
    long expected = 12, actual = Fraction::lcd(input1, input2);

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestLcd2) {
    long input1 = 6, input2 = 15;
    long expected = 30, actual = Fraction::lcd(input1, input2);

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestLcd3) {
    long input1 = 27, input2 = 18;
    long expected = 54, actual = Fraction::lcd(input1, input2);

    ASSERT_EQ(expected, actual);
}
