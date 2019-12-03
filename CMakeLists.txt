CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0)
PROJECT(calculator)

INCLUDE(Version.cmake)

SET(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(include)

OPTION(CODE_COVERAGE "Enable coverage reporting." OFF)
OPTION(BUILD_TESTING "Build the tests." ON)

IF (CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	ADD_DEFINITIONS(-fprofile-arcs -ftest-coverage)
	ADD_LINK_OPTIONS(--coverage)
ENDIF ()

IF (BUILD_TESTING)
	ENABLE_TESTING()
	FIND_PACKAGE(GTest REQUIRED)
	FIND_PACKAGE(Threads REQUIRED)
	INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})
ENDIF ()

ADD_LIBRARY(
		standard_operators OBJECT src/operators/operators.h src/operators/standard.cc
		src/operators/operators.cc)

ADD_LIBRARY(
		standard_functions OBJECT
		src/operators/functions/abs.cc src/operators/functions/functions.cc
		src/operators/functions/functions.h src/operators/functions/log.cc
		src/operators/functions/sqrt.cc src/operators/functions/trig.cc)

ADD_LIBRARY(
		standard_constants OBJECT src/constants/constants.cc
		src/constants/constants.h src/constants/standard.cc)

ADD_LIBRARY(token OBJECT src/compute/token/token.h src/compute/token/token.cc)

ADD_LIBRARY(compute OBJECT src/compute/compute.cc src/compute/stack.h
			src/compute/utils.cc src/compute/utils.h)

ADD_LIBRARY(engine OBJECT src/engine/engine.cc src/engine/engine.h
			src/engine/register.cc src/engine/history.cc)

ADD_LIBRARY(c_api OBJECT src/c_api/c_api.h src/c_api/c_api.cc)

ADD_LIBRARY(library_version OBJECT src/version.h _version.cc)

ADD_LIBRARY(
		calculator
		src/operators/operators.h
		src/operators/functions/functions.h
		src/constants/constants.h
		src/compute/token/token.h
		src/compute/stack.h
		src/compute/utils.h
		src/engine/engine.h
		src/c_api/c_api.h
		include/calculator.h
		$<TARGET_OBJECTS:standard_operators>
		$<TARGET_OBJECTS:standard_functions>
		$<TARGET_OBJECTS:standard_constants>
		$<TARGET_OBJECTS:token>
		$<TARGET_OBJECTS:compute>
		$<TARGET_OBJECTS:library_version>
		$<TARGET_OBJECTS:engine>
		$<TARGET_OBJECTS:c_api>
)

ADD_SUBDIRECTORY(examples)
ADD_SUBDIRECTORY(tests)
ADD_SUBDIRECTORY(cmd/calc)