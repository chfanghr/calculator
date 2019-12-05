//
// Created by 方泓睿 on 2019/12/4.
//


#include "calc.h"

#include <calculator.h>
#include <getopt.h>
#include <iostream>

bool                     kQuiet               = false;
bool                     kStrict              = false;
bool                     kVerbose             = false;
bool                     kForceShellMode      = false;
bool                     kForceFileMode       = false;
bool                     kForceExpressionMode = false;
volatile bool            kShouldExit          = false;
std::string              kPrompt              = "> "; // NOLINT(cert-err58-cpp)
std::vector<std::string> kExtraOptions        = {};
calculator::Engine       kEngine;;

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
	std::cout << "Copyright 2019 chfanghr@gmail.com." << std::endl;
}

auto ShowVersion() -> void {
	std::cout << "calc version " << calculator::Engine::Version() << std::endl;
}

auto ShowHelpMessage() -> void {
	auto ShowOption = [](char opt, const std::string &desc) -> void {
		std::cout << "	-" << opt << "			" << desc << std::endl;
	};
	ShowBanner();
	std::cout << std::endl << "Options: " << std::endl;

	ShowOption('h', "Show this help message and then exit.");
	ShowOption('v', "Show version of calc and then exit.");
	ShowOption('q', "Quiet mode: don't print banner while startup as wel as disable  warning and diagnostic messages.");
	ShowOption('f', "File mode. Make calc to treat the arguments which are not parsed as file path and evaluate "
									"expressions store in the files.");
	ShowOption('P', "Set the prompt for shell mode. Require one argument. The default prompt is '> '.");
	ShowOption('p', "Disable prompt.");
	ShowOption('V', "Verbose mode: show more debug information.");
	ShowOption('e', "Expression mode: force calc to enter expression mode.");
	ShowOption('i', "Interactive mode: force calc to enter shell mode.");
}

auto ParseCommandLineOptions(int argc, char **argv) -> void {
	int c;
	// q quiet
	// V verbose
	// v version
	// s strict
	// i force interactive
	// h help
	// P set prompt
	// p no prompt
	// f force file mode
	// e force expression mode
	while ((c = getopt(argc, argv, "qvVsihP:pfe")) != -1) {
		switch (c) {
			case 'h':;
				ShowHelpMessage();
				exit(EXIT_SUCCESS);
			case 'q':;
				kVerbose = false;
				kQuiet   = true;
				break;
			case 'v': ShowVersion();
				exit(EXIT_SUCCESS);
			case 'V' :;
				kVerbose = true;
				kQuiet   = false;
				break;
			case 's':;
				kStrict = true;
				break;
			case 'i':;
				kForceShellMode      = true;
				kForceFileMode       = false;
				kForceExpressionMode = false;
				break;
			case 'p':;
				kPrompt = "";
				break;
			case 'P':;
				kPrompt = optarg;
				kPrompt += " ";
				break;
			case 'f':;
				kForceShellMode      = false;
				kForceFileMode       = true;
				kForceExpressionMode = false;
				break;
			case 'e':;
				kForceShellMode      = false;
				kForceFileMode       = false;
				kForceExpressionMode = true;
				break;
			case '?':;
				if (optopt == 'P')
					Panic("Option -P requires an argument.");
			default:;
				std::cout << "Unknown option " << std::endl;
				ShowHelpMessage();
				exit(EXIT_FAILURE);
		}
	}

	for (auto index = optind; index < argc; index++)
		kExtraOptions.emplace_back(argv[index]);

	if (kExtraOptions.empty()) {
		if (kForceExpressionMode || kForceFileMode)
			Panic("Cannot start expression/file mode cause no expression/file provided.");
		kForceShellMode = true;
	} else if (!(kForceShellMode || kForceFileMode || kForceExpressionMode))
		kForceExpressionMode = true;
}