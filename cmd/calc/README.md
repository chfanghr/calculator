# calc

A simple, fast, and intuitive command-line calculator written in cpp.<br>
![calc_screenshot](../../doc/img/calc_screenshot.png)

## Requirements
* Of course, `make`, `cmake`, cpp17 compiler,etc...
* The GNU's `libreadline`
    * If you're using osx - Then you need to do nothing. Just build it and enjoy!
    * If you're using ubuntu(or other debian based system) - If you're facing compilation issue, try to run this
     command in your terminal: `sudo apt install -y libreadline-dev` then have another shot. 
     * If you are on Windows .... Oh, Sorry. You have to find yourself a solution cause the developer have no machine
      running Windows :D.
     
## Usage
You can use calc in three ways: shell mode ,expression mode and file mode.

### Shell Mode
This is probably the mode you'll want to use. It's like the python shell or irb. **THIS MODE COMES WITH
Auto-COMPLETION (Just press `TAB`)**
```
❯ calc
> 1+1
2
> 3(5/(3-4))
-15
> 3pi^2
29.608813203268074
> @+1
30.608813203268074
> @@@*2
-30
> ln(-1)
NaN
```

### Expression Mode
You can also use calc to evaluate an expression with just a single command (i.e. without opening the shell). To do this, just use `calc [expression]`:
```
❯ calc 1+1
2
```

### File Mode
`calc` will evaluate expressions store in the files. Each line in the file will be considered as an expression
, unless the line is begin with `#`. <br>
An explicit `-f` option will be required to enable this mode:
```
❯ printf "1+1\n#1+1 should be 2\n cos(pi)" > input
❯ calc -f input
2
-1
```

## Why not use .....
* Google
    * Doesn't work without an internet connection
    * Slower
    * Doesn't show previous computations, so you end up with multiple tabs open at once.
* Spotlight (on OS X) (Yes I got a mac and I finished this project on it...)
    * No history
    * Switching between Spotlight and other windows isn't too fun
* Python/IRB
    * Requires use of a separate math module for most functions and constants 
    * A little bit slower to start up
* `bc`
    * Limited number of built-in functions; these have shortened (not too intuitive) names as well.

~~The most important reason is that I'm quite familiar with compiler and I  want to show off :P~~<br>

The alternatives above are all great, and have their own advantages over calc. I highly recommend looking into these
 if you don't like how calc works.
