//
// Created by 方泓睿 on 2019/12/2.
//

#ifndef CALCULATOR_CONSTANTS_CONSTANTS_H_
#define CALCULATOR_CONSTANTS_CONSTANTS_H_

#include <map>
#include <string>
#include <optional>

extern std::map<std::string, double> kConstants;

struct Constant {
	std::string name;
	double      value;
};

auto RegisterConstant(const Constant &) -> void;

auto IsConstantExists(const std::string &) -> bool;

auto GetConstantValue(const std::string &) -> std::optional<double>;

#endif //CALCULATOR_CONSTANTS_CONSTANTS_H_
