//
// Created by 方泓睿 on 2019/12/2.
//

#include "constants.h"

std::map<std::string, double> kConstants{};

auto RegisterConstant(const Constant &constant) -> void {
	kConstants[constant.name] = constant.value;
}

auto IsConstantExists(const std::string &name) -> bool {
	return kConstants.find(name) != kConstants.end();
}

auto GetConstantValue(const std::string &name) -> std::optional<double> {
	if (IsConstantExists(name))
		return kConstants[name];
	return {};
}