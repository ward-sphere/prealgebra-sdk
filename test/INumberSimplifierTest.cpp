#include <gtest/gtest.h>
#include <INumberSimplifier.hpp>
#include <BasicNumberSimplifier.hpp>

using namespace sdkmath::prealgebra;

INumberSimplifier& simplifier = *new BasicNumberSimplifier();

TEST(INumberSimplifierTest, TestPrimeFactorization1) {
    Integer input = Integer(12);
    std::vector<Integer> expectedOutput = { Integer(2), Integer(2), Integer(3) };
    std::vector<Integer> actualOutput = simplifier.getPrimeFactors(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberSimplifierTest, TestPrimeFactorization2) {
    Integer input = Integer(14);
    std::vector<Integer> expectedOutput = { Integer(2), Integer(7) };
    std::vector<Integer> actualOutput = simplifier.getPrimeFactors(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberSimplifierTest, TestPrimeFactorization3) {
    Integer input = Integer(19);
    std::vector<Integer> expectedOutput = { Integer(19) };
    std::vector<Integer> actualOutput = simplifier.getPrimeFactors(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberSimplifierTest, TestPrimeFactorization4) {
    Integer input = Integer(29);
    std::vector<Integer> expectedOutput = { Integer(29) };
    std::vector<Integer> actualOutput = simplifier.getPrimeFactors(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberSimplifierTest, TestPrimeFactorization5) {
    Integer input = Integer(30);
    std::vector<Integer> expectedOutput = { Integer(2), Integer(3), Integer(5) };
    std::vector<Integer> actualOutput = simplifier.getPrimeFactors(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction1) {
    Fraction input = Fraction(14, 21);
    Fraction expectedOutpout = Fraction(2, 3);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction2) {
    Fraction input = Fraction(15, 35);
    Fraction expectedOutpout = Fraction(3, 7);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction3) {
    Fraction input = Fraction(20, 70);
    Fraction expectedOutpout = Fraction(2, 7);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction4) {
    Fraction input = Fraction(7, 21);
    Fraction expectedOutpout = Fraction(1, 3);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction5) {
    Fraction input = Fraction(15, 105);
    Fraction expectedOutpout = Fraction(1, 7);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction6) {
    Fraction input = Fraction(35, 7);
    Fraction expectedOutpout = Fraction(5, 1);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction7) {
    Fraction input = Fraction(70, 10);
    Fraction expectedOutpout = Fraction(7, 1);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}