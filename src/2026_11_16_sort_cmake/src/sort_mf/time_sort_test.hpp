#pragma once

namespace STram {
  struct SortInfo {
    const char* const sort_name;
    void (*sort)(int* arr, int size);
  };
}
