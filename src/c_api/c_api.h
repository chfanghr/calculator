//
// Created by 方泓睿 on 2019/12/3.
//

#ifndef CALCULATOR_SRC_C_API_C_API_H_
#define CALCULATOR_SRC_C_API_C_API_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	kEngineOk,
	kEngineNullPointer,
	kEngineException
} EngineStatusCode;

struct Engine;

Engine *NewEngine();

EngineStatusCode FreeEngine(Engine *engine);

EngineStatusCode IsOk(Engine *engine);

const char *GetErrorMessage(Engine *engine);

double Evaluate(Engine *engine, const char *expression);

void ClearError(Engine *engine);

char *Version();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include "src/engine/engine.h"

auto GetEngine(Engine *engine) -> calculator::Engine &;
#endif

#endif //CALCULATOR_SRC_C_API_C_API_H_
