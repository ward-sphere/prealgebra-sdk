#include <Decimal.hpp>
#include <gtest/gtest.h>

using namespace sdkmath::prealgebra;

TEST(DecimalTest, TestConstructor00) {
    Decimal d("7.6");

    ASSERT_EQ(7, d.getPlaceValueMap()[0]);
    ASSERT_EQ(6, d.getPlaceValueMap()[-1]);
    ASSERT_EQ("7.6", d.toString());
}

TEST(DecimalTest, TestConstructor01) {
    Decimal d("-90.95");

    ASSERT_EQ(-9, d.getPlaceValueMap()[1]);
    ASSERT_EQ(-9, d.getPlaceValueMap()[-1]);
    ASSERT_EQ(-5, d.getPlaceValueMap()[-2]);
    ASSERT_EQ("-90.95", d.toString());
}

TEST(DecimalTest, TestConstructor03) {
    Decimal d("-194.992");

    ASSERT_EQ(-1, d.getPlaceValueMap()[2]);
    ASSERT_EQ(-9, d.getPlaceValueMap()[1]);
    ASSERT_EQ(-4, d.getPlaceValueMap()[0]);
    ASSERT_EQ(-9, d.getPlaceValueMap()[-1]);
    ASSERT_EQ(-9, d.getPlaceValueMap()[-2]);
    ASSERT_EQ(-2, d.getPlaceValueMap()[-3]);
    ASSERT_EQ("-194.992", d.toString());
}

TEST(DecimalTest, TestConstructor04) {
    Decimal d("580");

    ASSERT_EQ(5, d.getPlaceValueMap()[2]);
    ASSERT_EQ(8, d.getPlaceValueMap()[1]);
    ASSERT_EQ("580.0", d.toString());
}

TEST(DecimalTest, TestConstructor05) {
    Decimal d("-913.");

    ASSERT_EQ(-9, d.getPlaceValueMap()[2]);
    ASSERT_EQ(-1, d.getPlaceValueMap()[1]);
    ASSERT_EQ(-3, d.getPlaceValueMap()[0]);
    ASSERT_EQ("-913.0", d.toString());
}

TEST(DecimalTest, TestConstructor06) {
    Decimal d("-132.0");

    ASSERT_EQ(-1, d.getPlaceValueMap()[2]);
    ASSERT_EQ(-3, d.getPlaceValueMap()[1]);
    ASSERT_EQ(-2, d.getPlaceValueMap()[0]);
    ASSERT_EQ("-132.0", d.toString());
}

TEST(DecimalTest, TestConstructor07) {
    Decimal d("0.826");

    ASSERT_EQ(8, d.getPlaceValueMap()[-1]);
    ASSERT_EQ(2, d.getPlaceValueMap()[-2]);
    ASSERT_EQ(6, d.getPlaceValueMap()[-3]);
    ASSERT_EQ("0.826", d.toString());
}

TEST(DecimalTest, TestConstructor08) {
    Decimal d("-.258");

    ASSERT_EQ("-0.258", d.toString());
    ASSERT_EQ(-2, d.getPlaceValueMap()[-1]);
    ASSERT_EQ(-5, d.getPlaceValueMap()[-2]);
    ASSERT_EQ(-8, d.getPlaceValueMap()[-3]);
}

