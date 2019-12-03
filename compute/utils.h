//
// Created by 方泓睿 on 2019/12/2.
//

#ifndef CALCULATOR_COMPUTE_UTILS_H_
#define CALCULATOR_COMPUTE_UTILS_H_

#include "engine.h"
#include "token/token.h"
#include "stack.h"

namespace calculator::compute::utils {
auto IsOperand(token::Token tok) noexcept -> bool;

auto ParseFloat(const std::string &literal) noexcept(false) -> double;

auto TrimSpace(const std::string &str) noexcept -> std::string;
}
#endif //CALCULATOR_COMPUTE_UTILS_H_
