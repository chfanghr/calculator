//
// Created by 方泓睿 on 2019/12/4.
//

#include <string>
#include <iostream>

bool kQuiet;
bool kStrict;
bool kVerbose;
bool kForceInteractive;

auto Panic(const std::string &msg, int exit_value) -> void {
	std::cerr << "[PANIC] what: " << msg << std::endl;
	exit(exit_value);
}

auto TrimSpace(const std::string &str) noexcept -> std::string {
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first) {
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

volatile int kKeepRunning = 1;

extern "C" auto IntHandler(int) -> void {
	kKeepRunning = false;
}