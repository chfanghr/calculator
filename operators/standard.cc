//
// Created by 方泓睿 on 2019/12/1.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "operators.h"

#include <cmath>

auto kAdd = Operator{
		"+",
		1,
		AssociativityType::L,
		2,
		[](const std::valarray<double> &argv) -> double {
			return argv[0] + argv[1];
		}
};

auto kSub = Operator{
		"-",
		1,
		AssociativityType::L,
		2,
		[](const std::valarray<double> &argv) -> double {
			return argv[0] - argv[1];
		}
};

auto kNeg = Operator{
		"neg",
		2,
		AssociativityType::L,
		1,
		[](const std::valarray<double> &argv) -> double {
			return 0 - argv[0];
		}
};

auto kMul = Operator{
		"*",
		2,
		AssociativityType::L,
		2,
		[](const std::valarray<double> &argv) -> double {
			return argv[0] * argv[1];
		}
};

auto kDiv = Operator{
		"/",
		2,
		AssociativityType::L,
		2,
		[](const std::valarray<double> &argv) -> double {
			return argv[0] / argv[1];
		}
};

auto kMod = Operator{
		"%",
		2,
		AssociativityType::L,
		2,
		[](const std::valarray<double> &argv) -> double {
			auto l_op = argv[0];
			auto r_op = argv[1];

			if (l_op == std::floor(l_op) && r_op == std::floor(r_op))
				return (double) ((int64_t) l_op % (int64_t) r_op);

			// Handling negative values
			double mod = std::abs(l_op);
			r_op = std::abs(r_op);

			// Finding mod by repeated subtraction
			while (mod >= r_op)
				mod = mod - r_op;

			// Sign of result typically depends on sign of l_op.
			return mod * (l_op < 0 ? -1 : 1);
		}
};

auto kPow = Operator{
		"^",
		3,
		AssociativityType::R,
		2,
		[](const std::valarray<double> &argv) -> double {
			return std::pow(argv[0], argv[1]);
		}
};

auto RegisterStandardOperators() -> void {
	RegisterOperator(kAdd);
	RegisterOperator(kSub);
	RegisterOperator(kNeg);
	RegisterOperator(kMul);
	RegisterOperator(kMod);
	RegisterOperator(kDiv);
	RegisterOperator(kPow);
}

#pragma clang diagnostic pop