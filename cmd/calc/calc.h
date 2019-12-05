//
// Created by 方泓睿 on 2019/12/4.
//

#ifndef CALCULATOR_CMD_CALC_CALC_H_
#define CALCULATOR_CMD_CALC_CALC_H_

#include <calculator.h>

#include <string>
#include <vector>

extern bool                     kQuiet;
extern bool                     kStrict;
extern bool                     kVerbose;
extern bool                     kForceShellMode;
extern bool                     kForceFileMode;
extern bool                     kForceExpressionMode;
extern volatile bool            kShouldExit;
extern std::string              kPrompt;
extern std::vector<std::string> kExtraOptions;
extern calculator::Engine       kEngine;

auto Panic(const std::string &msg, int exit_value = EXIT_FAILURE) -> void;
auto EnterShellMode(const std::string &prompt) -> int;
auto EnterExpressionsMode() -> int;
auto EnterFileMode() -> int;
auto TrimSpace(const std::string &str) noexcept -> std::string;
auto ShowBanner() -> void;
auto ShowVersion() -> void;
auto ShowHelpMessage() -> void;
auto ParseCommandLineOptions(int argc, char **argv) -> void;

#endif //CALCULATOR_CMD_CALC_CALC_H_
