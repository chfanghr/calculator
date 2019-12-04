//
// Created by 方泓睿 on 2019/12/4.
//

#include "calc.h"

#include <calculator.h>

#include <iostream>

auto EnterExpressionsMode() -> int {
	auto engine = calculator::Engine();

	for (const auto &ele:kExtraOptions) {
		try {
			std::cout << engine.Evaluate(ele, kVerbose) << std::endl;
		} catch (const std::exception &re) {
			if (kStrict)
				Panic(std::string("Cannot evaluate ") + ele + ": " + re.what());

			if (kVerbose)
				std::cerr << "Cannot evaluate " << ele << ": " << re.what() << std::endl;
			else if (!kQuiet)
				std::cout << "Cannot evaluate due to error" << std::endl;

			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}