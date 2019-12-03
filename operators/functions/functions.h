//
// Created by 方泓睿 on 2019/12/1.
//

#ifndef CALCULATOR_OPERATORS_FUNCTIONS_FUNCTIONS_H_
#define CALCULATOR_OPERATORS_FUNCTIONS_FUNCTIONS_H_

#include "operators/operators.h"

namespace calculator::operators::functions::standard {
using Operator=Engine::Operator;
const extern Operator kAbs;
const extern Operator kLog;
const extern Operator kLn;
const extern Operator kLg;
const extern Operator kSqrt;
const extern Operator kSin;
const extern Operator kCos;
const extern Operator kTan;
const extern Operator kCot;
const extern Operator kSec;
const extern Operator kCsc;
const extern Operator kAsin;
const extern Operator kAcos;
const extern Operator kAtan;
const extern Operator kAcot;
const extern Operator kAsec;
const extern Operator kAcsc;
}

#endif //CALCULATOR_OPERATORS_FUNCTIONS_FUNCTIONS_H_
