//
// Created by 方泓睿 on 2019/12/2.
//

#ifndef CALCULATOR_COMPUTE_UTILS_H_
#define CALCULATOR_COMPUTE_UTILS_H_

#include <calculator/engine/engine.h>
#include <calculator/compute/token/token.h>
#include <calculator/compute/stack.h>

namespace calculator::compute::utils {
auto IsOperand(token::Token tok) noexcept -> bool;

auto ParseFloat(const std::string &literal) noexcept(false) -> double;

auto TrimSpace(const std::string &str) noexcept -> std::string;
}
#endif //CALCULATOR_COMPUTE_UTILS_H_