TEST(DecimalTest, TestEquality00) {
    Decimal lhs("2343.36"), rhs("2343.36");
    bool expected = true, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality01) {
    Decimal lhs("-2343.36"), rhs("2343.36");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality02) {
    Decimal lhs("2343.36"), rhs("-2343.36");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality03) {
    Decimal lhs("-2343.36"), rhs("-2343.36");
    bool expected = true, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality04) {
    Decimal lhs("2343.36"), rhs("735.89");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality05) {
    Decimal lhs("-2343.36"), rhs("735.89");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality06) {
    Decimal lhs("2343.36"), rhs("-735.89");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality07) {
    Decimal lhs("-2343.36"), rhs("-735.89");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality08) {
    Decimal lhs("735.89"), rhs("735.89");
    bool expected = true, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality09) {
    Decimal lhs("-735.89"), rhs("735.89");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality10) {
    Decimal lhs("735.89"), rhs("-735.89");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality11) {
    Decimal lhs("-735.89"), rhs("-735.89");
    bool expected = true, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality12) {
    Decimal lhs("735.89"), rhs("0");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality13) {
    Decimal lhs("-735.89"), rhs("0");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality14) {
    Decimal lhs("0"), rhs("0");
    bool expected = true, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality15) {
    Decimal lhs("0"), rhs("-735.89");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality16) {
    Decimal lhs("0"), rhs("735.89");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality17) {
    Decimal lhs("5164.21"), rhs("5164.2");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality18) {
    Decimal lhs("5164.2"), rhs("5164.21");
    bool expected = false, actual = lhs == rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality19) {
    Decimal lhs("2343.36"), rhs("2343.36");
    bool expected = false, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality20) {
    Decimal lhs("-2343.36"), rhs("2343.36");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality21) {
    Decimal lhs("2343.36"), rhs("-2343.36");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality22) {
    Decimal lhs("-2343.36"), rhs("-2343.36");
    bool expected = false, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality23) {
    Decimal lhs("2343.36"), rhs("735.89");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality24) {
    Decimal lhs("-2343.36"), rhs("735.89");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality25) {
    Decimal lhs("2343.36"), rhs("-735.89");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality26) {
    Decimal lhs("-2343.36"), rhs("-735.89");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality27) {
    Decimal lhs("735.89"), rhs("735.89");
    bool expected = false, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality28) {
    Decimal lhs("-735.89"), rhs("735.89");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality29) {
    Decimal lhs("735.89"), rhs("-735.89");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality30) {
    Decimal lhs("-735.89"), rhs("-735.89");
    bool expected = false, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality31) {
    Decimal lhs("735.89"), rhs("0");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality32) {
    Decimal lhs("-735.89"), rhs("0");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality33) {
    Decimal lhs("0"), rhs("0");
    bool expected = false, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality34) {
    Decimal lhs("0"), rhs("-735.89");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality35) {
    Decimal lhs("0"), rhs("735.89");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality36) {
    Decimal lhs("5164.21"), rhs("5164.2");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestEquality37) {
    Decimal lhs("5164.2"), rhs("5164.21");
    bool expected = true, actual = lhs != rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality00) {
    Decimal lhs("209.38"), rhs("8267.30");
    bool expected = true, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality01) {
    Decimal lhs("209.38"), rhs("-8267.30");
    bool expected = false, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality02) {
    Decimal lhs("-209.38"), rhs("-8267.30");
    bool expected = false, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality03) {
    Decimal lhs("-209.38"), rhs("8267.30");
    bool expected = true, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality04) {
    Decimal lhs("209.38"), rhs("8267.30");
    bool expected = false, actual = rhs < lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality05) {
    Decimal lhs("209.38"), rhs("-8267.30");
    bool expected = true, actual = rhs < lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality06) {
    Decimal lhs("-209.38"), rhs("-8267.30");
    bool expected = true, actual = rhs < lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality07) {
    Decimal lhs("-209.38"), rhs("8267.30");
    bool expected = false, actual = rhs < lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality08) {
    Decimal lhs("7206.5"), rhs("7206.55");
    bool expected = true, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality09) {
    Decimal lhs("7206.55"), rhs("7206.5");
    bool expected = false, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality10) {
    Decimal lhs("5106.5"), rhs("5106.5");
    bool expected = false, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality11) {
    Decimal lhs("209.38"), rhs("8267.30");
    bool expected = false, actual = lhs >= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality12) {
    Decimal lhs("209.38"), rhs("-8267.30");
    bool expected = true, actual = lhs >= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality13) {
    Decimal lhs("-209.38"), rhs("-8267.30");
    bool expected = true, actual = lhs >= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality14) {
    Decimal lhs("-209.38"), rhs("8267.30");
    bool expected = false, actual = lhs >= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality15) {
    Decimal lhs("209.38"), rhs("8267.30");
    bool expected = true, actual = rhs >= lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality16) {
    Decimal lhs("209.38"), rhs("-8267.30");
    bool expected = false, actual = rhs >= lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality17) {
    Decimal lhs("-209.38"), rhs("-8267.30");
    bool expected = false, actual = rhs >= lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality18) {
    Decimal lhs("-209.38"), rhs("8267.30");
    bool expected = true, actual = rhs >= lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality19) {
    Decimal lhs("7206.5"), rhs("7206.55");
    bool expected = true, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality20) {
    Decimal lhs("7206.55"), rhs("7206.5");
    bool expected = false, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality21) {
    Decimal lhs("5106.5"), rhs("5106.5");
    bool expected = true, actual = lhs >= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality22) {
    Decimal lhs("209.38"), rhs("8267.30");
    bool expected = false, actual = lhs > rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality23) {
    Decimal lhs("209.38"), rhs("-8267.30");
    bool expected = true, actual = lhs > rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality24) {
    Decimal lhs("-209.38"), rhs("-8267.30");
    bool expected = true, actual = lhs > rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality25) {
    Decimal lhs("-209.38"), rhs("8267.30");
    bool expected = false, actual = lhs > rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality26) {
    Decimal lhs("209.38"), rhs("8267.30");
    bool expected = true, actual = rhs > lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality27) {
    Decimal lhs("209.38"), rhs("-8267.30");
    bool expected = false, actual = rhs > lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality28) {
    Decimal lhs("-209.38"), rhs("-8267.30");
    bool expected = false, actual = rhs > lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality29) {
    Decimal lhs("-209.38"), rhs("8267.30");
    bool expected = true, actual = rhs > lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality30) {
    Decimal lhs("7206.5"), rhs("7206.55");
    bool expected = true, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality31) {
    Decimal lhs("7206.55"), rhs("7206.5");
    bool expected = false, actual = lhs < rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality32) {
    Decimal lhs("5106.5"), rhs("5106.5");
    bool expected = false, actual = lhs > rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality33) {
    Decimal lhs("209.38"), rhs("8267.30");
    bool expected = true, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality34) {
    Decimal lhs("209.38"), rhs("-8267.30");
    bool expected = false, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality35) {
    Decimal lhs("-209.38"), rhs("-8267.30");
    bool expected = false, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality36) {
    Decimal lhs("-209.38"), rhs("8267.30");
    bool expected = true, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality37) {
    Decimal lhs("209.38"), rhs("8267.30");
    bool expected = false, actual = rhs <= lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality38) {
    Decimal lhs("209.38"), rhs("-8267.30");
    bool expected = true, actual = rhs <= lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality39) {
    Decimal lhs("-209.38"), rhs("-8267.30");
    bool expected = true, actual = rhs <= lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality40) {
    Decimal lhs("-209.38"), rhs("8267.30");
    bool expected = false, actual = rhs <= lhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality41) {
    Decimal lhs("7206.5"), rhs("7206.55");
    bool expected = true, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality42) {
    Decimal lhs("7206.55"), rhs("7206.5");
    bool expected = false, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestInequality43) {
    Decimal lhs("5106.5"), rhs("5106.5");
    bool expected = true, actual = lhs <= rhs;

    ASSERT_EQ(expected, actual);
}

