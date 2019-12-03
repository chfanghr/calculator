//
// Created by 方泓睿 on 2019/12/2.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "constants.h"

#include <cmath>

namespace calculator::constants::standard {
const auto kE = Constant{
		"e", M_E
};

const auto kPI = Constant{
		"pi", M_PI
};
}
#pragma clang diagnostic pop