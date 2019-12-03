CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(calculator)

SET(CMAKE_CXX_STANDARD 17)

ADD_LIBRARY(standard_operators operators/operators.h operators/standard.cc)

ADD_EXECUTABLE(calculator main.cpp operators/operators.h operators/operators.cc operators/standard.cc operators/functions/abs.cc operators/functions/functions.cc operators/functions/functions.h operators/functions/log.cc operators/functions/sqrt.cc operators/functions/trig.cc constants/standard.cc compute/compute.cc compute/token/token.cc compute/token/token.h compute/utils.cc compute/utils.h engine.cc compute/stack.h engine.h operators/operators.cc constants/constants.h constants/constants.cc history.cc register.cc)

INCLUDE_DIRECTORIES(./)