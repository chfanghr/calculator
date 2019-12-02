//
// Created by 方泓睿 on 2019/12/1.
//

#include "functions.h"
#include "registers.h"

std::set<std::string> kFunctions{};

auto RegisterFunction(const Operator &an_operator) -> void {
	RegisterOperator(an_operator);
	kFunctions.insert(an_operator.name);
}

auto IsFunctionExists(const std::string &name) -> bool {
	return kFunctions.find(name) != kFunctions.end();
}

auto RegisterAllFunctions() -> void {
	RegisterAbsFunction();
	RegisterLogFunctions();
	RegisterSqrtFunction();
	RegisterTrigFunctions();
}