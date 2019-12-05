INCLUDE(FindReadLine.cmake)

FIND_LIBRARY(Readline REQUIRED)

INCLUDE_DIRECTORIES(${Readline_INCLUDE_DIR})

ADD_EXECUTABLE(calc calc.cc shell_mode.cc calc.h expression_mode.cc utils.cc file_mode.cc)

LINK_DIRECTORIES($ENV{LD_LIBRARY_PATH})

TARGET_LINK_LIBRARIES(calc calculator termcap ${Readline_LIBRARY} ncurses)