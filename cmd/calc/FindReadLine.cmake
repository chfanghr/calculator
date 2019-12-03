# - Try to find readline include dirs and libraries
#
# Usage of this module as follows:
#
#     FIND_PACKAGE(Readline)
#
# Variables used by this module, they can change the default behaviour and need
# to be set before calling find_package:
#
#  Readline_ROOT_DIR         Set this variable to the root installation of
#                            readline if the module has problems finding the
#                            proper installation path.
#
# Variables defined by this module:
#
#  READLINE_FOUND            System has readline, include and lib dirs found
#  Readline_INCLUDE_DIR      The readline include directories.
#  Readline_LIBRARY          The readline library.

FIND_PATH(Readline_ROOT_DIR
		  NAMES include/readline/readline.h
		  )

FIND_PATH(Readline_INCLUDE_DIR
		  NAMES readline/readline.h
		  HINTS ${Readline_ROOT_DIR}/include
		  )

FIND_LIBRARY(Readline_LIBRARY
			 NAMES readline
			 HINTS ${Readline_ROOT_DIR}/lib
			 )

IF (Readline_INCLUDE_DIR AND Readline_LIBRARY AND Ncurses_LIBRARY)
	SET(READLINE_FOUND TRUE)
ELSE (Readline_INCLUDE_DIR AND Readline_LIBRARY AND Ncurses_LIBRARY)
	FIND_LIBRARY(Readline_LIBRARY NAMES readline)
	INCLUDE(FindPackageHandleStandardArgs)
	FIND_PACKAGE_HANDLE_STANDARD_ARGS(Readline DEFAULT_MSG Readline_INCLUDE_DIR Readline_LIBRARY)
	MARK_AS_ADVANCED(Readline_INCLUDE_DIR Readline_LIBRARY)
ENDIF (Readline_INCLUDE_DIR AND Readline_LIBRARY AND Ncurses_LIBRARY)

MARK_AS_ADVANCED(
		Readline_ROOT_DIR
		Readline_INCLUDE_DIR
		Readline_LIBRARY
)