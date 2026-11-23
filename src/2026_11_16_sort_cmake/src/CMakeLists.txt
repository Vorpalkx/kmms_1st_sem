cmake_minimum_required(VERSION 3.2...3.27.5)

project(sort_project)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(sort_mf)
add_subdirectory(test)
