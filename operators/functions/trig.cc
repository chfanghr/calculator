//
// Created by 方泓睿 on 2019/12/2.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "functions.h"

#include <cmath>

auto kSin = Operator{
		"sin",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::sin(argv[0]);
		}
};

auto kCos = Operator{
		"cos",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::cos(argv[0]);
		}
};

auto kTan = Operator{
		"tan",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::tan(argv[0]);
		}
};

auto kCot = Operator{
		"cot",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return 1 / std::tan(argv[0]);
		}
};

auto kSec = Operator{
		"sec",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return 1 / std::cos(argv[0]);
		}
};

auto kCsc = Operator{
		"csc",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return 1 / std::sin(argv[0]);
		}
};

auto kAsin = Operator{
		"asin",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::asin(argv[0]);
		}
};

auto kAcos = Operator{
		"acos",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::acos(argv[0]);
		}
};

auto kAtan = Operator{
		"atan",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::atan(argv[0]);
		}
};

auto kAcot = Operator{
		"acot",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return (-90 * ((M_PI * std::atan(argv[0]) / 90) - M_PI)) / M_PI;
		}
};

auto kAsec = Operator{
		"asec",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::acos(1 / argv[0]);
		}
};

auto kAcsc = Operator{
		"acsc",
		0,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::asin(1 / argv[0]);
		}
};

auto RegisterTrigFunctions() -> void {
	RegisterFunction(kSin);
	RegisterFunction(kCos);
	RegisterFunction(kTan);
	RegisterFunction(kCot);
	RegisterFunction(kSec);
	RegisterFunction(kCsc);
	RegisterFunction(kAsin);
	RegisterFunction(kAcos);
	RegisterFunction(kAtan);
	RegisterFunction(kAcot);
	RegisterFunction(kAsec);
	RegisterFunction(kAcsc);
}

#pragma clang diagnostic pop