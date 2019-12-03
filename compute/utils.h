//
// Created by 方泓睿 on 2019/12/2.
//

#ifndef CALCULATOR_COMPUTE_UTILS_H_
#define CALCULATOR_COMPUTE_UTILS_H_

#include "token/token.h"
#include "operators/operators.h"
#include "constants/constants.h"
#include "token/token.h"
#include "operators/functions/functions.h"
#include "stack.h"

#include <stack>
#include <string>
#include <exception>

auto EvalOp(const std::string &op_name, Stack<double> &floats) noexcept(false) -> void;

auto IsOperator(const std::string &literal) -> bool;

auto IsOperand(Token tok) -> bool;

auto IsNegation(const Token &tok, const Token &prev) -> bool;

auto IsConstant(const std::string &literal) -> bool;

auto ParseFloat(const std::string &literal) noexcept(false) -> double;

auto ParseOperator(const std::string &literal) noexcept(false) -> Operator;

auto ShouldPopNext(const std::string &n1, const std::string &n2) noexcept(false) -> bool;

auto EvalUnprecedenced(const std::string &op, Stack<std::string> &ops, Stack<double> &floats) noexcept
(false) -> void;

auto IsFunction(const std::string &literal) -> bool;

auto TrimSpace(const std::string &str) -> std::string;

#endif //CALCULATOR_COMPUTE_UTILS_H_
