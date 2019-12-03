//
// Created by 方泓睿 on 2019/12/3.
//

#include <calculator.h>

#include <iostream>

auto EvaluateAndShow(calculator::Engine &engine, const std::string &expression) -> void {
	std::cout << expression << "=" << engine.Evaluate(expression) << std::endl;
}

auto main() -> int {
	EvaluateAndShow(calculator::Instance, "1+1");
	EvaluateAndShow(calculator::Instance, "1*3+2");
	EvaluateAndShow(calculator::Instance, "0+9/3");
	EvaluateAndShow(calculator::Instance, "(1+3)/2");
	EvaluateAndShow(calculator::Instance, "abs(-1.12334)");
	EvaluateAndShow(calculator::Instance, "1.45*44%3");
	EvaluateAndShow(calculator::Instance, "(1+4)/cos(3.1415926)");
	EvaluateAndShow(calculator::Instance, "@+1");
	EvaluateAndShow(calculator::Instance, "@@+1");
	EvaluateAndShow(calculator::Instance, "acos(1)*@");
	return EXIT_SUCCESS;
}