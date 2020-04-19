#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <iostream>
#include <vector>
#include "sorter_interface.hpp"
using namespace std;

template<typename T>
class HeapSort : public sorter<T>{
    static void sort(T a[], int left, int right) {
        if (left > right) return;
        int i = left, j = right;
        int tmp = a[left];
        while (i < j) {
            while (i < j && a[j] >= tmp) j--;
            while (i < j && a[i] <= tmp) i++;
            if (i < j) std::swap(a[i], a[j]);
        }
        std::swap(tmp, a[i]);
        sort(a, left, i - 1);
        sort(a, i + 1, right);
    }
   
static void sort(T& a, int left, int right) {
    if (left > right) return;
    int i = left, j = right;
    typename T::value_type tmp = a[left];
    while (i < j) {
        while (i < j && a[j] >= tmp) {
            j--;
        }
        while (i < j && a[i] <= tmp) {
            i++;
        }
        if (i < j) std::swap(a[i], a[j]);
    }
    a[left] = a[i];
    a[i] = tmp;
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}
   public:
    static void sort(T a[], int size) { sort(a, 0, size - 1); }
    static void sort(T a, int size) { sort(a, 0, size - 1); }
};



// The fixture for testing class Foo.
class HeapSortTest : public ::testing::Test {
protected:
   HeapSortTest() {}

   ~HeapSortTest() override {}

   void SetUp() override {}

   void TearDown() override {}
};


TEST_F(HeapSortTest, quicksort) {
   typedef std::vector<double> double_vector;
   const int size = 2000;
   double_vector double_vec;
   std::random_device rd;

   for (int i = 0; i < size; i++) {
      double_vec.push_back(rd()%10000);
   }
   #ifdef DEBUG
   print(double_vec);
   #endif
   double_vector primary(double_vec);
   std::sort(primary.begin(), primary.end());
   quicksort(double_vec, 0, double_vec.size() - 1);

   #ifdef DEBUG
   print(primary);
   print(double_vec);
   #endif
   EXPECT_EQ(double_vec, primary);
}

TEST_F(HeapSortTest, quicksort_array) {
   const int size = 1000;
   double double_vec[size];
   std::random_device rd;
   for (int i = 0; i < size; i++) {
       double_vec[i] = (rd() % 10000 / (double)10000);
   }
   double primary[size];
   std::copy(double_vec, double_vec + size, primary);
   std::sort(primary, primary + size);
   quicksort(double_vec, 0 ,size-1);

   #ifdef DEBUG
   for (int i = 0; i < size; i++) {
      std::cout << primary[i] << " ";
   }
   std::cout << std::endl;

   for (int i = 0; i < size; i++) {
      std::cout << double_vec[i] << " ";
   }
   std::cout << std::endl;
   #endif
   EXPECT_EQ(std::equal(double_vec, double_vec + size, primary), true);
}


#endif