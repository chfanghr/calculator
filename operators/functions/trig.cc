//
// Created by 方泓睿 on 2019/12/2.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "functions.h"

#include <cmath>

namespace calculator::operators::functions::standard {
const auto kSin = Operator{
		"sin",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::sin(argv[0]);
		},
		Operator::Type::kFunction,
};

const auto kCos = Operator{
		"cos",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::cos(argv[0]);
		},
		Operator::Type::kFunction,
};

const auto kTan = Operator{
		"tan",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::tan(argv[0]);
		},
		Operator::Type::kFunction,
};

const auto kCot = Operator{
		"cot",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return 1 / std::tan(argv[0]);
		},
		Operator::Type::kFunction,
};

const auto kSec = Operator{
		"sec",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return 1 / std::cos(argv[0]);
		},
		Operator::Type::kFunction,
};

const auto kCsc = Operator{
		"csc",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return 1 / std::sin(argv[0]);
		},
		Operator::Type::kFunction,
};

const auto kAsin = Operator{
		"asin",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::asin(argv[0]);
		},
		Operator::Type::kFunction,
};

const auto kAcos = Operator{
		"acos",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::acos(argv[0]);
		}
};

const auto kAtan = Operator{
		"atan",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::atan(argv[0]);
		},
		Operator::Type::kFunction,
};

const auto kAcot = Operator{
		"acot",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return (-90 * ((M_PI * std::atan(argv[0]) / 90) - M_PI)) / M_PI;
		},
		Operator::Type::kFunction,
};

const auto kAsec = Operator{
		"asec",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::acos(1 / argv[0]);
		},
		Operator::Type::kFunction,
};

const auto kAcsc = Operator{
		"acsc",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::asin(1 / argv[0]);
		},
		Operator::Type::kFunction,
};
}

#pragma clang diagnostic pop