//
// Created by 方泓睿 on 2019/12/1.
//

#ifndef CALCULATOR_OPERATORS_FUNCTIONS_FUNCTIONS_H_
#define CALCULATOR_OPERATORS_FUNCTIONS_FUNCTIONS_H_

#include "operators/operators.h"

#include <set>

auto RegisterFunction(const Operator &) -> void;

auto IsFunctionExists(const std::string &name) -> bool;

extern std::set<std::string> kFunctions;

#endif //CALCULATOR_OPERATORS_FUNCTIONS_FUNCTIONS_H_
