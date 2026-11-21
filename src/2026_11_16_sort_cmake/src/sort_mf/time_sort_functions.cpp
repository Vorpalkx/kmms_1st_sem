#include "time_sort_functions.hpp"

#include <chrono>
#include <cstdlib>
#include <fstream>

namespace {
  void arr_copy(int* const original, int* const copy, const int size) {
    for (int i = 0; i < size; i++) {
      copy[i] = original[i];
    }
  }
}

namespace STram {
  void generate_array(int* const arr, const int size) {
    for (int i = 0; i < size; i++) {
      arr[i] = std::rand() % size;
    }
  }

  void time_sort(
      const SortInfo* sort,
      int* const arr,
      const int size,
      std::ofstream& file
  ) {
    int *copy = new int [ size ];
    arr_copy(arr, copy, size);

    auto start =
      std::chrono::high_resolution_clock::now();
    sort->sort(copy, size);
    auto end =
      std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> sec = end - start;

    file << sort->sort_name << " " << size << " = " << sec.count() << "s\n";

    delete[] copy;
  }
}
