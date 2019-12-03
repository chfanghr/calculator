//
// Created by 方泓睿 on 2019/12/2.
//

#include "utils.h"

#include <exception>

auto EvalOp(const std::string &op_name, Stack<double> &floats) -> void {
	auto op_pack = GetOperator(op_name);
	if (!op_pack)
		throw std::runtime_error("Either unmatched paren or unrecognized operator.");

	auto      op   = op_pack.value();
	auto      args = std::valarray<double>(op.args);

	for (auto i    = op.args - 1; i >= 0; i--) {
		if (!floats)
			throw std::runtime_error("Not enough arguments to operator!");
		auto arg = floats.Pop();
		args[i] = arg;
	}

	floats.Push(op.operation(args));
}

auto IsOperator(const std::string &literal) -> bool {
	return IsOperatorExists(literal);
}

auto IsNegation(const Token &tok, const Token &prev) -> bool {
	return tok == Token::kSub && (prev == Token::kIllegal || IsOperator(TokenToString(prev)) || prev == Token::kRParen);
}

auto ParseFloat(const std::string &literal) -> double {
	try { return std::stod(literal); }
	catch (...) {
		throw std::runtime_error(std::string("Cannot parse recognized float: ") + literal);
	}
}

auto ParseOperator(const std::string &literal) -> Operator {
	auto op_pack = GetOperator(literal);
	if (!op_pack)
		throw std::runtime_error(std::string("No such operator named: ") + literal);
	return op_pack.value();
}

auto ShouldPopNext(const std::string &n1, const std::string &n2) -> bool {
	if (!IsOperator(n2))
		return false;
	if (n1 == "neg")
		return false;
	auto op_1 = ParseOperator(n1);
	auto op_2 = ParseOperator(n2);
	if (op_1.associativity == AssociativityType::L)
		return op_1.precedence <= op_2.precedence;
	return op_1.precedence < op_2.precedence;
}

auto EvalUnprecedenced(const std::string &op, Stack<std::string> &ops, Stack<double> &floats) -> void {
	while (ops && ShouldPopNext(op, ops.SafePop()))
		EvalOp(ops.SafePop(), floats);
	ops.Push(op);
}

auto IsConstant(const std::string &literal) -> bool {
	return IsConstantExists(literal);
}

auto IsOperand(Token tok) -> bool {
	return tok == Token::kFloat || tok == Token::kInt;
}

auto IsFunction(const std::string &literal) -> bool {
	return IsFunctionExists(literal);
}

auto TrimSpace(const std::string &str) -> std::string {
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first) {
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

