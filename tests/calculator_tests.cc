//
// Created by 方泓睿 on 2019/12/3.
//

#include <calculator.h>
#include <gtest/gtest.h>

class CalculatorTestGroup : public testing::Test {
 public:
	calculator::Engine engine_;
};

TEST_F(CalculatorTestGroup, PlaceHolder) {}