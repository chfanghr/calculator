//
// Created by 方泓睿 on 2019/12/3.
//

#include <calculator.h>

#include <iostream>

auto EvaluateAndShow(calculator::Engine &engine, const std::string &expression) -> void {
	std::cout << expression << "=" << engine.Evaluate(expression) << std::endl;
}

auto main() -> int {
	calculator::Engine engine;
	EvaluateAndShow(engine, "1+1");
	EvaluateAndShow(engine, "1*3+2");
	EvaluateAndShow(engine, "0+9/3");
	EvaluateAndShow(engine, "(1+3)/2");
	EvaluateAndShow(engine, "abs(-1.12334)");
	EvaluateAndShow(engine, "1.45*44%3");
	EvaluateAndShow(engine, "(1+4)/cos(3.1415926)");
	EvaluateAndShow(engine, "@+1");
	EvaluateAndShow(engine, "@@+1");
	EvaluateAndShow(engine, "acos(1)*@");
	return EXIT_SUCCESS;
}