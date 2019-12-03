//
// Created by 方泓睿 on 2019/12/2.
//

#include "compute.h"
#include "utils.h"
#include "history.h"
#include "stack.h"

auto Evaluate(const std::string &in) -> double {
	auto    floats = Stack<double>();
	auto    ops    = Stack<std::string>();
	auto    s      = Scanner(in);
	auto    prev   = Token::kIllegal;
	int64_t back   = -1;
	for (;;) {
		auto[pos, tok, lit]=s.Scan();
		if (lit != "@" && back > -1 && !kResHistory.empty()) {
			floats.Push(GetHistory(back));
			if (prev == Token::kRParen || IsConstant(TokenToString(prev)))
				EvalUnprecedenced("*", ops, floats);
			back = -1;
		}
		if (tok == Token::kEOF)break;
		else if (lit == "@")back += 1;
		else if (IsConstant(lit)) {
			floats.Push(GetConstantValue(lit).value());
			if (prev == Token::kRParen || IsOperand(prev))
				EvalUnprecedenced("*", ops, floats);
		} else if (IsOperand(tok)) {
			floats.Push(ParseFloat(lit));
			if (prev == Token::kRParen || IsConstant(TokenToString(prev)))
				EvalUnprecedenced("*", ops, floats);
		} else if (IsFunction(lit)) {
			if (IsOperand(prev) || prev == Token::kRParen)
				EvalUnprecedenced("*", ops, floats);
			ops.Push(lit);
		} else if (IsOperator(TokenToString(tok))) {
			auto op = TokenToString(tok);
			if (IsNegation(tok, prev))
				op = "neg";
			EvalUnprecedenced(op, ops, floats);
		} else if (tok == Token::kLParen) {
			if (IsOperand(prev))
				EvalUnprecedenced("*", ops, floats);
			ops.Push(TokenToString(tok));
		} else if (tok == Token::kRParen) {
			while (ops && ops.SafeTop() != "(")
				EvalOp(ops.SafePop(), floats);
			ops.Pop();
			if (ops && IsFunction(ops.SafePop()))
				EvalOp(ops.SafePop(), floats);
		} else {
			auto inspect = TokenToString(tok);
			if (!TrimSpace(lit).empty())
				inspect += " (`" + lit + "`)";
			throw std::runtime_error(std::string("Unrecognized token ") + inspect + " in expression.");
		}
		prev = tok;
	}
	while (ops)
		EvalOp(ops.SafePop(), floats);
	auto res = floats.Top();
	PushHistory(res);
	return res;
}