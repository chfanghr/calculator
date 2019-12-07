//
// Created by 方泓睿 on 2019/12/3.
//

#include <calculator/calculator.h>

#include <iostream>

auto main() -> int {
	std::cout << "version = " << calculator::Version() << std::endl;
	return EXIT_SUCCESS;
}