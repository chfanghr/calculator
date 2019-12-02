//
// Created by 方泓睿 on 2019/12/1.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "functions.h"

#include <cmath>

auto kAbs = Operator{
		"abs",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::abs(argv[0]);
		}
};

auto RegisterAbsFunction() -> void {
	RegisterFunction(kAbs);
}
#pragma clang diagnostic pop