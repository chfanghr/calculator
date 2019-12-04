//
// Created by 方泓睿 on 2019/12/3.
//

#include "calc.h"

#include <calculator.h>
#include <getopt.h>
#include <iostream>

#include <signal.h>

auto ShowVersion() -> int {
	std::cout << "calc version " << calculator::Engine::Version() << std::endl;
	return EXIT_SUCCESS;
}

auto ShowHelpMessage() -> void {
	// TODO
}

auto main(int argc, char **argv) -> int {
	signal(SIGINT, IntHandler);

	kVerbose = false;

	int c;
	while ((c = getopt(argc, argv, "qvsih")) != -1) {
		switch (c) {
			case 'q': kQuiet = true;
				break;
			case 'v': exit(ShowVersion());
			case 'V' : kVerbose = true;
				break;
			case 's': kStrict = true;
				break;
			case 'i': kForceInteractive = true;
			default: ShowHelpMessage();
				return EXIT_FAILURE;
		}
	}

	std::string to_eval{};

	for (auto index = optind; index < argc; index++) {
		to_eval += argv[index];
		to_eval += ";";
	}

	to_eval = TrimSpace(to_eval);

	if (to_eval.empty())
		kForceInteractive = true;

	if (kForceInteractive)
		exit(Shell(">> "));
	else
		exit(ParseAndEvaluate(to_eval));
}