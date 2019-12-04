//
// Created by 方泓睿 on 2019/12/4.
//

#include <calculator.h>

#include <string>
#include <iostream>

#include "calc.h"

bool          kQuiet;
bool          kStrict;
bool          kVerbose;
bool          kForceInteractive;
volatile bool kShouldExit;

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

auto ShowBanner() -> void {
	ShowVersion();
	std::cout << "calc is a powerful open-source command-line calculator." << std::endl;
	std::cout << "The code is hosted on github.com/chfanghr/calculator with MIT license." << std::endl;
}

auto ShowVersion() -> int {
	std::cout << "calc version " << calculator::Engine::Version() << std::endl;
	return EXIT_SUCCESS;
}

auto ShowHelpMessage() -> void {
	// TODO
}