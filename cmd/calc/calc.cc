//
// Created by 方泓睿 on 2019/12/3.
//

#include "calc.h"

#include <getopt.h>

auto main(int argc, char **argv) -> int {
	kVerbose = false;

	int c;
	while ((c = getopt(argc, argv, "qvVsih")) != -1) {
		switch (c) {
			case 'q': kVerbose = false;
				kQuiet           = true;
				break;
			case 'v': exit(ShowVersion());
			case 'V' : kVerbose = true;
				kQuiet            = false;
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
		exit(Shell("> "));
	else
		exit(ParseAndEvaluate(to_eval));
}