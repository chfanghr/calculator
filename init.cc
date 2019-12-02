//
// Created by 方泓睿 on 2019/12/2.
//

#include "operators/operators.h"

__attribute__((constructor, used))
auto Init() -> void {
	InitOperators();
}