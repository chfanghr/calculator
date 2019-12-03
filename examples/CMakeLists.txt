ADD_EXECUTABLE(simple simple/main.cc)
TARGET_LINK_LIBRARIES(simple calculator)

ADD_EXECUTABLE(version version/version.cc)
TARGET_LINK_LIBRARIES(version calculator)