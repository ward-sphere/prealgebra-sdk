#include <gtest/gtest.h>
#include <Fraction.hpp>

#include <limits>

using namespace sdkmath::prealgebra;

TEST(FractionTest, TestConstructor01) {
    Fraction f(0, 1);
    long expectedNum = 0, actualNum = f.getNumerator();
    long exepctedDen = 1, actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestConstructor02) {
    Fraction f(std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    long expectedNum = std::numeric_limits<long>::min(), actualNum = f.getNumerator();
    long exepctedDen = std::numeric_limits<long>::max(), actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestConstructor03) {
    Fraction f(std::numeric_limits<long>::max(), std::numeric_limits<long>::min() + 1);
    long expectedNum = -(std::numeric_limits<long>::max()), actualNum = f.getNumerator();
    long exepctedDen = -(std::numeric_limits<long>::min() + 1), actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestConstructor04) {
    Fraction f(-500000000, 500000000);
    long expectedNum = -500000000, actualNum = f.getNumerator();
    long exepctedDen = 500000000, actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestConstructor05) {
    Fraction f(500000000, -500000000);
    long expectedNum = -500000000, actualNum = f.getNumerator();
    long exepctedDen = 500000000, actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestConstructor06) {
    Fraction f(-500000000, -500000000);
    long expectedNum = 500000000, actualNum = f.getNumerator();
    long exepctedDen = 500000000, actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestConstructor07) { ASSERT_THROW(Fraction(0, 0), std::invalid_argument); }

TEST(FractionTest, TestConstructor08) {
    Fraction f(0, 1);
    long expectedNum = 0, actualNum = f.getNumerator();
    long exepctedDen = 1, actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestConstructor09) {
    Fraction f(std::numeric_limits<long>::min(), 1);
    long expectedNum = std::numeric_limits<long>::min(), actualNum = f.getNumerator();
    long exepctedDen = 1, actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestConstructor10) {
    Fraction f(std::numeric_limits<long>::max(), 1);
    long expectedNum = std::numeric_limits<long>::max(), actualNum = f.getNumerator();
    long exepctedDen = 1, actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestConstructor11) {
    Fraction f(-500000000, 1);
    long expectedNum = -500000000, actualNum = f.getNumerator();
    long exepctedDen = 1, actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestConstructor12) {
    Fraction f(500000000, 1);
    long expectedNum = 500000000, actualNum = f.getNumerator();
    long exepctedDen = 1, actualDen = f.getDenominator();

    ASSERT_EQ(expectedNum, actualNum);
    ASSERT_EQ(exepctedDen, actualDen);
}

TEST(FractionTest, TestEquality1) {
    Fraction lhs(2, 3), rhs(2, 3);
    bool expected = true, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality2) {
    Fraction lhs(2, 3), rhs(-2, -3);
    bool expected = true, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality3) {
    for (int k = -5; k <= 5; k++) {
        if (k == 0) continue;

        Fraction lhs(k * 2, k * 3), rhs(k * 2, k * 3);
        bool expected = true, actual = lhs == rhs;

        ASSERT_EQ(expected, actual);
    }
}

TEST(FractionTest, TestEquality4) {
    Fraction lhs(2, 3), rhs(-2, 3);
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality5) {
    Fraction lhs(2, 3), rhs(2, -3);
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality6) {
    for (int k = -5; k <= 5; k++) {
        if (k == 0) continue;

        Fraction lhs(k * 2, k * 3), rhs(-k * 2, k * 3);
        bool expected = false, actual = lhs == rhs;

        ASSERT_EQ(expected, actual);
    }
}

TEST(FractionTest, TestEquality7) {
    for (int k = -5; k <= 5; k++) {
        if (k == 0) continue;

        Fraction lhs(k * 2, k * 3), rhs(k * 2, -k * 3);
        bool expected = false, actual = lhs == rhs;

        ASSERT_EQ(expected, actual);
    }
}

TEST(FractionTest, TestEquality8) {
    Fraction lhs(2, 3), rhs(2, 3);
    bool expected = false, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality9) {
    Fraction lhs(2, 3), rhs(-2, -3);
    bool expected = false, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality10) {
    for (int k = -5; k <= 5; k++) {
        if (k == 0) continue;

        Fraction lhs(k * 2, k * 3), rhs(k * 2, k * 3);
        bool expected = false, actual = lhs != rhs;

        ASSERT_EQ(expected, actual);
    }
}

TEST(FractionTest, TestEquality11) {
    Fraction lhs(2, 3), rhs(-2, 3);
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality12) {
    Fraction lhs(2, 3), rhs(2, -3);
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality13) {
    for (int k = -5; k <= 5; k++) {
        if (k == 0) continue;

        Fraction lhs(k * 2, k * 3), rhs(-k * 2, k * 3);
        bool expected = true, actual = lhs != rhs;

        ASSERT_EQ(expected, actual);
    }
}

TEST(FractionTest, TestEquality14) {
    for (int k = -5; k <= 5; k++) {
        if (k == 0) continue;

        Fraction lhs(k * 2, k * 3), rhs(k * 2, -k * 3);
        bool expected = true, actual = lhs != rhs;

        ASSERT_EQ(expected, actual);
    }
}

TEST(FractionTest, TestEquality15) {
    Fraction lhs(2, 1), rhs(2, 1);
    bool expected = true, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality16) {
    for (int k = -5; k <= 5; k++) {
        if (k == 0) continue;

        Fraction lhs(k * 2, 1), rhs(k * 2, 1);
        bool expected = true, actual = lhs == rhs;

        ASSERT_EQ(expected, actual);
    }
}

TEST(FractionTest, TestEquality17) {
    Fraction lhs(2, 1), rhs(-2, 1);
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality18) {
    for (int k = -5; k <= 5; k++) {
        if (k == 0) continue;

        Fraction lhs(k * 2, 1), rhs(-k * 2, 1);
        bool expected = false, actual = lhs == rhs;

        ASSERT_EQ(expected, actual);
    }
}

TEST(FractionTest, TestEquality19) {
    Fraction lhs(2, 1), rhs(2, 1);
    bool expected = false, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality20) {
    for (int k = -5; k <= 5; k++) {
        if (k == 0) continue;

        Fraction lhs(k * 2, 1), rhs(k * 2, 1);
        bool expected = false, actual = lhs != rhs;

        ASSERT_EQ(expected, actual);
    }
}

TEST(FractionTest, TestEquality21) {
    Fraction lhs(2, 1), rhs(-2, 1);
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestEquality22) {
    for (int k = -5; k <= 5; k++) {
        if (k == 0) continue;

        Fraction lhs(k * 2, 1), rhs(-k * 2, 1);
        bool expected = true, actual = lhs != rhs;

        ASSERT_EQ(expected, actual);
    }
}

TEST(FractionTest, TestInequality01) {
    Fraction lhs(2, 4), rhs(2, 3);
    bool expected = false, actual = lhs > rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality02) {
    Fraction lhs(2, 4), rhs(2, 3);
    bool expected = true, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality03) {
    Fraction lhs(2, 4), rhs(2, 3);
    bool expected = false, actual = lhs >= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality04) {
    Fraction lhs(2, 4), rhs(2, 3);
    bool expected = true, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality05) {
    Fraction lhs(1, 1), rhs(1, 1);
    bool expected = false, actual = lhs > rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality06) {
    Fraction lhs(1, 1), rhs(1, 1);
    bool expected = false, actual = lhs > rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality07) {
    Fraction lhs(1, 1), rhs(1, 1);
    bool expected = true, actual = lhs >= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality08) {
    Fraction lhs(1, 1), rhs(1, 1);
    bool expected = true, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality09) {
    Fraction lhs(-2, 3), rhs(2, 4);
    bool expected = true, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality10) {
    Fraction lhs(-2, 3), rhs(2, 4);
    bool expected = false, actual = lhs > rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality11) {
    Fraction lhs(-2, 3), rhs(2, 4);
    bool expected = true, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality12) {
    Fraction lhs(-2, 3), rhs(2, 4);
    bool expected = false, actual = lhs >= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality13) {
    Fraction lhs(1, 2), rhs(50, 100);
    bool expected = false, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality14) {
    Fraction lhs(1, 2), rhs(50, 100);
    bool expected = false, actual = lhs > rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality15) {
    Fraction lhs(1, 2), rhs(50, 100);
    bool expected = true, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestInequality16) {
    Fraction lhs(1, 2), rhs(50, 100);
    bool expected = true, actual = lhs >= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition01) {
    Fraction lhs(2, 3), rhs(1, 3);
    Fraction expected(3, 3);
    Number& actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition02) {
    Fraction lhs(2, 3), rhs(-1, 3);
    Fraction expected(1, 3);
    Number& actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition03) {
    Fraction lhs(-2, 3), rhs(1, 3);
    Fraction expected(-1, 3);
    Number& actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition04) {
    Fraction lhs(-2, 3), rhs(-1, 3);
    Fraction expected(-3, 3);
    Number& actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition05) {
    Fraction lhs(0, 1), rhs(0, 1);
    Fraction expected(0, 1);
    Number& actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition06) {
    Fraction lhs(1, 2), rhs(1, 5);
    Fraction expected(7, 10);
    Number& actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition07) {
    Fraction lhs(1, 2), rhs(-1, 5);
    Fraction expected(3, 10);
    Number& actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition08) {
    Fraction lhs(-1, 2), rhs(-1, 5);
    Fraction expected(-7, 10);
    Number& actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition09) {
    Fraction lhs(-1, 2), rhs(1, 5);
    Fraction expected(-3, 10);
    Number& actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition10) {
    Fraction lhs(-1, 2), rhs(1, 5);
    Fraction expected(-7, 10);
    Number& actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition11) {
    Fraction lhs(2, 3), rhs(1, 3);
    Fraction expected(1, 3);
    Number& actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition12) {
    Fraction lhs(2, 3), rhs(-1, 3);
    Fraction expected(3, 3);
    Number& actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition13) {
    Fraction lhs(-2, 3), rhs(1, 3);
    Fraction expected(-3, 3);
    Number& actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition14) {
    Fraction lhs(-2, 3), rhs(-1, 3);
    Fraction expected(-1, 3);
    Number& actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition15) {
    Fraction lhs(0, 1), rhs(0, 1);
    Fraction expected(0, 1);
    Number& actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition16) {
    Fraction lhs(1, 2), rhs(1, 5);
    Fraction expected(3, 10);
    Number& actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition17) {
    Fraction lhs(1, 2), rhs(-1, 5);
    Fraction expected(7, 10);
    Number& actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestAddition18) {
    Fraction lhs(-1, 2), rhs(-1, 5);
    Fraction expected(-3, 10);
    Number& actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication01) {
    Fraction lhs(2, 3), rhs(1, 3);
    Fraction expected(2, 9);
    Number& actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication02) {
    Fraction lhs(2, 3), rhs(-1, 3);
    Fraction expected(-2, 9);
    Number& actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication03) {
    Fraction lhs(-2, 3), rhs(1, 3);
    Fraction expected(-2, 9);
    Number& actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication04) {
    Fraction lhs(-2, 3), rhs(-1, 3);
    Fraction expected(2, 9);
    Number& actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication05) {
    Fraction lhs(0, 1), rhs(0, 1);
    Fraction expected(0, 1);
    Number& actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication06) {
    Fraction lhs(1, 2), rhs(1, 5);
    Fraction expected(1, 10);
    Number& actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication07) {
    Fraction lhs(1, 2), rhs(-1, 5);
    Fraction expected(1, -10);
    Number& actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication08) {
    Fraction lhs(-1, 2), rhs(-1, 5);
    Fraction expected(1, 10);
    Number& actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication09) {
    Fraction lhs(-1, 2), rhs(1, 5);
    Fraction expected(-1, 10);
    Number& actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication10) {
    Fraction lhs(-1, 2), rhs(1, 5);
    Fraction expected(-5, 2);
    Number& actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication11) {
    Fraction lhs(2, 3), rhs(1, 3);
    Fraction expected(2, 1);
    Number& actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication12) {
    Fraction lhs(2, 3), rhs(-1, 3);
    Fraction expected(-2, 1);
    Number& actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication13) {
    Fraction lhs(-2, 3), rhs(1, 3);
    Fraction expected(-2, 1);
    Number& actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication14) {
    Fraction lhs(-2, 3), rhs(-1, 3);
    Fraction expected(2, 1);
    Number& actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication15) {
    Fraction lhs(0, 1), rhs(0, 1);
    ASSERT_THROW(lhs / rhs, std::invalid_argument);
}

TEST(FractionTest, TestMultiplication16) {
    Fraction lhs(1, 2), rhs(1, 5);
    Fraction expected(5, 2);
    Number& actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication17) {
    Fraction lhs(1, 2), rhs(-1, 5);
    Fraction expected(-5, 2);
    Number& actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(FractionTest, TestMultiplication18) {
    Fraction lhs(-1, 2), rhs(-1, 5);
    Fraction expected(5, 2);
    Number& actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}
