//
// Created by 方泓睿 on 2019/12/1.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "functions.h"

#include <cmath>

auto kLog = Operator{
		"log",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::log10(argv[0]);
		}
};

auto kLn = Operator{
		"ln",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::log(argv[0]);
		}
};

auto kLg = Operator{
		"lg",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::log2(argv[0]);
		}
};

auto RegisterLogFunctions() -> void {
	RegisterFunction(kLog);
	RegisterFunction(kLn);
	RegisterFunction(kLg);
}

#pragma clang diagnostic pop