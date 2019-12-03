//
// Created by 方泓睿 on 2019/12/3.
//

#include <calculator.h>

#include <iostream>

auto main() -> int {
	auto engine = calculator::Engine();

	std::cout << engine.Evaluate("1+1") << std::endl;
	std::cout << engine.Evaluate("1*3+2") << std::endl;
	std::cout << engine.Evaluate("0+9/3") << std::endl;
	std::cout << engine.Evaluate("(1+3)/2") << std::endl;
	std::cout << engine.Evaluate("abs(-1.12334)") << std::endl;
	std::cout << engine.Evaluate("1.45*44%3") << std::endl;
	std::cout << engine.Evaluate("(1+4)/cos(3.1415926)") << std::endl;
	std::cout << engine.Evaluate("@+1") << std::endl;
	std::cout << engine.Evaluate("@@+1") << std::endl;
	std::cout << engine.Evaluate("acos(1)") << std::endl;
	return EXIT_SUCCESS;
}