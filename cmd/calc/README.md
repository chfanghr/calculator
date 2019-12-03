# calc

A simple, fast, and intuitive command-line calculator written in cpp.

## Usage
You can use calc in two ways: shell mode and command.

### Shell mode
This is probably the mode you'll want to use. It's like the python shell or irb.

### Command
You can also use calc to evaluate an expression with just a single command (i.e. without opening the shell). To do this, just use `calc [expression]`:
```bash
bash$ calc 1+1
2
bash$
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

~~The most important reason is that I'm quit familiar with compiler and I  want to show off :P~~<br>

The alternatives above are all great, and have their own advantages over calc. I highly recommend looking into these
 if you don't like how calc works.