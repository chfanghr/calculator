//
// Created by 方泓睿 on 2019/12/3.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <calculator.h>
#include <gtest/gtest.h>

#include <map>
#include <vector>
#include <tuple>

class CalculatorTestGroup : public testing::Test {
 public:
	calculator::Engine engine_;
};

TEST_F(CalculatorTestGroup, EvalateShouldWorkAsExpected) {
	std::map<std::string, double> exps{
			{"1+1", 2},
			{"1+2^3^2", 513,},
			{"2^(3+4)", 128,},
			{"2^(3/(1+2))", 2,},
			{"2(1+3)", 8,},
			{"2^2(1+3)", 16,},
			{"-2", -2,},
			{"1+(-1)^2", 2,},
			{"3-5", -2,},
			{"-3*4", -12,},
			{"3*-4", -12,},
			{"3*(3-(5+6)^12)*23^3-5^23", -126476703133661843,},
			{"2^3^2", 512,},
			{"-3^2", -9,},
			{"2(1+1)4", 16,},
			{"3*abs(1-5)", 12,},
			{"ln(3^15)", 16.47918433,},
			{"sqrt(10)", 3.16227766,},
			{"abs(-3/2)", 1.5,},
			{"1+2sin(-1024)tan(acos(1))^2", 1,},
			{"tan(10)cos(20)", 0.2645844,},
			{"2(e^3)", 40.1710738464,},
	};

	for (const auto &ele:exps)
		ASSERT_NEAR(engine_.Evaluate(std::get<0>(ele)), std::get<1>(ele), 0.000001);
}

TEST_F(CalculatorTestGroup, EngineShouldThrowExceptionWhenExpressionIsInvalid) {
	std::vector<std::vector<std::string>> tests = {
			{"/"},
			{"1/"},
			{"1("},
			{")("},
			{"(()"},
			{"@"},
			{"@@"},
			{"0", "@@"},
			{"0", "@@@"},
			{"@@\xa6"},
	};
	for (const auto                       &test: tests) {
		engine_.Reset();
		ASSERT_ANY_THROW([&]() -> void {
			for (const auto &c:test)
				engine_.Evaluate(c);
		}());
	}
}

#pragma clang diagnostic pop