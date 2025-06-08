#include <gtest/gtest.h>
#include <concrete/RegexDecimalStringParser.hpp>

using namespace sdkmath::prealgebra;

concrete::RegexDecimalStringParser u;

TEST(TestRegexDecimalStringParser, ValidateFullMatch00) {
    ASSERT_NO_THROW(u.validateFullMatch("0.0"));
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch01) {
    ASSERT_NO_THROW(u.validateFullMatch("-0.0"));
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch02) {
    ASSERT_NO_THROW(u.validateFullMatch("0."));
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch03) {
    ASSERT_NO_THROW(u.validateFullMatch(".0"));
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch04) {
    ASSERT_NO_THROW(u.validateFullMatch("."));
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch05) {
    ASSERT_NO_THROW(u.validateFullMatch("0"));
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch06) {
    ASSERT_NO_THROW(u.validateFullMatch("879453.12879"));
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch07) {
    ASSERT_THROW(u.validateFullMatch("--0.0"), std::invalid_argument);
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch08) {
    ASSERT_THROW(u.validateFullMatch("-0.0.0"), std::invalid_argument);
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch09) {
    ASSERT_THROW(u.validateFullMatch("0.-0"), std::invalid_argument);
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch10) {
    ASSERT_THROW(u.validateFullMatch("0.0-"), std::invalid_argument);
}

TEST(TestRegexDecimalStringParser, ValidateFullMatch11) {
    ASSERT_THROW(u.validateFullMatch("--0.0"), std::invalid_argument);
}

TEST(TestRegexDecimalStringParser, ValidatePartialMatch00) {
    ASSERT_NO_THROW(u.validatePartialMatch("0.0"));
}

TEST(TestRegexDecimalStringParser, ValidatePartialMatch01) {
    ASSERT_NO_THROW(u.validatePartialMatch("-0.0"));
}

TEST(TestRegexDecimalStringParser, ValidatePartialMatch02) {
    ASSERT_NO_THROW(u.validatePartialMatch("0."));
}

TEST(TestRegexDecimalStringParser, ValidatePartialMatch03) {
    ASSERT_NO_THROW(u.validatePartialMatch(".0"));
}

TEST(TestRegexDecimalStringParser, ValidatePartialMatch04) {
    ASSERT_NO_THROW(u.validatePartialMatch("0"));
}

TEST(TestRegexDecimalStringParser, ValidatePartialMatch05) {
    ASSERT_NO_THROW(u.validatePartialMatch("879453.12879"));
}

TEST(TestRegexDecimalStringParser, ValidatePartialMatch06) {
    ASSERT_THROW(u.validatePartialMatch("."), std::invalid_argument);
}

TEST(TestRegexDecimalStringParser, IsNegative01) {
    ASSERT_FALSE(u.isNegative("0"));
}

TEST(TestRegexDecimalStringParser, IsNegative02) {
    ASSERT_TRUE(u.isNegative("-0"));
}

TEST(TestRegexDecimalStringParser, IsNegative03) {
    ASSERT_FALSE(u.isNegative("0.0"));
}

TEST(TestRegexDecimalStringParser, IsNegative04) {
    ASSERT_TRUE(u.isNegative("-0.0"));
}

TEST(TestRegexDecimalStringParser, IsNegative05) {
    ASSERT_FALSE(u.isNegative(".0"));
}

TEST(TestRegexDecimalStringParser, IsNegative06) {
    ASSERT_TRUE(u.isNegative("-.0"));
}

TEST(TestRegexDecimalStringParser, IsNegative07) {
    ASSERT_FALSE(u.isNegative("44289.59"));
}

TEST(TestRegexDecimalStringParser, IsNegative08) {
    ASSERT_TRUE(u.isNegative("-44289.59"));
}

TEST(TestRegexDecimalStringParser, IsNegative09) {
    ASSERT_FALSE(u.isNegative("+44289.59"));
}

TEST(TestRegexDecimalStringParser, MatchPrefix01) {
    ASSERT_EQ("0", u.matchPrefix("0.0"));
}

TEST(TestRegexDecimalStringParser, MatchPrefix02) {
    ASSERT_EQ("0", u.matchPrefix(".0"));
}

TEST(TestRegexDecimalStringParser, MatchPrefix03) {
    ASSERT_EQ("0", u.matchPrefix("0."));
}

TEST(TestRegexDecimalStringParser, MatchPrefix04) {
    ASSERT_EQ("0", u.matchPrefix("0"));
}

