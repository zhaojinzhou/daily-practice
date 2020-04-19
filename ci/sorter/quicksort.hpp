#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <vector>
#include "sorter_interface.hpp"
using namespace std;

template <typename T>
void quicksort(T a[], int left, int right) {
    if (left > right) return;
    int i = left, j = right;
    T tmp = a[left];
    while (i < j) {
        while (i < j && a[j] >= tmp) j--;
        while (i < j && a[i] <= tmp) i++;
        if (i < j) std::swap(a[i], a[j]);
    }
    a[left] = a[i];
    a[i] = tmp;
    quicksort(a, left, i - 1);
    quicksort(a, i + 1, right);
}


template <typename T>
void quicksort(T& a, int left, int right) {
    if (left > right) return;
    int i = left, j = right;
    typename T::value_type tmp = a[left];
    while (i < j) {
        while (i < j && a[j] >= tmp) j--;
        while (i < j && a[i] <= tmp) i++;
        if (i < j) std::swap(a[i], a[j]);
    }
    a[left] = a[i];
    a[i] = tmp;
    quicksort(a, left, i - 1);
    quicksort(a, i + 1, right);
}


template<typename T>
class quick_sort :public sorter<T>{
    static void sort(T element[], int left, int right) {
        if (left > right) return;
        int i = left, j = right;
        int tmp = element[left];
        while (i < j) {
            while (i < j && element[j] >= tmp) j--;
            while (i < j && element[i] <= tmp) i++;
            if (i < j) std::swap(element[i], element[j]);
        }
        std::swap(tmp, element[i]);
        sort(element, left, i - 1);
        sort(element, i + 1, right);
    }
   
static void sort(T& container, int left, int right) {
    if (left > right) return;
    int i = left, j = right;
    typename T::value_type tmp = container[left];
    while (i < j) {
        while (i < j && container[j] >= tmp) j--;
        while (i < j && container[i] <= tmp) i++;
        if (i < j) std::swap(container[i], container[j]);
    }
    container[left] = container[i];
    container[i] = tmp;
    sort(container, left, i - 1);
    sort(container, i + 1, right);
}
   public:
    void sort(T& container, int size){ quick_sort::sort(container, 0, size - 1); }
    static void sort(T element[], int size) { quick_sort::sort(element, 0, size - 1); }
    static void sort(T container, int size) { quick_sort::sort(container, 0, size - 1); }
};




// The fixture for testing class Foo.
class QuicksortTest : public ::testing::Test {
protected:
   QuicksortTest() {}

   ~QuicksortTest() override {}

   void SetUp() override {}

   void TearDown() override {}
};


TEST_F(QuicksortTest, quicksort) {
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

TEST_F(QuicksortTest, quicksort_array) {
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