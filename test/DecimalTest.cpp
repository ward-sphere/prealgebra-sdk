#include <gtest/gtest.h>
#include <Fraction.hpp>
#include <Decimal.hpp>

using namespace sdkmath::prealgebra;

TEST(DecimalTest, TestEquality1) {
    Decimal lhs(Fraction(6, 10)), rhs("0.6");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality2) {
    Decimal lhs(Fraction(29, 100)), rhs("0.29");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality3) {
    Decimal lhs(Fraction(527, 1000)), rhs("0.527");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality4) {
    Decimal lhs(Fraction(138, 100)), rhs("1.38");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality5) {
    Decimal lhs(Fraction(7, 100000)), rhs("0.00007");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality6) {
    Decimal lhs(Fraction(3, 4)), rhs(".75");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality7) {
    Decimal lhs(Fraction(21, 20)), rhs("1.05");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality8) {
    Decimal lhs(Fraction(1, 8)), rhs(".125");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality9) {
    Decimal lhs(Fraction(3, 200)), rhs(".015");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality10) {
    DecimalContext ctx; ctx.minPlacement = -5;
    Decimal lhs(Fraction(2, 11), ctx), rhs("0.18181");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality11) {
    DecimalContext ctx; ctx.minPlacement = -5;
    Decimal lhs(Fraction(5, 6), ctx), rhs("0.83333");

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality12) {
    Fraction lhs = Decimal("0.2").toFraction(), rhs(1, 5);

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality13) {
    Fraction lhs = Decimal("0.35").toFraction(), rhs(7, 20);

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality14) {
    Fraction lhs = Decimal("0.516").toFraction(), rhs(129, 250);

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality15) {
    Fraction lhs = Decimal("0.74").toFraction(), rhs(37, 50);

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality16) {
    Fraction lhs = Decimal("0.138").toFraction(), rhs(69, 500);

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestEquality17) {
    Fraction lhs = Decimal("0.008").toFraction(), rhs(1, 125);

    ASSERT_EQ(lhs, rhs);
}

TEST(DecimalTest, TestDecimalAddition1) {
    Decimal lhs("3.6"), rhs("2.3");
    Decimal expected("5.9"), actual = lhs + rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalAddition2) {
    Decimal lhs("127.32"), rhs("38.48");
    Decimal expected("88.84"), actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalAddition3) {
    Decimal lhs("5.0006"), rhs("3.1248");
    Decimal expected("1.8758"), actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalAddition4) {
    Decimal lhs("12.000"), rhs("0.057");
    Decimal expected("11.943"), actual = lhs - rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication1) {
    Decimal lhs("0.8"), rhs("0.4");
    Decimal expected("0.32"), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication2) {
    Decimal lhs("0.123"), rhs("0.5");
    Decimal expected("0.0615"), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication3) {
    Decimal lhs("2.56"), rhs("0.003");
    Decimal expected("0.00768"), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication4) {
    Decimal lhs("0.0036"), rhs("0.008");
    Decimal expected("0.0000288"), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication5) {
    Decimal lhs("32.68"), rhs((long) 4);
    Decimal expected("8.17"), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication6) {
    Decimal lhs("16.2"), rhs("0.027");
    Decimal expected("600"), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication7) {
    Decimal lhs("0.04288"), rhs("3.2");
    Decimal expected("0.0134"), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication8) {
    Decimal lhs("3.24"), rhs((long) 10);
    Decimal expected("32.4"), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication9) {
    Decimal lhs("15.6"), rhs((long) 100);
    Decimal expected((long) 1560), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication10) {
    Decimal lhs("0.0026"), rhs((long) 1000);
    Decimal expected("2.6"), actual = lhs * rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication11) {
    Decimal lhs("52.6"), rhs((long) 10);
    Decimal expected("5.26"), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication12) {
    Decimal lhs("0.0038"), rhs((long) 100);
    Decimal expected("0.000038"), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestDecimalMultiplication13) {
    Decimal lhs("5936.2"), rhs((long) 1000);
    Decimal expected("5.9362"), actual = lhs / rhs;

    ASSERT_EQ(expected, actual);
}