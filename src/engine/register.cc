//
// Created by 方泓睿 on 2019/12/3.
//

#include "calculator/engine/engine.h"

namespace calculator {

auto Engine::Register(const Operator &an_operator) noexcept -> void {
	switch (an_operator.type) {
		case Operator::Type::kOperator: RegisterOperator(an_operator);
			return;
		case Operator::Type::kFunction: RegisterFunction(an_operator);
			return;
	}
}

auto Engine::Register(const Constant &constant) noexcept -> void {
	constants_[constant.name] = constant.value;
}

auto Engine::RegisterOperator(const Operator &op) noexcept -> void {
	operators_[op.name] = op;
}

auto Engine::RegisterFunction(const Operator &func) noexcept -> void {
	functions_.insert(func.name);
	operators_[func.name] = func;
}
}