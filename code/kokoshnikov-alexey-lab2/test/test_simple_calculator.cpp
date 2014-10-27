// Copyright 2014 Alexey Kokoshnikov

#include <gtest/gtest.h>

#include <limits.h>
#include <string>

#include "include/simplecalculator.h"

class CalculatorTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    SimpleCalculator calc;
};

/*TEST_F(CalculatorTest, Can_Add) {
    EXPECT_EQ(2 + 2, calc.Add(2, 2));
}

TEST_F(CalculatorTest, Do_Throw_Exception_When_Sum_Is_Larger_Than_INT_MAX) {
    EXPECT_THROW(calc.Add(INT_MAX, INT_MAX), std::string);
}
*/
