//
// Created by 方泓睿 on 2019/12/5.
//

#include "calc.h"

#include <calculator.h>

#include <fstream>
#include <stdexcept>
#include <iostream>

auto ReadAndEvaluate(const std::string &file_name) -> void {
	if (file_name.empty())
		return;

	auto file = std::ifstream(file_name);

	for (std::string line; std::getline(file, line);) {
		if (line.empty() || TrimSpace(line).empty())
			continue;
		if (line[0] == '#')
			continue;
		try { std::cout << kEngine.Evaluate(line, kVerbose) << std::endl; }
		catch (const std::exception &re) {
			if (kStrict)
				Panic(std::string("Cannot evaluate ") + line + ": " + re.what());

			if (kVerbose)
				std::cerr << "Cannot evaluate " << line << ": " << re.what() << std::endl;
			else if (!kQuiet)
				std::cout << "Cannot evaluate due to error" << std::endl;
		}
	}

	if (file.fail() && !file.eof())
		throw std::runtime_error("Unexpected io error.");
}

auto EnterFileMode() -> int {
	kEngine.Reset();
	for (const auto &file:kExtraOptions) {
		try {
			if (file.empty())
				continue;
			ReadAndEvaluate(file);
		} catch (const std::exception &re) {
			if (kStrict)
				Panic(std::string("Cannot evaluate file: ") + file + ": " + re.what());

			if (kVerbose)
				std::cerr << "Cannot evaluate file:" << file << ": " << re.what() << std::endl;
			else if (!kQuiet)
				std::cout << "Cannot evaluate due to error" << std::endl;

			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}