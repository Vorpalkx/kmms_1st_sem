#include "sort.hpp"

#include <algorithm>
#include <utility>

void biv::bubble_sort_classic(int* arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void biv::bubble_sort_early_exit(int* arr, const int size) {
  bool is_swapped;
  int i = 0;
  do {
    is_swapped = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        is_swapped = true;
      }
    }
    i++;
  } while (is_swapped);
}

void biv::bubble_sort_early_exit_opt(int* arr, const int size) {
  bool is_swapped;
  int end = size - 1;
  do {
    int temp = 0;
    is_swapped = false;
    for (int j = 0; j < end; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        is_swapped = true;
        temp = j + 1;
      }
    }
    end = temp;
  } while (is_swapped);
}

void biv::shaker_sort(int* arr, const int size) {
  int begin = 0;
  int end = size - 1;
  bool is_swapped = true;

  while (is_swapped) {
    is_swapped = false;
    for (int i = begin; i < end; i++) {
      if (arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);
        is_swapped = true;
      }
    }
    end--;

    if (!is_swapped) break;

    is_swapped = false;
    for (int i = end; i > begin; i--) {
      if (arr[i] < arr[i - 1]) {
        std::swap(arr[i], arr[i - 1]);
        is_swapped = true;
      }
    }
    begin++;
  }
}

void biv::shaker_sort_opt(int* arr, const int size) {
  int begin = 0;
  int end = size - 1;
  bool is_swapped = true;

  while (is_swapped) {
    is_swapped = false;
    int temp;
    for (int i = begin; i < end; i++) {
      if (arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);
        is_swapped = true;
        temp = i + 1;
      }
    }

    if (!is_swapped) break;

    end = temp;

    is_swapped = false;
    for (int i = end; i > begin; i--) {
      if (arr[i] < arr[i - 1]) {
        std::swap(arr[i], arr[i - 1]);
        is_swapped = true;
        temp = i - 1;
      }
    }
    begin = temp;
  }
}

void biv::odd_even_sort(int* arr, const int size) {
  bool is_swapped;
  do {
    is_swapped = false;
    for (int j = 0; j < size - 1; j += 2) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        is_swapped = true;
      }
    }
    for (int j = 1; j < size - 1; j += 2) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        is_swapped = true;
      }
    }
  } while (is_swapped);
}

void biv::comb_sort(int* arr, const int size) {
  if (size < 2) return;

  double factor = 1.25;
  int step = size - 1;

  bool is_swapped = true;

  while (step > 1 || is_swapped) {
    is_swapped = false;
    for (int i = 0; i + step < size; i++) {
      if (arr[i] > arr[i + step]) {
        std::swap(arr[i], arr[i + step]);
        is_swapped = true;
      }
    }

    if (step > 1) {
      step /= factor;
      is_swapped = true;
    }
  }
}

void biv::selection_sort(int* arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      int t = arr[i];
      arr[i] = arr[min];
      arr[min] = t;
    }
  }
}

void biv::insert_sort(int* arr, const int size) {
  for (int i = 1; i < size; i ++) {
    int j = i;
    int x = arr[j];
    while (j > 0 && x < arr[j - 1]) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = x;
  }
}

void biv::insert_sort_opt(int* arr, const int size) {
  for (int i = 1; i < size; i ++) {
    int x = arr[i];

    int begin = 0;
    int end = i - 1;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (x < arr[mid]) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    if (x < arr[begin]) {
      for (int j = i; j > begin; j--) {
        arr[j] = arr[j - 1];
      }
      arr[begin] = x;
    }
  }
}

void biv::shell_sort(int* arr, const int size) {
  int step = size / 2;
  while (step > 0) {
    for (int i = step; i < size; i++) {
      int j = i;
      int x = arr[j];
      while (j >= step && x < arr[j - step]) {
        arr[j] = arr[j - step];
        j -= step;
      }
      arr[j] = x;
    }
    step /= 2;
  }
}

namespace {
  void quick_sort_range(int* arr, int begin, int end) {
    if (begin >= end) return;

    int mid = (begin + end) / 2;
    int pivot = arr[begin] + arr[mid] + arr[end] -
      std::min({arr[begin], arr[mid], arr[end]}) -
      std::max({arr[begin], arr[mid], arr[end]});

    int i = begin, j = end;
    while(i <= j) {
      while (arr[i] < pivot) i++;
      while (arr[j] > pivot) j--;
      if (i <= j) std::swap(arr[i++], arr[j--]);
    }

  quick_sort_range(arr, begin, j);
  quick_sort_range(arr, i, end);
  }
}

void biv::quick_sort(int* arr, const int size) {
  if (size < 2) return;
  quick_sort_range(arr, 0, size - 1);
}

namespace {
  void merge_ranges(
      int* arr,
      int* buffer,
      const int begin,
      const int mid,
      const int end
  ) {
    int i = begin;
    int j = mid + 1;
    int k = begin;

    while (i <= mid && j <= end) {
      if (arr[i] < arr[j]) {
        buffer[k++] = arr[i++];
      } else {
        buffer[k++] = arr[j++];
      }
    }

    while (i <= mid) {
      buffer[k++] = arr[i++];
    }
    while (j <= end) {
      buffer[k++] = arr[j++];
    }

    for (int index = begin; index <= end; ++index) {
      arr[index] = buffer[index];
    }
  }

  void merge_sort_range(
      int* arr,
      int* buffer,
      const int begin,
      const int end
  ) {
    if (begin >= end) return;

    const int mid = begin + (end - begin) / 2;

    merge_sort_range(arr, buffer, begin, mid);
    merge_sort_range(arr, buffer, mid + 1, end);

    merge_ranges(arr, buffer, begin, mid, end);
  }
}

void biv::merge_sort(int* arr, const int size) {
  if (size < 2) return;

  int* buffer = new int [size];
  merge_sort_range(arr, buffer, 0, size - 1);
  delete[] buffer;
}

namespace {
  void heapify(int* arr, const int size, const int current_root) {
    int max = current_root;
    int left = 2 * current_root + 1;
    int right = 2 * current_root + 2;

    if (left < size && arr[left] > arr[max]) {
      max = left;
    }

    if (right < size && arr[right] > arr[max]) {
      max = right;
    }

    if (max != current_root) {
      std::swap(arr[current_root], arr[max]);
      heapify(arr, size, max);
    }
  }
}

void biv::heap_sort(int* arr, const int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(arr, size, i);
  }

  for (int i = size - 1; i >= 0; i--) {
    std::swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}
