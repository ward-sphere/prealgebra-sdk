#include <gtest/gtest.h>
#include <INumberSimplifier.hpp>
#include <BasicNumberSimplifier.hpp>

using namespace sdkmath::prealgebra;

INumberSimplifier& simplifier = *new BasicNumberSimplifier();

TEST(INumberSimplifierTest, TestPrimeFactorization1) {
    Integer input = 12;
    std::vector<Integer> expectedOutput = { 2, 2, 3 };
    std::vector<Integer> actualOutput = simplifier.getPrimeFactors(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberSimplifierTest, TestPrimeFactorization2) {
    Integer input = 14;
    std::vector<Integer> expectedOutput = { 2, 7 };
    std::vector<Integer> actualOutput = simplifier.getPrimeFactors(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberSimplifierTest, TestPrimeFactorization3) {
    Integer input = 19;
    std::vector<Integer> expectedOutput = { 19 };
    std::vector<Integer> actualOutput = simplifier.getPrimeFactors(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberSimplifierTest, TestPrimeFactorization4) {
    Integer input = 29;
    std::vector<Integer> expectedOutput = { 29 };
    std::vector<Integer> actualOutput = simplifier.getPrimeFactors(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberSimplifierTest, TestPrimeFactorization5) {
    Integer input = 30;
    std::vector<Integer> expectedOutput = { 2, 3, 5 };
    std::vector<Integer> actualOutput = simplifier.getPrimeFactors(input);

    ASSERT_EQ(expectedOutput, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction1) {
    Fraction input(14, 21);
    Fraction expectedOutpout(2, 3);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction2) {
    Fraction input(15, 35);
    Fraction expectedOutpout(3, 7);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction3) {
    Fraction input(20, 70);
    Fraction expectedOutpout(2, 7);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction4) {
    Fraction input(7, 21);
    Fraction expectedOutpout(1, 3);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction5) {
    Fraction input(15, 105);
    Fraction expectedOutpout(1, 7);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction6) {
    Fraction input(35, 7);
    Fraction expectedOutpout(5, 1);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}

TEST(INumberSimplifierTest, TestSimplifyFraction7) {
    Fraction input = Fraction(70, 10);
    Fraction expectedOutpout = Fraction(7, 1);
    Fraction actualOutput = simplifier.simplifyFraction(input);

    ASSERT_EQ(expectedOutpout, actualOutput);
}