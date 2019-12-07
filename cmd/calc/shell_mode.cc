//
// Created by 方泓睿 on 2019/12/4.
//

#include "calc.h"

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <csignal>

#include "third_party/cpp-linenoise/linenoise.hpp"

std::vector<std::string> kVocabulary;

auto GenerateVocabulary() -> void {
	kVocabulary = {};

	auto engine    = calculator::Engine();
	auto functions = engine.Functions();
	auto constants = engine.Constants();

	for (const auto &function:functions)
		if (function.size() > 1)
			kVocabulary.push_back(function);

	for (const auto &constant:constants)
		if (std::get<0>(constant).size() > 1)
			kVocabulary.push_back(std::get<0>(constant));
}

auto OnNewLine(const std::string &in) -> void {
	if (!in.empty()) {
		try {
			if (in[0] == '!' && in.size() > 1) {
				if (!system(&in.c_str()[1]))
					throw std::runtime_error("Command execution failed.");
			} else if (in == "shell") {
				if (!system("bash"))
					throw std::runtime_error("Failed to execute bash.");
			} else if (in == "quit") {
				std::cout << "";
				kShouldExit = true;
				return;
			} else if (in == "version") {
				std::cout << "calc version " << calculator::Engine::Version() << std::endl;
			} else if (kIAmINM && (in.find("114514") != std::string::npos
					|| in.find("1919810") != std::string::npos)) {
				std::string WTF = "https://www.youtube.com/watch?v=b1p8c99FgAQ";
#ifndef _WIN32
				std::vector<std::string> solutions = {"open", "xdg-open", "gnome-open ", "cygstart"};

				for (auto solution:solutions)
					system((solution.append(" " + WTF + " 1>&- 2>&-").c_str()));
#elif
				system(("cmd /c start " + WTF).c_str());
#endif
				auto res = kEngine.Evaluate(in, kVerbose);
				std::cout << res << std::endl;
			} else {
				auto res = kEngine.Evaluate(in, kVerbose);
				std::cout << res << std::endl;
			}
		} catch (const std::exception &re) {
			if (kStrict)
				Panic(std::string("Cannot evaluate ") + in + ": " + re.what());
			if (kVerbose)
				std::cerr << "Cannot evaluate " << in << ": " << re.what() << std::endl;
			else if (!kQuiet)
				std::cout << "Cannot evaluate due to error" << std::endl;
		}
	}
}

auto EnterShellMode(const std::string &prompt) -> int {
	GenerateVocabulary();

	if (!kQuiet)
		ShowBanner();

	kShouldExit = false;
	kEngine.Reset();

	auto user_dir = const_cast<const char *>(getenv("USER"));
	if (!user_dir)
		user_dir = const_cast<const char *>(getenv("HOME"));
	if (!user_dir)
		user_dir = "/tmp";

	const auto history_path = std::string(user_dir) + "/.calc_history";

	linenoise::SetCompletionCallback([](const char *text, std::vector<std::string> &matches) {
		if (!text)
			return;
		auto in = std::string(text);
		if (in.empty())
			return;
		if (!isalpha(*in.rbegin()))
			return;

		int64_t pos;

		for (pos = in.size() - 1; pos >= 0; pos--)
			if (!isalpha(in[pos]))
				break;

		pos += 1;

		auto word_remain = std::string();
		if (pos != 0)
			word_remain = std::string(in, 0, pos);
		auto word_to_comp = std::string(in, pos);

		for (const auto &word : kVocabulary) {
			if (word.size() >= word_to_comp.size() &&
					word.compare(0, word_to_comp.size(), word_to_comp) == 0) {
				matches.push_back(word_remain + word);
			}
		}
	});

	std::signal(SIGINT, [](int) -> void {
		kShouldExit = true;
		std::cerr << "(interrupt) Please use 'quit' to exit" << std::endl;
	});

	linenoise::SetMultiLine(true);
	linenoise::SetHistoryMaxLen(100);
	linenoise::LoadHistory(history_path.c_str());

	while (true) {
		// Read line
		std::string line{};

		if (std::cin.fail() || std::cin.eof())
			break;

		auto quit = linenoise::Readline((prompt + " ").c_str(), line);

		if (quit) break;

		OnNewLine(line);

		if (kShouldExit) break;

		linenoise::AddHistory(line.c_str());
	}

	std::cout << "Bye bye" << std::endl;
	linenoise::SaveHistory(history_path.c_str());

	return EXIT_SUCCESS;
}