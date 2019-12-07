//
// Created by 方泓睿 on 2019/12/1.
//

#ifndef CALCULATOR__OPERATORS_OPERATORS_H_
#define CALCULATOR__OPERATORS_OPERATORS_H_

#include <calculator/engine/engine.h>

namespace calculator::operators::standard {
using Operator=Engine::Operator;
extern const Operator kAdd;
extern const Operator kSub;
extern const Operator kNeg;
extern const Operator kMul;
extern const Operator kDiv;
extern const Operator kMod;
extern const Operator kPow;
}

#endif