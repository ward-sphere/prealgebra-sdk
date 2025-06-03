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

TEST(FractionTest, TestAddition1) {
    Fraction lhs(5, 7), rhs(1, 7);
    Fraction expected(6, 7), actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition2) {
    Fraction lhs(2, 3), rhs(1, 3);
    Fraction expected(3, 3), actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition3) {
    Fraction lhs(3, 5), rhs(4, 5);
    Fraction expected(7, 5), actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition4) {
    Fraction lhs(9, 11), rhs(2, 11);
    Fraction expected(7, 11), actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition5) {
    Fraction lhs(5, 6), rhs(1, 6);
    Fraction expected(2, 3), actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition6) {
    Fraction lhs(2, 3), rhs(1, 4);
    Fraction expected(11, 12), actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition7) {
    Fraction lhs(7, 18), rhs(5, 12);
    Fraction expected(29, 36), actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition8) {
    Fraction lhs(25, 48), rhs(5, 36);
    Fraction expected(55, 144), actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication1) {
    Fraction lhs(3, 5), rhs(2, 7);
    Fraction expected(6, 35), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication2) {
    Fraction lhs(1, 3), rhs(5, 4);
    Fraction expected(5, 12), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication3) {
    Fraction lhs(7, 3), rhs(1, 5);
    Fraction expected(7, 15), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication4) {
    Fraction lhs(6, 5), rhs(2, 3);
    Fraction expected(4, 5), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication5) {
    Fraction lhs(3, 5), rhs(5, 7);
    Fraction expected(3, 7), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication6) {
    Fraction lhs(4, 11), rhs(5, 2);
    Fraction expected(10, 11), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication7) {
    Fraction lhs(15, 8), rhs(10, 27);
    Fraction expected(25, 36), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication8) {
    long lhs = 7; 
    Fraction rhs(3, 5);
    Fraction expected(21, 5), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication9) {
    Fraction lhs(3, 16);
    long rhs = 4;
    Fraction expected(3, 4), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication10) {
    Fraction lhs(1, 3);
    long rhs = 2;
    Fraction expected(1, 6), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication11) {
    long lhs = 5;
    Fraction rhs(1, 3);
    Fraction expected(15), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication12) {
    Fraction lhs(3, 7), rhs(3, 5);
    Fraction expected(5, 7), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication13) {
    Fraction lhs(2, 9), rhs(5, 7);
    Fraction expected(14, 45), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestFractionMultiplication14) {
    long lhs = 96;
    Fraction rhs(3, 4);
    Fraction expected(128), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}