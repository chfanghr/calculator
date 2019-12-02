//
// Created by 方泓睿 on 2019/12/1.
//

#ifndef CALCULATOR__OPERATORS_OPERATORS_H_
#define CALCULATOR__OPERATORS_OPERATORS_H_

#include <functional>
#include <string>
#include <valarray>
#include <optional>
#include <map>
#include <vector>

enum class AssociativityType : int32_t {
	L = 0, R = 1
};

struct Operator {
	std::string                                          name;
	int32_t                                              precedence;
	AssociativityType                                    associativity;
	int32_t                                              args;
	std::function<double(const std::valarray<double> &)> operation;
};

auto RegisterOperator(const Operator &) -> void;

auto IsOperatorExists(const std::string &) -> bool;

auto GetOperator(const std::string &) -> std::optional<Operator>;

extern std::map<std::string, Operator> kOperations;

auto InitOperators() -> void;

#endif