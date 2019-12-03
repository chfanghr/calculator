//
// Created by 方泓睿 on 2019/12/1.
//

#include "functions.h"

namespace calculator {
auto Engine::RegisterStandardFunctions() noexcept -> void {
	using namespace operators::functions::standard;
	Register(kAbs);
	Register(kLog);
	Register(kLn);
	Register(kLg);
	Register(kSqrt);
	Register(kSin);
	Register(kCos);
	Register(kTan);
	Register(kCot);
	Register(kSec);
	Register(kCsc);
	Register(kAsin);
	Register(kAcos);
	Register(kAtan);
	Register(kAcot);
	Register(kSec);
	Register(kAsec);
	Register(kAcsc);
}
}