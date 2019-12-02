//
// Created by 方泓睿 on 2019/12/2.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "functions.h"

#include <cmath>

auto kSqrt = Operator{
		"sqrt",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::sqrt(argv[0]);
		}
};

auto RegisterSqrtFunction() -> void {
	RegisterFunction(kSqrt);
}

#pragma clang diagnostic pop