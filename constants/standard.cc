//
// Created by 方泓睿 on 2019/12/2.
//

#include "constants.h"

#include <cmath>

auto kE = Constant{
		"e", M_E
};

auto kPI = Constant{
		"pi", M_PI
};

auto RegisterStandardConstants() -> void {
	RegisterConstant(kE);
	RegisterConstant(kPI);
}
