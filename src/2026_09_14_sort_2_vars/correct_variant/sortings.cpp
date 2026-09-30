#include "sortings.hpp"

void biv::gnome_sort(int* const arr, const int size) {
    int index = 0;

    while (index < size) {
      if (index == 0 || arr[index] >= arr[index - 1]) {
        index++;
      } else {
        int temp = arr[index];
        arr[index] = arr[index - 1];
        arr[index - 1] = temp;

        index--;
      }
    }
}
