#include <gtest/gtest.h>
#include "sumofn/sumofn.h"

TEST(SumOfN_RecursiveTest, RecursiveBaseCase) {
    EXPECT_EQ(sumOfN_Recursive(0), 0);
}

TEST(SumOfN_RecursiveTest, RecursiveTypicalCase) {
    EXPECT_EQ(sumOfN_Recursive(5), 15);
    EXPECT_EQ(sumOfN_Recursive(10), 55);
}

TEST(SumOfN_RecursiveTest, RecursiveEdgeCase) {
    EXPECT_EQ(sumOfN_Recursive(1), 1);
    EXPECT_EQ(sumOfN_Recursive(100), 5050);
}

TEST(SumOfN_FormulaTest, FormulaBaseCase) {
    EXPECT_EQ(sumOfN_Formula(0), 0);
}

TEST(SumOfN_FormulaTest, FormulaTypicalCase) {
    EXPECT_EQ(sumOfN_Formula(5), 15);
    EXPECT_EQ(sumOfN_Formula(10), 55);
}

TEST(SumOfN_FormulaTest, FormulaEdgeCase) {
    EXPECT_EQ(sumOfN_Formula(1), 1);
    EXPECT_EQ(sumOfN_Formula(100), 5050);
}

TEST(SumOfN_IterativeTest, IterativeBaseCase) {
    EXPECT_EQ(sumOfN_Iterative(0), 0);
}

TEST(SumOfN_IterativeTest, IterativeTypicalCase) {
    EXPECT_EQ(sumOfN_Iterative(5), 15);
    EXPECT_EQ(sumOfN_Iterative(10), 55);
}

TEST(SumOfN_IterativeTest, IterativeEdgeCase) {
    EXPECT_EQ(sumOfN_Iterative(1), 1);
    EXPECT_EQ(sumOfN_Iterative(100), 5050);
}
