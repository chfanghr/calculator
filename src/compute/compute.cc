//
// Created by 方泓睿 on 2019/12/2.
//

#include "utils.h"
#include "stack.h"

namespace calculator {
auto Engine::Eval(const std::string &in, bool verbose) const -> double {
	using namespace compute::utils;
	using namespace compute::token;

	auto    floats = Stack<double>();
	auto    ops    = Stack<std::string>();
	auto    s      = Scanner(in);
	auto    prev   = Token::kIllegal;
	int64_t back   = -1;

	for (;;) {
		auto[pos, tok, lit]=s.Scan();
		if (lit != "@" && back > -1 && !history_.empty()) {
			floats.Push(GetHistory(back));
			if (prev == Token::kRParen || IsConstant(ToString(prev)))
				EvalUnprecedenced("*", ops, floats);
			back = -1;
		}
		if (tok == Token::kEOF)break;
		else if (lit == "@")
			back += 1;
		else if (IsConstant(lit)) {
			floats.Push(GetConstant(lit));
			if (prev == Token::kRParen || IsOperand(prev))
				EvalUnprecedenced("*", ops, floats);
		} else if (IsOperand(tok)) {
			floats.Push(ParseFloat(lit));
			if (prev == Token::kRParen || IsConstant(ToString(prev)))
				EvalUnprecedenced("*", ops, floats);
		} else if (IsFunction(lit)) {
			if (IsOperand(prev) || prev == Token::kRParen)
				EvalUnprecedenced("*", ops, floats);
			ops.Push(lit);
		} else if (IsOperator(ToString(tok))) {
			auto op = ToString(tok);
			if (IsNegation(tok, prev))
				op = "neg";
			EvalUnprecedenced(op, ops, floats);
		} else if (tok == Token::kLParen) {
			if (IsOperand(prev))
				EvalUnprecedenced("*", ops, floats);
			ops.Push(ToString(tok));
		} else if (tok == Token::kRParen) {
			while (ops && ops.SafeTop() != "(")
				EvalOp(ops.SafePop(), floats);
			ops.Pop();
			if (ops && IsFunction(ops.SafeTop()))
				EvalOp(ops.SafePop(), floats);
		} else {
			auto inspect = ToString(tok);
			if (!TrimSpace(lit).empty())
				inspect += " (`" + lit + "`)";
			throw std::runtime_error(std::string("Unrecognized token ") + inspect + " in expression.");
		}
		prev = tok;
	}
	while (ops)
		EvalOp(ops.SafePop(), floats);
	return floats.Top();
}

auto Engine::Evaluate(const std::string &in, bool verbose) -> double {
	auto res = Eval(in, verbose);
	PushHistory(res);
	return res;
}

auto Engine::Evaluate(const std::string &in, bool verbose) const -> double {
	return Eval(in, verbose);
}
}