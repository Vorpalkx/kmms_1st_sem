#include <gtest/gtest.h>

#include "sort.hpp"

TEST(HeapSort, SortsUnsortedArray) {
  int size = 6;
  int actual[] = {8, 1, 5, 3, 11, 2};
  int expected[] = {1, 2, 3, 5, 8, 11};

  biv::heap_sort(actual, size);

  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(expected[i], actual[i])
        << "Массивы отличаются в элементе с индексом " << i;
  }
}

TEST(HeapSort, SortsDuplicatesAndNegativeValues) {
  int size = 7;
  int actual[] = {4, -1, 4, 0, -1, 2, 0};
  int expected[] = {-1, -1, 0, 0, 2, 4, 4};

  biv::heap_sort(actual, size);

  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(expected[i], actual[i])
        << "Массивы отличаются в элементе с индексом " << i;
  }
}

TEST(HeapSort, HandlesSingleAndAlreadySortedArrays) {
  int single[] = {7};
  biv::heap_sort(single, 1);
  EXPECT_EQ(single[0], 7);

  int sorted[] = {-2, 0, 5};
  int expected[] = {-2, 0, 5};
  biv::heap_sort(sorted, 3);

  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(expected[i], sorted[i])
        << "Массивы отличаются в элементе с индексом " << i;
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
