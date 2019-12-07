//
// Created by 方泓睿 on 2019/12/5.
//

#include <calculator/calculator.h>

#include <stdio.h>
#include <stdlib.h>

void EvaluateAndShow(Engine *engine, const char *in) {
	printf("%s=%f\n", in, Evaluate(engine, in));
}

int main() {
	Engine *engine = NewEngine();
	if (!engine) {
		printf("[PANIC] Cannot create new engine\n");
		return EXIT_FAILURE;
	}
	EvaluateAndShow(engine, "1+1");
	EvaluateAndShow(engine, "pi");
	return EXIT_SUCCESS;
}