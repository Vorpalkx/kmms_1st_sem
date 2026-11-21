add_subdirectory(sortings)

add_executable(sort_mf 
  time_sort_test.cpp
  time_sort_functions.cpp
  time_sort_items.cpp
)

target_compile_definitions(sort_mf PRIVATE
  PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}"
)

target_link_libraries(sort_mf PRIVATE
    sort_lib
)
