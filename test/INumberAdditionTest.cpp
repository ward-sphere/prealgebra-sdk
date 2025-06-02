#include <gtest/gtest.h>
#include <Integer.hpp>
#include <Fraction.hpp>
#include <MixedNumber.hpp>
#include <BasicNumberTranslator.hpp>
#include <BasicNumberAddition.hpp>

using namespace sdkmath::prealgebra;

INumberTranslator& translator = *new BasicNumberTranslator();
INumberAddition& adder = *new BasicNumberAddition(translator);

size_t ITERATION_COUNT = 100;

TEST(INumberAdditionTest, TestAddInteger) {
    size_t iterations = ITERATION_COUNT;
    while (iterations > 0) {
        long lhs = rand() % 1000 - 500,
            rhs = rand() % 1000 - 500,
            sum = lhs + rhs;
        ASSERT_EQ(
            Integer(sum),
            adder.add(Integer(lhs), Integer(rhs))
        );
        iterations -= 1;
    }
}

TEST(INumberAdditionTest, TestSubtractInteger) {
    size_t iterations = ITERATION_COUNT;
    while (iterations > 0) {
        long lhs = rand() % 1000 - 500,
            rhs = rand() % 1000 - 500,
            difference = lhs - rhs;
        ASSERT_EQ(
            Integer(difference),
            adder.subtract(Integer(lhs), Integer(rhs))
        );
        iterations -= 1;
    }
}

TEST(INumberAdditionTest, TestAddFraction_Happy) {
    size_t iterations = ITERATION_COUNT;
    while (iterations > 0) {
        long lhs = rand() % 1000 - 500,
            rhs = rand() % 1000 - 500,
            denominator = rand() % 1000 + 1;
        ASSERT_EQ(
            Fraction(lhs + rhs, denominator),
            adder.add(
                Fraction(lhs, denominator),
                Fraction(rhs, denominator)
            )
        );
        iterations -= 1;
    }
}

TEST(INumberAdditionTest, TestSubtractFraction_Happy) {
    size_t iterations = ITERATION_COUNT;
    while (iterations > 0) {
        long lhs = rand() % 1000 - 500,
            rhs = rand() % 1000 - 500,
            denominator = rand() % 1000 + 1;
        ASSERT_EQ(
            Fraction(lhs - rhs, denominator),
            adder.subtract(
                Fraction(lhs, denominator),
                Fraction(rhs, denominator)
            )
        );
        iterations -= 1;
    }
}