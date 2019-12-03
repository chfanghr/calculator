INCLUDE(FindReadLine.cmake)

FIND_LIBRARY(Readline REQUIRED)

INCLUDE_DIRECTORIES(${Readline_INCLUDE_DIR})

ADD_EXECUTABLE(calc calc.cc shell.cc calc.h)

TARGET_LINK_LIBRARIES(calc calculator ${Readline_LIBRARY})