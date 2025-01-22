#include <gtest/gtest.h>
#include "postfixinfix/postfix_infix.h"

TEST(InfixToPostfixTest, CanConvertInfixToPostfix) {
    char* infix = "a+b*c-d/e";
    
    char* postfix = InfixToPostfix(infix);
    
    EXPECT_STREQ(postfix, "abc*+de/-");
    delete[] postfix;
}

TEST(InfixToPostfixTest, CanConvertInfixToPostfixWithParentheses) {
    char* infix = "((a+b)*c)-d^e^f";
    
    char* postfix = InfixToPostfix(infix);
    
    EXPECT_STREQ(postfix, "ab+c*def^^-");
    delete[] postfix;
}

TEST(EvalTest, CanEvaluateInfix) {
    char* infix = "1+2*3-4/2";
    
    int result = Eval(infix);
    
    EXPECT_EQ(result, 5);
}

TEST(EvalTest, CanEvaluateInfixWithParentheses) {
    char* infix = "((1+2)*3)-4^2";
    
    int result = Eval(infix);
    
    EXPECT_EQ(result, -7);
}
