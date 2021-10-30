cmake_minimum_required(VERSION 3.0)
project(libcborg VERSION 0.1.0 LANGUAGES C)

# BUILD
set(CMAKE_C_FLAGS "-std=c99 -Wall -Wextra -pedantic")
option(COVERAGE "Enable code coverage" OFF)
if(COVERAGE)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fprofile-arcs -ftest-coverage --coverage")
endif(COVERAGE)


# INSTALL
include(GNUInstallDirs)

# SOURCE CODE
add_subdirectory(src)
add_subdirectory(include)

# TESTS
include(CTest)
add_subdirectory(tests)

# CPACK
set(CPACK_GENERATOR "DEB" "TGZ" "RPM")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Adil Benhlal")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
include(CPack)

# UNINSTALL
# source: https://gitlab.kitware.com/cmake/community/-/wikis/FAQ#can-i-do-make-uninstall-with-cmake
if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
