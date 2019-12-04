//
// Created by 方泓睿 on 2019/12/3.
//

#include "calc.h"

#include <calculator.h>
#include <getopt.h>
#include <iostream>

auto ShowVersion() -> int {
	std::cout << "calc version " << calculator::Engine::Version() << std::endl;
	return EXIT_SUCCESS;
}

auto main(int argc, char **argv) -> int {
	kVerbose = false;
	int c;
	while ((c = getopt(argc, argv, "qvs")) != -1) {
		switch (c) {
			case 'q': kQuiet = true;
				break;
			case 'v': exit(ShowVersion());
			case 'V' : kVerbose = true;
				break;
			case 's': kStrict = true;
				break;
			default:;
		}
	}

	return Shell(">> ");
}