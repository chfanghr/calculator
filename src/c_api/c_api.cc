//
// Created by 方泓睿 on 2019/12/3.
//

#include "src/engine/engine.h"
#include "c_api.h"

#include <cmath>
#include <stdexcept>
#include <cstring>

#ifdef __cplusplus
extern "C" {
#endif

struct Engine {
	calculator::Engine engine;
	EngineStatusCode   status{};
	const char         *error_message{};
};

Engine *NewEngine() {
	return new Engine;
}

EngineStatusCode FreeEngine(Engine *engine) {
	if (!engine)
		return kEngineNullPointer;
	delete engine;
	return kEngineOk;
}

EngineStatusCode IsOk(Engine *engine) {
	if (!engine)
		return kEngineNullPointer;
	return engine->status;
}

double Evaluate(Engine *engine, const char *expression) {
	if (!engine)
		return NAN;
	double res = NAN;
	try {
		res = engine->engine.Evaluate(expression);
	} catch (std::runtime_error &re) {
		engine->error_message = re.what();
		engine->status        = kEngineException;
	} catch (...) {
		engine->error_message = "Unknown error";
		engine->status        = kEngineException;
	}
	return res;
}

const char *GetErrorMessage(Engine *engine) {
	if (!engine)
		return nullptr;
	return engine->error_message;
}

void ClearError(Engine *engine) {
	if (!engine)
		return;
	engine->error_message = "";
	engine->status        = kEngineOk;
}

char *Version() {
	return strdup(calculator::Engine::Version().c_str());
}

#ifdef __cplusplus
}

auto GetEngine(Engine *engine) -> calculator::Engine & {
	if (!engine)
		throw std::runtime_error("Invalid nullptr access.");
	return engine->engine;
}

#endif