#include <iostream>

void gnome_sort(int *arr, const int size);
void print_array(const char* const comment, int *arr, const int size);

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

    print_array("Исходный массив: ", arr, size);

    gnome_sort(arr, size);

    print_array("Отсортированный массив: ", arr, size);

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

void print_array(const char* const comment, int *arr, const int size) {
    std::cout << comment;

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;   
}
