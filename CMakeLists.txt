cmake_minimum_required(VERSION 3.8)
project(regexp)

set(CXX_STANDARD 11)
add_subdirectory(src)
add_subdirectory(test)
enable_testing()

add_test(NAME regexp_test COMMAND regexp_test)