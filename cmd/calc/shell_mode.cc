//
// Created by 方泓睿 on 2019/12/4.
//

#include "calc.h"

#include <calculator.h>

#include <readline/readline.h>
#include <readline/history.h>

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <csignal>

std::vector<std::string> kVocabulary;

calculator::Engine kEngine;

auto GenerateVocabulary() -> void {
	kVocabulary = {};

	auto engine    = calculator::Engine();
	auto functions = engine.Functions();
	auto constants = engine.Constatnts();

	for (const auto &function:functions)
		if (function.size() > 1)
			kVocabulary.push_back(function);

	for (const auto &constant:constants)
		if (std::get<0>(constant).size() > 1)
			kVocabulary.push_back(std::get<0>(constant));
}

auto CompletionGenerator(const char *text, int state) -> char * {
	// This function is called with state=0 the first time; subsequent calls are
	// with a nonzero state. state=0 can be used to perform one-time
	// initialization for this completion session.
	std::string res{};

	while (*text != '\0') {
		if (isalpha(*text))
			break;
		res += *text;
		text++;
	}

	if (*text == '\0')
		return nullptr;

	static std::vector<std::string> matches;
	static size_t                   match_index = 0;

	if (state == 0) {
		// During initialization, compute the actual matches for 'text' and keep
		// them in a static vector.


		matches.clear();
		match_index = 0;

		// Collect a vector of matches: vocabulary words that begin with text.
		std::string text_str = std::string(text);

		for (const auto &word : kVocabulary) {
			if (word.size() >= text_str.size() &&
					word.compare(0, text_str.size(), text_str) == 0) {
				matches.push_back(word);
			}
		}
	}

	if (match_index >= matches.size()) {
		// We return nullptr to notify the caller no more matches are available.
		return nullptr;
	} else {
		// Return a malloc'd char* for the match. The caller frees it.
		return strdup((res + matches[match_index++]).c_str());
	}
}

auto Completer(const char *text, int start, int end) -> char ** {
	// Don't do filename completion even if our generator finds no matches.
	rl_attempted_completion_over = 1;

	// Note: returning nullptr here will make readline use the default filename
	// completer.
	return rl_completion_matches(text, CompletionGenerator);
}

auto InitShell() -> void {
	GenerateVocabulary();
	rl_attempted_completion_function = Completer;
	kEngine                          = calculator::Engine();
	kEngine.Reset();
}

auto OnNewLine(char *buf) -> void {
	if (buf == nullptr) {
		kShouldExit = true;
		return;
	}
	if (strlen(buf) > 0) {
		add_history(buf);
		if (buf[0] == '!') {
			system(&buf[1]);
		} else if (!strcmp(buf, "shell"))
			system("bash");
		else if (!strcmp(buf, "quit")) {
			kShouldExit = true;
			return;
		} else if (!strcmp(buf, "version"))
			std::cout << "calc version " << calculator::Engine::Version() << std::endl;
		else {
			try {
				auto res = kEngine.Evaluate(buf, kVerbose);
				std::cout << res << std::endl;
			} catch (const std::exception &re) {
				if (kStrict)
					Panic(std::string("Cannot evaluate ") + buf + ": " + re.what());
				if (kVerbose)
					std::cerr << "Cannot evaluate " << buf << ": " << re.what() << std::endl;
				else if (!kQuiet)
					std::cout << "Cannot evaluate due to error" << std::endl;
			}
		}
	}
	free(buf);
}

auto StartShell(const std::string &prompt) -> void {
	InitShell();
	rl_callback_handler_install(prompt.c_str(), OnNewLine);
}

auto EnterShellMode(const std::string &prompt) -> int {
	if (!kQuiet)
		ShowBanner();

	kShouldExit = false;

	StartShell(prompt);

	if (signal(SIGINT, [](int) -> void {
		std::cout << "(interrupt) use quit to exit." << std::endl;
	}) == SIG_ERR)
		Panic("Failed to install signal handler.");

	while (!kShouldExit) {
		rl_callback_read_char();
	}

	std::cout << "Bye bye" << std::endl;

	fflush(stdout);
	return EXIT_SUCCESS;
}