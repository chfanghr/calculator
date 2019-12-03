//
// Created by 方泓睿 on 2019/12/4.
//

#include <calculator.h>

#include <string>
#include <vector>

#include <readline/history.h>
#include <readline/readline.h>

std::vector<std::string> kVocabulary;

auto GenerateVocabulary() -> void {
	kVocabulary = {};

	auto engine    = calculator::Engine();
	auto functions = engine.Functions();
	auto constants = engine.Constatnts();
//	auto operators       = engine.Operators();
//	auto op_exclude_func = std::vector<std::string>{};

	for (const auto &function:functions)
		if (function.size() > 1)
			kVocabulary.push_back(function);

	for (const auto &constant:constants)
		if (std::get<0>(constant).size() > 1)
			kVocabulary.push_back(std::get<0>(constant));

//	for (const auto &an_operator:operators)
//		if (!engine.IsFunction(std::get<0>(an_operator)))
//			op_exclude_func.push_back(std::get<0>(an_operator));
//
//	for (const auto &function:functions)
//		for (const auto &oef:op_exclude_func)
//			kVocabulary.push_back(oef + function);
//
//	for (const auto &constant:constants)
//		for (const auto &oef:op_exclude_func)
//			kVocabulary.push_back(oef + std::get<0>(constant));
}

char *CompletionGenerator(const char *text, int state) {
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

char **Completer(const char *text, int start, int end) {
	// Don't do filename completion even if our generator finds no matches.
	rl_attempted_completion_over = 1;

	// Note: returning nullptr here will make readline use the default filename
	// completer.
	return rl_completion_matches(text, CompletionGenerator);
}

auto Shell(const std::string &prompt) -> int {
	GenerateVocabulary();

	auto engine = calculator::Engine();

	rl_attempted_completion_function = Completer;
	char *buf = nullptr;

	while ((buf = readline(prompt.c_str())) != nullptr) {
		if (strlen(buf) > 0) {
			add_history(buf);
		}

		try {
			auto res = engine.Evaluate(buf);
			printf("%s = %f\n", buf, res);
		} catch (const std::runtime_error &re) {
			printf("Cannot evaluate %s: %s", buf, re.what());
		}
		
		// readline malloc'd the buffer; clean it up.
		free(buf);
	}
	return EXIT_SUCCESS;
}