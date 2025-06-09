#include <gtest/gtest.h>
#include <Integer.hpp>

#include <limits>

using namespace sdkmath::prealgebra;

TEST(IntegerTest, TestConstructor1) {
    Integer i(0);
    long expected = 0, actual = i.getValue();

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestConstructor2) {
    Integer i(std::numeric_limits<long>::min());
    long expected = std::numeric_limits<long>::min(), actual = i.getValue();

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestConstructor3) {
    Integer i(std::numeric_limits<long>::max());
    long expected = std::numeric_limits<long>::max(), actual = i.getValue();

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestConstructor4) {
    Integer i(-50000000);
    long expected = -50000000, actual = i.getValue();

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestConstructor5) {
    Integer i(50000000);
    long expected = 50000000, actual = i.getValue();

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestEquality1) {
    Integer i1(0), i2(0);
    bool expected = true, actual = i1 == i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestEquality2) {
    Integer i1(0), i2(0);
    bool expected = false, actual = i1 != i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestEquality3) {
    Integer i1(-5000), i2(5000);
    bool expected = false, actual = i1 == i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestEquality4) {
    Integer i1(-5000), i2(5000);
    bool expected = true, actual = i1 != i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality1) {
    Integer i1(0), i2(0);
    bool expected = false, actual = i1 < i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality2) {
    Integer i1(0), i2(0);
    bool expected = false, actual = i1 > i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality3) {
    Integer i1(0), i2(0);
    bool expected = true, actual = i1 <= i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality4) {
    Integer i1(0), i2(0);
    bool expected = true, actual = i1 >= i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality5) {
    Integer i1(-5000), i2(5000);
    bool expected = true, actual = i1 < i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality6) {
    Integer i1(-5000), i2(5000);
    bool expected = false, actual = i1 > i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality7) {
    Integer i1(-5000), i2(5000);
    bool expected = true, actual = i1 <= i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality8) {
    Integer i1(-5000), i2(5000);
    bool expected = false, actual = i1 >= i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality9) {
    Integer i1(5000), i2(-5000);
    bool expected = false, actual = i1 < i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality10) {
    Integer i1(5000), i2(-5000);
    bool expected = true, actual = i1 > i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality11) {
    Integer i1(5000), i2(-5000);
    bool expected = false, actual = i1 <= i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestInequality12) {
    Integer i1(5000), i2(-5000);
    bool expected = true, actual = i1 >= i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestAddition1) {
    Integer i1(0), i2(0);
    Integer expected(0);
    Number& actual = i1 + i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestAddition2) {
    Integer i1(-5000), i2(5000);
    Integer expected(0);
    Number& actual = i1 + i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestAddition3) {
    Integer i1(5000), i2(-5000);
    Integer expected(0);
    Number& actual = i1 + i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestAddition4) {
    Integer i1(5000), i2(5000);
    Integer expected(10000);
    Number& actual = i1 + i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestAddition5) {
    Integer i1(-5000), i2(-5000);
    Integer expected(-10000);
    Number& actual = i1 + i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestSubtraction1) {
    Integer i1(0), i2(0);
    Integer expected(0);
    Number& actual = i1 - i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestSubtraction2) {
    Integer i1(-5000), i2(5000);
    Integer expected(-10000);
    Number& actual = i1 - i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestSubtraction3) {
    Integer i1(5000), i2(-5000);
    Integer expected(10000);
    Number& actual = i1 - i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestSubtraction4) {
    Integer i1(5000), i2(5000);
    Integer expected(0);
    Number& actual = i1 - i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestSubtraction5) {
    Integer i1(-5000), i2(-5000);
    Integer expected(0);
    Number& actual = i1 - i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestMultiplication1) {
    Integer i1(0), i2(0);
    Integer expected(0);
    Number& actual = i1 * i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestMultiplication2) {
    Integer i1(-50), i2(50);
    Integer expected(-2500);
    Number& actual = i1 * i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestMultiplication3) {
    Integer i1(50), i2(-50);
    Integer expected(-2500);
    Number& actual = i1 * i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestMultiplication4) {
    Integer i1(50), i2(50);
    Integer expected(2500);
    Number& actual = i1 * i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestMultiplication5) {
    Integer i1(-50), i2(-50);
    Integer expected(2500);
    Number& actual = i1 * i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestDivision1) {
    Integer i1(0), i2(0);
    ASSERT_THROW(i1 / i2, std::invalid_argument);
}

TEST(IntegerTest, TestDivision2) {
    Integer i1(-50), i2(50);
    Integer expected(-1);
    Number& actual = i1 / i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestDivision3) {
    Integer i1(50), i2(-50);
    Integer expected(-1);
    Number& actual = i1 / i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestDivision4) {
    Integer i1(50), i2(50);
    Integer expected(1);
    Number& actual = i1 / i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestDivision5) {
    Integer i1(-50), i2(-50);
    Integer expected(1);
    Number& actual = i1 / i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestDivision6) {
    Integer i1(-2500), i2(50);
    Integer expected(-50);
    Number& actual = i1 / i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestDivision7) {
    Integer i1(2500), i2(-50);
    Integer expected(-50);
    Number& actual = i1 / i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestDivision8) {
    Integer i1(2500), i2(50);
    Integer expected(50);
    Number& actual = i1 / i2;

    ASSERT_EQ(expected, actual);
}

TEST(IntegerTest, TestDivision9) {
    Integer i1(-2500), i2(-50);
    Integer expected(50);
    Number& actual = i1 / i2;

    ASSERT_EQ(expected, actual);
}
