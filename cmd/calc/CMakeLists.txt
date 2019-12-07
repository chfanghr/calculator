ADD_EXECUTABLE(calc calc.cc shell_mode.cc calc.h expression_mode.cc utils.cc file_mode.cc)

TARGET_LINK_LIBRARIES(calc calculator)

INSTALL(
		TARGETS calc
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
		RUNTIME DESTINATION bin
)