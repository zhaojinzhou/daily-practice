#include <vector>
#include <list>
#include <iostream>
using namespace std;

/**
 * @brief print container e.g: vector; list
 * 
 * @tparam T container type
 * @param container 
 */
template <typename T>
void print(T& container) {
    for (auto& i : container) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}