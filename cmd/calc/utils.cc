//
// Created by 方泓睿 on 2019/12/4.
//

#include <string>
#include <iostream>

bool kQuiet;
bool kStrict;
bool kVerbose;

auto Panic(const std::string &msg, int exit_value) -> void {
	std::cerr << "[PANIC] what: " << msg << std::endl;
	exit(exit_value);
}