//
// Created by 方泓睿 on 2019/12/3.
//

#ifndef CALCULATOR__ENGINE_H_
#define CALCULATOR__ENGINE_H_

#include "src/compute/token/token.h"
#include "src/compute/stack.h"
#include "src/version.h"

#include <cstdint>
#include <string>
#include <valarray>
#include <map>
#include <set>
#include <deque>
#include <functional>

namespace calculator {
class Engine {
 public:
	struct Operator {
		enum class AssociativityType : int32_t {
			L = 0, R = 1
		};
		enum class Type {
			kOperator,
			kFunction
		};
		std::string                                          name;
		int32_t                                              precedence;
		AssociativityType                                    associativity;
		int32_t                                              args;
		std::function<double(const std::valarray<double> &)> operation;
		Type                                                 type;
	};
	struct Constant {
		std::string name;
		double      value;
	};

	Engine() noexcept;

	auto Register(const Operator &an_operator) noexcept -> void;
	auto Register(const Constant &constant) noexcept -> void;

	[[nodiscard]] auto IsOperator(const std::string &name) const noexcept -> bool;
	[[nodiscard]] auto IsFunction(const std::string &name) const noexcept -> bool;
	[[nodiscard]] auto IsConstant(const std::string &name) const noexcept -> bool;

	[[nodiscard]] auto GetOperator(const std::string &name) const noexcept(false) -> Operator;
	[[nodiscard]] auto GetConstant(const std::string &name) const noexcept(false) -> double;

	auto Evaluate(const std::string &in) -> double;
	[[nodiscard]] auto Evaluate(const std::string &in) const -> double;

	auto History() noexcept -> std::deque<double> &;
	[[nodiscard]] auto History() const noexcept -> const std::deque<double> &;

	auto ClearHistory() noexcept -> void;

	auto Reset() noexcept -> void;
 private:
	std::map<std::string, Operator> operators_;
	std::map<std::string, double>   constants_;
	std::set<std::string>           functions_;
	std::deque<double>              history_;
 private:
	auto RegisterOperator(const Operator &op) noexcept -> void;
	auto RegisterFunction(const Operator &func) noexcept -> void;

	auto RegisterStandardOperators() noexcept -> void;
	auto RegisterStandardFunctions() noexcept -> void;
	auto RegisterStandardConstants() noexcept -> void;
	auto RegisterStandards() noexcept -> void;
 private:
	[[nodiscard]] auto GetHistory(size_t idx) const -> double;
	auto PushHistory(double res) noexcept -> void;
 private:
	[[nodiscard]] auto IsNegation(compute::token::Token tok, compute::token::Token prev) const noexcept -> bool;
	[[nodiscard]] auto ShouldPopNext(const std::string &n1, const std::string &n2) const -> bool;
	auto EvalUnprecedenced(const std::string &op, compute::utils::Stack<std::string> &ops,
												 compute::utils::Stack<double> &floats) const -> void;
	auto EvalOp(const std::string &op_name, compute::utils::Stack<double> &floats) const -> void;
 private:
	[[nodiscard]] auto Eval(const std::string &in) const -> double;
 public:
	static auto Version() -> std::string;
};

auto Version() -> std::string;
}
#endif //CALCULATOR__ENGINE_H_
