# Calculator [![CircleCI](https://circleci.com/gh/chfanghr/calculator.svg?style=svg)](https://circleci.com/gh/chfanghr/calculator)
This is a calculator which compiles an expression to vm bytecode then execute it. <br>

## Requirements
This library requires C++17 to build, including compiler and standard library support. <br>
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

## TODO
- [ ] More Uint Tests
- [ ] API Document
- [ ] More Examples
- [ ] Full Fill README
- [ ] CLI Application
- [ ] Benchmark
