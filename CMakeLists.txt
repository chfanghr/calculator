CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(calculator)

SET(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE(calculator main.cpp operators/operators.h operators/operators.cc operators/standard.cc operators/functions/abs.cc operators/functions/functions.cc operators/functions/functions.h operators/functions/log.cc operators/functions/sqrt.cc operators/functions/trig.cc constants/constants.cc constants/constants.h constants/standard.cc compute/compute.cc compute/compute.h compute/token/token.cc compute/token/token.h compute/utils.cc compute/utils.h init.cc operators/functions/registers.h operators/registers.h compute/history.cc compute/history.h compute/stack.h)

INCLUDE_DIRECTORIES(./)