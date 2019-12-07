ADD_EXECUTABLE(calculator_tests calculator_tests.cc)
TARGET_LINK_LIBRARIES(calculator_tests calculator ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
ADD_TEST(NAME CALCULATOR_TESTS COMMAND calculator_tests)
