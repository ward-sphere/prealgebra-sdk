#include <concrete/BasicFractionSimplification.hpp>
#include <gtest/gtest.h>

using namespace sdkmath::prealgebra::concrete;

BasicFractionSimplification s;

TEST(BasicFractionSimplificationTest, TestPrimeFactorization01) {
    long input = 2;
    std::vector<long> expected = { 2 }; 
    std::vector<long> actual = s.primeFactorization(input);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestPrimeFactorization02) {
    long input = 7;
    std::vector<long> expected = { 7 };
    std::vector<long> actual = s.primeFactorization(input);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestPrimeFactorization03) {
    long input = 30;
    std::vector<long> expected = { 2, 3, 5 };
    std::vector<long> actual = s.primeFactorization(input);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestPrimeFactorization04) {
    long input = -2;
    std::vector<long> expected = { 2 };
    std::vector<long> actual = s.primeFactorization(input);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestPrimeFactorization05) {
    long input = -7;
    std::vector<long> expected = { 7 };
    std::vector<long> actual = s.primeFactorization(input);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestPrimeFactorization06) {
    long input = -30;
    std::vector<long> expected = { 2, 3, 5 };
    std::vector<long> actual = s.primeFactorization(input);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestFindGcd01) {
    long lhs = 30, rhs = 48;
    long expected = 6, actual = s.find_gcd(lhs, rhs);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestFindGcd02) {
    long lhs = 64, rhs = 48;
    long expected = 16, actual = s.find_gcd(lhs, rhs);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestFindGcd03) {
    long lhs = 2, rhs = 7;
    long expected = 1, actual = s.find_gcd(lhs, rhs);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestFindLcm01) {
    long lhs = 10, rhs = 12;
    long expected = 60, actual = s.find_lcm(lhs, rhs);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestFindLcm02) {
    long lhs = 18, rhs = 12;
    long expected = 36, actual = s.find_lcm(lhs, rhs);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestFindLcm03) {
    long lhs = 15, rhs = 20;
    long expected = 60, actual = s.find_lcm(lhs, rhs);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestFindLcm04) {
    long lhs = 4, rhs = 6;
    long expected = 12, actual = s.find_lcm(lhs, rhs);

    ASSERT_EQ(expected, actual);
}

TEST(BasicFractionSimplificationTest, TestFindLcm05) {
    long lhs = 3, rhs = 5;
    long expected = 15, actual = s.find_lcm(lhs, rhs);

    ASSERT_EQ(expected, actual);
}