TEST(DecimalTest, TestAddition00) {
    Decimal lhs("839.4"), rhs("866.29");
    Decimal expected("1705.69");
    std::unique_ptr<Number> actual = lhs + rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition01) {
    Decimal lhs("839.4"), rhs("-866.29");
    Decimal expected("-26.89");
    std::unique_ptr<Number> actual = lhs + rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition02) {
    Decimal lhs("-839.4"), rhs("-866.29");
    Decimal expected("-1705.69");
    std::unique_ptr<Number> actual = lhs + rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition03) {
    Decimal lhs("-839.4"), rhs("866.29");
    Decimal expected("26.89");
    std::unique_ptr<Number> actual = lhs + rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition04) {
    Decimal lhs("-839.4"), rhs("0");
    Decimal expected = lhs;
    std::unique_ptr<Number> actual = lhs + rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition05) {
    Decimal lhs("-839.4"), rhs("0");
    Decimal expected = lhs;
    std::unique_ptr<Number> actual = lhs + rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition06) {
    Decimal lhs("839.4"), rhs("866.29");
    Decimal expected("-26.89");
    std::unique_ptr<Number> actual = lhs - rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition07) {
    Decimal lhs("839.4"), rhs("-866.29");
    Decimal expected("1705.69");
    std::unique_ptr<Number> actual = lhs - rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition08) {
    Decimal lhs("-839.4"), rhs("-866.29");
    Decimal expected("26.89");
    std::unique_ptr<Number> actual = lhs - rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition09) {
    Decimal lhs("-839.4"), rhs("866.29");
    Decimal expected("-1705.69");
    std::unique_ptr<Number> actual = lhs - rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition10) {
    Decimal lhs("-839.4"), rhs("0");
    Decimal expected = lhs;
    std::unique_ptr<Number> actual = lhs - rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestAddition11) {
    Decimal lhs("-839.4"), rhs("0");
    Decimal expected("839.4");
    std::unique_ptr<Number> actual = rhs - lhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication00) {
    Decimal lhs("839.4"), rhs("866.29");
    Decimal expected("727163.826");
    std::unique_ptr<Number> actual = lhs * rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication01) {
    Decimal lhs("839.4"), rhs("-866.29");
    Decimal expected("-727163.826");
    std::unique_ptr<Number> actual = lhs * rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication02) {
    Decimal lhs("-839.4"), rhs("-866.29");
    Decimal expected("727163.826");
    std::unique_ptr<Number> actual = lhs * rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication03) {
    Decimal lhs("-839.4"), rhs("866.29");
    Decimal expected("-727163.826");
    std::unique_ptr<Number> actual = lhs * rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication04) {
    Decimal lhs("-839.4"), rhs("1");
    Decimal expected = lhs;
    std::unique_ptr<Number> actual = lhs * rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication05) {
    Decimal lhs("-839.4"), rhs("1");
    Decimal expected = lhs;
    std::unique_ptr<Number> actual = lhs * rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication06) {
    Decimal lhs("375.68"), rhs("117.4");
    Decimal expected("3.2");
    std::unique_ptr<Number> actual = lhs / rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication07) {
    Decimal lhs("375.68"), rhs("-117.4");
    Decimal expected("-3.2");
    std::unique_ptr<Number> actual = lhs / rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication08) {
    Decimal lhs("-375.68"), rhs("-117.4");
    Decimal expected("3.2");
    std::unique_ptr<Number> actual = lhs / rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication09) {
    Decimal lhs("-375.68"), rhs("117.4");
    Decimal expected("-3.2");
    std::unique_ptr<Number> actual = lhs / rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication10) {
    Decimal lhs("375.68"), rhs("1");
    Decimal expected = lhs;
    std::unique_ptr<Number> actual = lhs / rhs;

    ASSERT_EQ(expected, *actual);
}

TEST(DecimalTest, TestMultiplication11) {
    Decimal lhs("375.68"), rhs("0");
    ASSERT_THROW(lhs / rhs, std::invalid_argument);
}