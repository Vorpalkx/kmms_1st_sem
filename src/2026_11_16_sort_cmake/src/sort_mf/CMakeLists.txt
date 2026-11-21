project(sort_mf)

add_subdirectory(sortings)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE
sort_lib)