TEST(TestRegexDecimalStringParser, MatchPrefix05) {
    ASSERT_EQ("4532", u.matchPrefix("4532.478"));
}

TEST(TestRegexDecimalStringParser, MatchPrefix06) {
    ASSERT_EQ("0", u.matchPrefix("-0.0"));
}

TEST(TestRegexDecimalStringParser, MatchPrefix07) {
    ASSERT_EQ("0", u.matchPrefix("-.0"));
}

TEST(TestRegexDecimalStringParser, MatchPrefix08) {
    ASSERT_EQ("0", u.matchPrefix("-0."));
}

TEST(TestRegexDecimalStringParser, MatchPrefix09) {
    ASSERT_EQ("0", u.matchPrefix("-0"));
}

TEST(TestRegexDecimalStringParser, MatchPrefix10) {
    ASSERT_EQ("4532", u.matchPrefix("-4532.478"));
}

TEST(TestRegexDecimalStringParser, MatchPrefix11) {
    ASSERT_EQ("4532", u.matchPrefix("+4532.478"));
}

TEST(TestRegexDecimalStringParser, MatchSuffix01) {
    ASSERT_EQ("0", u.matchSuffix("0.0"));
}

TEST(TestRegexDecimalStringParser, MatchSuffix02) {
    ASSERT_EQ("0", u.matchSuffix(".0"));
}

TEST(TestRegexDecimalStringParser, MatchSuffix03) {
    ASSERT_EQ("0", u.matchSuffix("0."));
}

TEST(TestRegexDecimalStringParser, MatchSuffix04) {
    ASSERT_EQ("0", u.matchSuffix("0"));
}

TEST(TestRegexDecimalStringParser, MatchSuffix05) {
    ASSERT_EQ("478", u.matchSuffix("4532.478"));
}

TEST(TestRegexDecimalStringParser, MatchSuffix06) {
    ASSERT_EQ("0", u.matchSuffix("-0.0"));
}

TEST(TestRegexDecimalStringParser, MatchSuffix07) {
    ASSERT_EQ("0", u.matchSuffix("-.0"));
}

TEST(TestRegexDecimalStringParser, MatchSuffix08) {
    ASSERT_EQ("0", u.matchSuffix("-0."));
}

TEST(TestRegexDecimalStringParser, MatchSuffix09) {
    ASSERT_EQ("0", u.matchSuffix("-0"));
}

TEST(TestRegexDecimalStringParser, MatchSuffix10) {
    ASSERT_EQ("478", u.matchSuffix("-4532.478"));
}

TEST(TestRegexDecimalStringParser, MatchSuffix11) {
    ASSERT_EQ("478", u.matchSuffix("+4532.478"));
}

TEST(TestRegexDecimalStringParser, TestFromString1) {
    auto v = u.fromString("4532.408");
    std::map<int, long> expected = {
        {3, 4},
        {2, 5},
        {1, 3},
        {0, 2},
        {-1, 4},
        {-3, 8}
    };
    std::map<int, long> actual;
    for (auto pair : v) {
        actual[pair.first] = pair.second;
    }

    for (auto pair : expected) {
        ASSERT_EQ(1, actual.count(pair.first));
        ASSERT_EQ(pair.second, actual[pair.first]);
    }
    ASSERT_EQ(expected.size(), actual.size());
}

TEST(TestRegexDecimalStringParser, TestFromString2) {
    auto v = u.fromString("-4532.408");
    std::map<int, long> expected = {
        {3, -4},
        {2, -5},
        {1, -3},
        {0, -2},
        {-1, -4},
        {-3, -8}
    };
    std::map<int, long> actual;
    for (auto pair : v) {
        actual[pair.first] = pair.second;
    }

    for (auto pair : expected) {
        ASSERT_EQ(1, actual.count(pair.first));
        ASSERT_EQ(pair.second, actual[pair.first]);
    }
    ASSERT_EQ(expected.size(), actual.size());
}

TEST(TestRegexDecimalStringParser, TestFromString3) {
    auto v = u.fromString("+4532.408");
    std::map<int, long> expected = {
        {3, 4},
        {2, 5},
        {1, 3},
        {0, 2},
        {-1, 4},
        {-3, 8}
    };
    std::map<int, long> actual;
    for (auto pair : v) {
        actual[pair.first] = pair.second;
    }

    for (auto pair : expected) {
        ASSERT_EQ(1, actual.count(pair.first));
        ASSERT_EQ(pair.second, actual[pair.first]);
    }
    ASSERT_EQ(expected.size(), actual.size());
}
