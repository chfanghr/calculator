EXECUTE_PROCESS(
        COMMAND git log --pretty=format:'%h' -n 1
        OUTPUT_VARIABLE GIT_REV
        ERROR_QUIET)

# Check whether we got any revision (which isn't always the case, e.g. when
# someone downloaded a zip file from Github instead of a checkout)
IF ("${GIT_REV}" STREQUAL "")
  SET(GIT_REV "N/A")
  SET(GIT_DIFF "")
  SET(GIT_TAG "N/A")
  SET(GIT_BRANCH "N/A")
ELSE ()
  EXECUTE_PROCESS(COMMAND bash -c "git diff --quiet --exit-code || echo +"
                  OUTPUT_VARIABLE GIT_DIFF)
  EXECUTE_PROCESS(
          COMMAND git describe --exact-match --tags
          OUTPUT_VARIABLE GIT_TAG
          ERROR_QUIET)
  EXECUTE_PROCESS(COMMAND git rev-parse --abbrev-ref HEAD
                  OUTPUT_VARIABLE GIT_BRANCH)

  STRING(STRIP "${GIT_REV}" GIT_REV)
  STRING(SUBSTRING "${GIT_REV}" 1 7 GIT_REV)
  STRING(STRIP "${GIT_DIFF}" GIT_DIFF)
  STRING(STRIP "${GIT_TAG}" GIT_TAG)
  STRING(STRIP "${GIT_BRANCH}" GIT_BRANCH)
ENDIF ()

SET(VERSION
    "const char* GIT_REV=\"${GIT_REV}${GIT_DIFF}\";
const char* GIT_TAG=\"${GIT_TAG}\";
const char* GIT_BRANCH=\"${GIT_BRANCH}\";")

IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/_version.cc)
  FILE(READ ${CMAKE_CURRENT_SOURCE_DIR}/_version.cc VERSION_)
ELSE ()
  SET(VERSION_ "")
ENDIF ()

IF (NOT "${VERSION}" STREQUAL "${VERSION_}")
  FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/_version.cc
       "// Generated by Version.cmake, DO NOT EDIT\n")
  FILE(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/_version.cc "${VERSION}")
ENDIF ()
