//
// Created by 方泓睿 on 2019/12/2.
//

#include "calculator/engine/engine.h"

#include <stdexcept>

namespace calculator {
auto Engine::RegisterStandards() noexcept -> void {
	RegisterStandardOperators();
	RegisterStandardFunctions();
	RegisterStandardConstants();
}

auto Engine::Reset() noexcept -> void {
	ClearHistory();
	functions_.clear();
	operators_.clear();
	RegisterStandards();
}

Engine::Engine() noexcept {
	Reset();
}

auto Engine::IsOperator(const std::string &name) const noexcept -> bool {
	return operators_.find(name) != operators_.end();
}

auto Engine::IsFunction(const std::string &name) const noexcept -> bool {
	return functions_.find(name) != functions_.end();
}

auto Engine::IsConstant(const std::string &name) const noexcept -> bool {
	return constants_.find(name) != constants_.end();
}

auto Engine::GetOperator(const std::string &name) const noexcept(false) -> Operator {
	if (!(IsOperator(name) || IsFunction(name)))
		throw std::runtime_error(std::string("No such operator: ") + name);
	return operators_.at(name);
}

auto Engine::GetConstant(const std::string &name) const noexcept(false) -> double {
	if (!IsConstant(name))
		throw std::runtime_error(std::string("No such constant: ") + name);
	return constants_.at(name);
}

auto Engine::Version() -> std::string {
	return std::string(GIT_BRANCH) + "." + std::string(GIT_REV) + "." + std::string(GIT_TAG);
}

[[nodiscard]] auto Engine::Functions() const noexcept -> const std::set<std::string> & {
	return functions_;
}

[[nodiscard]] auto Engine::Constants() const noexcept -> const std::map<std::string, double> & {
	return constants_;
}

[[nodiscard]] auto Engine::Operators() const noexcept -> const std::map<std::string, Operator> & {
	return operators_;
}

auto Version() -> std::string {
	return Engine::Version();
}
}
