//
// Created by 方泓睿 on 2019/12/1.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "calculator/operators/functions/functions.h"

#include <cmath>
#include <functional>

namespace calculator::operators::functions::standard {
const Operator kAbs = Operator{
		"abs",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::abs(argv[0]);
		},
		Operator::Type::kFunction,
};
}

#pragma clang diagnostic pop