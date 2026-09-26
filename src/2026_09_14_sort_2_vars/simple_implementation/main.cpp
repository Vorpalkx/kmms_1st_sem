#include <iostream>

void gnome_sort(int *arr, const int size);

int main() {
    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Размер массива должен быть положительным." << std::endl;
        return 1;
    }

    int * arr = new int[ size ];

    std::cout << "Введите элементы массива:" << std::endl;

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Исходный массив: ";

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    gnome_sort(arr, size);

    std::cout << "Отсортированный массив: ";

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    delete[] arr;

    return 0;
}

void gnome_sort(int *arr, const int size) {
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
