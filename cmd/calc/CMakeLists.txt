INCLUDE(FindReadLine.cmake)

FIND_LIBRARY(Readline REQUIRED)

INCLUDE_DIRECTORIES(${Readline_INCLUDE_DIR})

ADD_EXECUTABLE(calc calc.cc shell.cc calc.h non_interactive.cc utils.cc)

TARGET_LINK_LIBRARIES(calc calculator ${Readline_LIBRARY})