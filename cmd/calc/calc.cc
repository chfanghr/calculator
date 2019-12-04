//
// Created by 方泓睿 on 2019/12/3.
//

#include "calc.h"

auto main(int argc, char **argv) -> int {
	ParseCommandLineOptions(argc, argv);

	if (kForceShellMode)
		exit(EnterShellMode(kPrompt));
	else if (kForceExpressionMode)
		exit(EnterExpressionsMode());
	else if (kForceFileMode)
		exit(EnterFileMode());

	Panic("No mode to enter. This is a bug, please open an issue.");
}