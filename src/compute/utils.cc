//
// Created by 方泓睿 on 2019/12/2.
//

#include "utils.h"

#include <exception>

namespace calculator::compute::utils {

auto ParseFloat(const std::string &literal) -> double {
	try { return std::stod(literal); }
	catch (...) {
		throw std::runtime_error(std::string("Cannot parse recognized float: ") + literal);
	}
}

auto IsOperand(token::Token tok) noexcept -> bool {
	return tok == token::Token::kFloat || tok == token::Token::kInt;
}

auto TrimSpace(const std::string &str) noexcept -> std::string {
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first) {
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

}

namespace calculator {

auto Engine::IsNegation(compute::token::Token tok, compute::token::Token prev) const noexcept -> bool {
	return tok == compute::token::Token::kSub
			&& (prev == compute::token::Token::kIllegal
					|| IsOperator(compute::token::ToString(prev))
					|| prev == compute::token::Token::kLParen);
}

auto Engine::ShouldPopNext(const std::string &n1, const std::string &n2) const -> bool {
	if (!IsOperator(n2))
		return false;
	if (n1 == "neg")
		return false;
	auto op_1 = GetOperator(n1);
	auto op_2 = GetOperator(n2);
	if (op_1.associativity == Operator::AssociativityType::L)
		return op_1.precedence <= op_2.precedence;
	return op_1.precedence < op_2.precedence;
}

auto Engine::EvalUnprecedenced(const std::string &op, compute::utils::Stack<std::string> &ops,
															 compute::utils::Stack<double> &floats) const -> void {
	while (ops && ShouldPopNext(op, ops.SafeTop()))
		EvalOp(ops.SafePop(), floats);
	ops.Push(op);
}

auto Engine::EvalOp(const std::string &op_name, compute::utils::Stack<double> &floats) const -> void {
	auto op   = GetOperator(op_name);
	auto args = std::valarray<double>(op.args);

	for (auto i = op.args - 1; i >= 0; i--) {
		if (!floats)
			throw std::runtime_error("No enough arguments for operator!");
		auto arg = floats.Pop();
		args[i] = arg;
	}

	floats.Push(op.operation(args));
}
}