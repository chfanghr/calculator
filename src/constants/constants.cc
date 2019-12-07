//
// Created by 方泓睿 on 2019/12/3.
//

#include "calculator/constants/constants.h"

namespace calculator {
auto Engine::RegisterStandardConstants() noexcept -> void {
	using namespace constants::standard;
	Register(kE);
	Register(kPI);
}
}