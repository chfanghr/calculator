CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0)
PROJECT(calculator)

INCLUDE(cmake/Version.cmake)

SET(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(include)

OPTION(CODE_COVERAGE "Enable coverage reporting." OFF)
OPTION(BUILD_TESTS "Build the tests." ON)
OPTION(BUILD_CALC "Build the calc" ON)

IF (CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	ADD_DEFINITIONS(-fprofile-arcs -ftest-coverage)
	ADD_LINK_OPTIONS(--coverage)
ENDIF ()

IF (BUILD_TESTS)
	ENABLE_TESTING()
	FIND_PACKAGE(GTest REQUIRED)
	FIND_PACKAGE(Threads REQUIRED)
	INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})
	ADD_SUBDIRECTORY(tests)
ENDIF ()

ADD_LIBRARY(
		standard_operators OBJECT include/calculator/operators/operators.h src/operators/standard.cc
		src/operators/operators.cc)

ADD_LIBRARY(
		standard_functions OBJECT
		src/operators/functions/abs.cc src/operators/functions/functions.cc
		include/calculator/operators/functions/functions.h src/operators/functions/log.cc
		src/operators/functions/sqrt.cc src/operators/functions/trig.cc)

ADD_LIBRARY(
		standard_constants OBJECT src/constants/constants.cc
		include/calculator/constants/constants.h src/constants/standard.cc)

ADD_LIBRARY(token OBJECT include/calculator/compute/token/token.h src/compute/token/token.cc)

ADD_LIBRARY(compute OBJECT src/compute/compute.cc include/calculator/compute/stack.h
			src/compute/utils.cc include/calculator/compute/utils.h)

ADD_LIBRARY(engine OBJECT src/engine/engine.cc include/calculator/engine/engine.h
			src/engine/register.cc src/engine/history.cc)

ADD_LIBRARY(c_api OBJECT include/calculator/c_api/c_api.h src/c_api/c_api.cc)

ADD_LIBRARY(library_version OBJECT include/calculator/version.h src/_version.cc)

ADD_LIBRARY(
		calculator
		include/calculator/operators/operators.h
		include/calculator/operators/functions/functions.h
		include/calculator/constants/constants.h
		include/calculator/compute/token/token.h
		include/calculator/compute/stack.h
		include/calculator/compute/utils.h
		include/calculator/engine/engine.h
		include/calculator/c_api/c_api.h
		include/calculator/calculator.h
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

IF (BUILD_CALC)
	ADD_SUBDIRECTORY(cmd/calc)
ENDIF ()

INSTALL(
		TARGETS calculator
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
		RUNTIME DESTINATION bin
)

install(DIRECTORY include/calculator DESTINATION include)