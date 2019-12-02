//
// Created by 方泓睿 on 2019/12/1.
//

#include "operators.h"
#include "functions/registers.h"
#include "registers.h"

std::map<std::string, Operator> kOperations{};

auto RegisterOperator(const Operator &an_operator) -> void {
	kOperations[an_operator.name] = an_operator;
}

auto IsOperatorExists(const std::string &name) -> bool {
	return kOperations.find(name) != kOperations.end();
}

auto GetOperator(const std::string &name) -> std::optional<Operator> {
	if (IsOperatorExists(name))
		return kOperations[name];
	return {};
}

auto RegisterAllOperators() -> void {
	RegisterStandardOperators();
}

auto InitOperators() -> void {
	RegisterAllFunctions();
	RegisterAllOperators();
};