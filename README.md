# Calculator [![CircleCI](https://circleci.com/gh/chfanghr/calculator.svg?style=svg)](https://circleci.com/gh/chfanghr/calculator)
`calculator` is a **Zero Dependency** **C++17** library. Frankly, the purpose of this library is to evaluate any common math expression 
with high speed and low memory cost. 
To achieve this, I implemented an engine which compiles math expressions 
to **VM bytecode** so that the expressions can be evaluated in VM effectively. <br>

Note That although this library is written in cpp, it provides **untested** C-APIs. Just have a try :P.

## Features: Support standard functions, operators, and constants
`calculator` supports all the standard stuff, and I'm definitely adding more later (also feel free to fork and add
 your own!) .
 
 ### Operators
 `+`, `-`, `*`, `/`, `^`, `%`
 
 ### Functions
 `sin`, `cos`, `tan`, `cot`, `sec`, `csc`, `asin`, `acos`, `atan`, `acot`, `asec`, `acsc`, `sqrt`, `log`, `lg`, `ln`, `abs`
 
 ### Constants
 `e`, `pi`
 
 ### History
 Previous results can be accessed with the `@` symbol. A single `@` returns the result of the last computation, while
  multiple `@` gets the n<sup>th</sup> last result, where n is the number of `@`s used (for example, `@@` returns the
   second-last result, `@@@@@` returns the fifth-last result).
 
## Requirements
This library requires **C++17** to build, including compiler and standard library support. <br>
So the following minimum versions will be required to build the library:
* GCC 7
* Clang 5
* VS 2017 15.3

...And the `cmake` and `make` tools:
* cmake 3.1.0
* make 4.0.0

If you want to build tests(which is enable by default), you should also install Google Test framework on your machine.
 
## Build
```bash
cmake -H. -Bbuild
cmake --build build
```
This will create a `build` folder in the project root, and build the project inside it.

If you don't want to build tests, replace the first command with:
```bash
cmake -DBUILD_TESTING=OFFF -H. -Bbuild
``` 

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
examples/version
``` 
You'll see
```
❯ examples/simple
1+1=2
1*3+2=5
0+9/3=3
(1+3)/2=2
abs(-1.12334)=1.12334
1.45*44%3=0.8
(1+4)/cos(3.1415926)=-5
@+1=-4
@@+1=-4
acos(1)*@=-0
❯ examples/version
version = master:3268dc9+: # Or something else...
```

## CLI App: `calc`
**Usable but still Experimental**, check out [calc](cmd/calc/README.md)

## TODO
- [ ] More Uint Tests
- [ ] API Document
- [ ] More Examples
- [ ] Full Fill README
- [ ] CLI Application (Working in progress, check out [calc](cmd/calc/README.md))
- [ ] Benchmark

## Note: When you failed to build....
* Check if your compiler/tools meet the requirements
* If you're on Windows.... Sorry, I cannot help you cause I have no machine running Windows...
* Any way, feel free to open an issue, but please post the full detail%)....

## LICENSE
MIT, check [LICENSE](LICENSE) for more details.
