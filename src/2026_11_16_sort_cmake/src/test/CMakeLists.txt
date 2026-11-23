set(SORT_TESTS
    bubble_sort_classic
    bubble_sort_early_exit
    bubble_sort_early_exit_opt
    shaker_sort
    shaker_sort_opt
    odd_even_sort
    comb_sort
    selection_sort
    insert_sort
    insert_sort_opt
    shell_sort
)

foreach(SORT_NAME ${SORT_TESTS})
    set(TEST_TARGET "${SORT_NAME}_test")

    add_executable(${TEST_TARGET} "${SORT_NAME}_test.cpp")
    target_link_libraries(${TEST_TARGET} PRIVATE
        gtest
        sort_lib
    )

    add_test(NAME ${SORT_NAME} COMMAND ${TEST_TARGET})
endforeach()
