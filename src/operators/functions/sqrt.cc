//
// Created by 方泓睿 on 2019/12/2.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "functions.h"

#include <cmath>
#include <functional>

namespace calculator::operators::functions::standard {
const Operator kSqrt = Operator{
		"sqrt",
		0,
		Operator::AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return std::sqrt(argv[0]);
		},
		Operator::Type::kFunction
};
}

#pragma clang diagnostic pop