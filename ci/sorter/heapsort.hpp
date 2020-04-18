#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <iostream>
#include <vector>
#include "sorter.hpp"
using namespace std;

template <typename T>
void heapsort(T a[], int left, int right) {

}

template <typename T>
void heapsort(T& a, int left, int right) {
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
    quicksort(a, left, i - 1);
    quicksort(a, i + 1, right);
}


template<typename T>
class quick_sort : public sort{
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
#endif