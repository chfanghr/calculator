//
// Created by 方泓睿 on 2019/12/4.
//

#ifndef CALCULATOR_CMD_CALC_CALC_H_
#define CALCULATOR_CMD_CALC_CALC_H_

#include <string>

extern bool         kQuiet;
extern bool         kStrict;
extern bool         kVerbose;
extern bool         kForceInteractive;
extern volatile int kKeepRunning;

extern "C" void IntHandler(int);
auto Panic(const std::string &msg, int exit_value = EXIT_FAILURE) -> void;
auto Shell(const std::string &prompt) -> int;
auto ParseAndEvaluate(const std::string &in) -> int;
auto TrimSpace(const std::string &str) noexcept -> std::string;

#endif //CALCULATOR_CMD_CALC_CALC_H_
