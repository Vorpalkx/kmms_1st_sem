#pragma once

#include "time_sort_test.hpp"

#include <fstream>

namespace STram {
  void time_sort(
    const SortInfo* sort,
    int* const arr,
    const int size,
    std::ofstream& file
  );
  void generate_array(int* const arr, const int size);
}
