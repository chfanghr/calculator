# Calculator
This is a calculator which compiles a expression to vm bytecode then execute it. <br>
Note that this project is still at beta stage.
## Build examples
```bash
mkdir build
cd build
cmake ..
make -j8
```
The examples will be built by default, you will see them in your build folder.<br>
Execute the [`simple`](examples/simple/simple.cc) example as below:
```bash
# In your build folder ....
examples/simple
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
```
## TODO
- [ ] Uint Tests
- [ ] API Document
- [ ] More Examples
- [ ] Full Fill README
- [ ] CLI Application
