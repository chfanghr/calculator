//
// Created by 方泓睿 on 2019/12/3.
//

#include "calculator/engine/engine.h"
#include "calculator/operators/operators.h"

namespace calculator {
auto Engine::RegisterStandardOperators() noexcept -> void {
	using namespace operators::standard;
	Register(kAdd);
	Register(kSub);
	Register(kNeg);
	Register(kMul);
	Register(kDiv);
	Register(kMod);
	Register(kPow);
}
}