# LIBCBORG
file(GLOB_RECURSE SRC "*.c")
file(GLOB_RECURSE HEADER "${CMAKE_SOURCE_DIR}/include/*.h")
add_library(cborg ${SRC} ${HEADER})
target_link_libraries(cborg PUBLIC cborg-h)
install(TARGETS cborg DESTINATION ${CMAKE_INSTALL_LIBDIR})
