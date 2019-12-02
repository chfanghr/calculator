//
// Created by 方泓睿 on 2019/12/2.
//

#include "compute.h"
#include "utils.h"
#include "history.h"
#include "stack.h"

auto Evaluate(const std::string &in) -> double {
	auto    floats = std::stack<double>();
	auto    ops    = std::stack<std::string>();
	auto    s      = Scanner(in);
	auto    prev   = Token::kIllegal;
	int64_t back   = -1;
	for (;;) {
		auto[pos, tok, lit]=s.Scan();
		if (lit != "@" && back > -1 && !kResHistory.empty()) {
			floats.push(GetHistory(back));
			if (prev == Token::kRParen || IsConstant(TokenToString(prev)))
				EvalUnprecedenced("*", ops, floats);
			back = -1;
		}
		if (tok == Token::kEOF)break;
		else if (lit == "@")back += 1;
		else if (IsConstant(lit)) {
			floats.push(GetConstantValue(lit).value());
			if (prev == Token::kRParen || IsOperand(prev))
				EvalUnprecedenced("*", ops, floats);
		} else if (IsOperand(tok)) {
			floats.push(ParseFloat(lit));
			if (prev == Token::kRParen || IsConstant(TokenToString(prev)))
				EvalUnprecedenced("*", ops, floats);
		} else if (IsFunction(lit)) {
			if (IsOperand(prev) || prev == Token::kRParen)
				EvalUnprecedenced("*", ops, floats);
			ops.push(lit);
		} else if (IsOperator(TokenToString(tok))) {
			auto op = TokenToString(tok);
			if (IsNegation(tok, prev))
				op = "neg";
			EvalUnprecedenced(op, ops, floats);
		} else if (tok == Token::kLParen) {
			if (IsOperand(prev))
				EvalUnprecedenced("*", ops, floats);
			ops.push(TokenToString(tok));
		} else if (tok == Token::kRParen) {
			while (!ops.empty() && SafeTop(ops) != "(")
				EvalOp(SafePop(ops), floats);
			Pop(ops);
			if (!ops.empty() && IsFunction(SafeTop(ops)))
				EvalOp(SafePop(ops), floats);
		} else {
			auto inspect = TokenToString(tok);
			if (!TrimSpace(lit).empty())
				inspect += " (`" + lit + "`)";
			throw std::runtime_error(std::string("Unrecognized token ") + inspect + " in expression.");
		}
		prev = tok;
	}
	while (!ops.empty())
		EvalOp(SafePop(ops), floats);
	auto res = Top(floats);
	PushHistory(res);
	return res;
}