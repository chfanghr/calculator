# Calculator [![CircleCI](https://circleci.com/gh/chfanghr/calculator.svg?style=svg)](https://circleci.com/gh/chfanghr/calculator)
`calculator` is a **Zero Dependency** library which compiles an expression to **VM bytecode** then execute it. <br>
Note That although this library is a cpp library, it provides an **untested** C-api. Just have a try :P.

## Features: Support standard functions, operators, and constants
`calculator` supports all the standard stuff, and I'm definitely adding more later (also feel free to fork and add
 your own!) .
 
 ### Operators
 `+`,`-`, `*`, `/`, `^`, `%`
 
 ### Functions
 `sin`, `cos`, `tan`, `cot`, `sec`, `csc`, `asin`, `acos`, `atan`, `acot`, `asec`, `acsc`, `sqrt`, `log`, `lg`, `ln`, `abs`
 
 ### Constants
 `e`, `pi`
 
 ### History
 Previous results can be accessed with the `@` symbol. A single `@` returns the result of the last computation, while multiple @ gets the nth last result, where n is the number of `@`s used (for example, `@@` returns the second-last result, `@@@@@` returns the fifth-last result).
 
## Requirements
This library requires **C++17** to build, including compiler and standard library support. <br>
So the following minimum versions will be required to build the library:
* GCC 7
* Clang 5
* VS 2017 15.3

## Build
```bash
cmake -H. -Bbuild
cmake --build build
```
This will create a `build` folder in the project root.

## Tests
The tests will be built by default. To run it(for now there is only one test, more tests will be added soon ):
```bash
cd build
make test
## or
tests/*tests
```
You'll see:
```
❯ make test
Running tests...
Test project /Users/fanghr/CLionProjects/calculator/cmake-build-debug
    Start 1: CALCULATOR_TESTS
1/1 Test #1: CALCULATOR_TESTS .................   Passed    1.13 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   1.15 sec
```

## Examples
The examples will be built by default, you will see them in your build folder.<br>
Execute the [`simple`](examples/simple/simple.cc) example as below:

```bash
cd build
examples/simple
example/version
``` 
You'll see
```
❯ examples/simple
2
5
3
2
1.12334
0.8
-5
-4
-4
❯ examples/version
version = master:3268dc9+: # Or something else...
```

## CLI App: `cloc`
In progress, check out [calc](cmd/calc/README.md)

## TODO
- [ ] More Uint Tests
- [ ] API Document
- [ ] More Examples
- [ ] Full Fill README
- [ ] CLI Application (In progress, check out [calc](cmd/calc/README.md))
- [ ] Benchmark
