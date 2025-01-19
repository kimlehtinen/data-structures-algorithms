#include <gtest/gtest.h>
#include "parenthesesmatching/parentheses_matching.h"


TEST(ParenthesesMatchingTest, CanCheckIfParenthesesAreBalancedWhenTheyAre) {
    char expression[] = "((a+b)*(c-d))";
    EXPECT_EQ(AreParenthesesBalanced(expression), true);
}

TEST(ParenthesesMatchingTest, CanCheckIfParenthesesAreBalancedWhenMissingOpeningParentheses) {
    char expression[] = "(a+b)*(c-d))";
    EXPECT_EQ(AreParenthesesBalanced(expression), false);
}

TEST(ParenthesesMatchingTest, CanCheckIfParenthesesAreBalancedWhenMissingClosingParentheses) {
    char expression[] = "((a+b)*(c-d)";
    EXPECT_EQ(AreParenthesesBalanced(expression), false);
}

TEST(ParenthesesMatchingTest, CanCheckIfParenthesesAreBalancedWhenThereAreNoParentheses) {
    char expression[] = "a+b*c-d";
    EXPECT_EQ(AreParenthesesBalanced(expression), true);
}

TEST(ParenthesesMatchingTest, CanCheckIfParenthesesAreBalancedWhenExpressionIsNull) {
    char* expression = nullptr;
    EXPECT_EQ(AreParenthesesBalanced(expression), false);
}

TEST(ParenthesesMatchingTest, CanCheckIfParenthesesAreBalancedWhenExpressionIsEmpty) {
    char expression[] = "";
    EXPECT_EQ(AreParenthesesBalanced(expression), true);
}

TEST(ParenthesesMatchingTest, CanCheckIfParenthesesAreBalancedWhenExpressionHasOnlyOpeningParentheses) {
    char expression[] = "(((";
    EXPECT_EQ(AreParenthesesBalanced(expression), false);
}

TEST(ParenthesesMatchingTest, CanCheckIfParenthesesAreBalancedWhenExpressionHasOnlyClosingParentheses) {
    char expression[] = ")))";
    EXPECT_EQ(AreParenthesesBalanced(expression), false);
}

TEST(ParenthesesMatchingTest, CanCheckIfParenthesesAreBalancedWhenExpressionHasOpeningAndClosingParentheses) {
    char expression[] = "(()";
    EXPECT_EQ(AreParenthesesBalanced(expression), false);
}

TEST(ParenthesesMatchingTest, CanCheckIfParenthesesAreBalancedWhenExpressionHasClosingAndOpeningParentheses) {
    char expression[] = ")(";
    EXPECT_EQ(AreParenthesesBalanced(expression), false);
}
