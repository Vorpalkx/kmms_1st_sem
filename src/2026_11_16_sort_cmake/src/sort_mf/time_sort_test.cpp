#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "time_sort_test.hpp"
#include "time_sort_items.hpp"
#include "time_sort_functions.hpp"

#define SIZE1 10'000
#define SIZE2 100'000

int main() {
  std::filesystem::path output =
    std::filesystem::path(PROJECT_SOURCE_DIR) / "report.md";
  std::ofstream report(output);

  if (!report) {
    std::cerr << "Не удалось открыть файл: " << output << '\n';
    return 1;
  }

  std::srand(time(0));

  int array1[SIZE1];
  int array2[SIZE2];
  STram::generate_array(array1, SIZE1);
  STram::generate_array(array2, SIZE2);

  report << "## Отчет\n";

  STram::time_sort(&STram::BUBBLE_SORT_CLASSIC, array1, SIZE1, report);
  STram::time_sort(&STram::BUBBLE_SORT_CLASSIC, array2, SIZE2, report);

  report << "\n---\n\n";


  STram::time_sort(&STram::BUBBLE_SORT_EARLY_EXIT, array1, SIZE1, report);
  STram::time_sort(&STram::BUBBLE_SORT_EARLY_EXIT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::BUBBLE_SORT_EARLY_EXIT_OPT, array1, SIZE1, report);
  STram::time_sort(&STram::BUBBLE_SORT_EARLY_EXIT_OPT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::SHAKER_SORT, array1, SIZE1, report);
  STram::time_sort(&STram::SHAKER_SORT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::SHAKER_SORT_OPT, array1, SIZE1, report);
  STram::time_sort(&STram::SHAKER_SORT_OPT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::ODD_EVEN_SORT, array1, SIZE1, report);
  STram::time_sort(&STram::ODD_EVEN_SORT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::COMB_SORT, array1, SIZE1, report);
  STram::time_sort(&STram::COMB_SORT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::SELECTION_SORT, array1, SIZE1, report);
  STram::time_sort(&STram::SELECTION_SORT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::INSERT_SORT, array1, SIZE1, report);
  STram::time_sort(&STram::INSERT_SORT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::INSERT_SORT_OPT, array1, SIZE1, report);
  STram::time_sort(&STram::INSERT_SORT_OPT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::SHELL_SORT, array1, SIZE1, report);
  STram::time_sort(&STram::SHELL_SORT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::QUICK_SORT, array1, SIZE1, report);
  STram::time_sort(&STram::QUICK_SORT, array2, SIZE2, report);

  report << "\n---\n\n";

  STram::time_sort(&STram::MERGE_SORT, array1, SIZE1, report);
  STram::time_sort(&STram::MERGE_SORT, array2, SIZE2, report);

  return 0;
}

