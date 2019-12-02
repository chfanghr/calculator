# Calculator
This is a calculator which compiles a expression to vm bytecode then execute it. <br>
Here is an example:
```cpp
#include "compute/compute.h"

#include <iostream>

auto main() -> int {
	std::cout << Evaluate("1+1") << std::endl;
	std::cout << Evaluate("1*3+2") << std::endl;
	std::cout << Evaluate("0+9/3") << std::endl;
	std::cout << Evaluate("(1+3)/2") << std::endl;
	std::cout << Evaluate("abs(1.12334)") << std::endl;
	std::cout << Evaluate("1.45*44%3") << std::endl;
	std::cout << Evaluate("(1+4)/cos(3.1415926)") << std::endl;
	std::cout << Evaluate("@+1") << std::endl;
	std::cout << Evaluate("@@+1") << std::endl;
	return EXIT_SUCCESS;
}
```
Run it, you will see:
```bash
2
5
3
2
1.12334
0.8
-5
-4
-4
```