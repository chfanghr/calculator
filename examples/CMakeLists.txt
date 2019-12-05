ADD_EXECUTABLE(simple simple/simple.cc)
TARGET_LINK_LIBRARIES(simple calculator)

ADD_EXECUTABLE(version version/version.cc)
TARGET_LINK_LIBRARIES(version calculator)

ADD_EXECUTABLE(call_c_api call_c_api/main.c)
TARGET_LINK_LIBRARIES(call_c_api calculator)