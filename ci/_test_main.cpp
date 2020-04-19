#include <iostream>
#include <random>
#include <vector>
#include <list>
#include <algorithm>
#include "gtest/gtest.h"
/*********************************/
#include "quicksort.hpp"
#include "heapsort.hpp"
#include "container_print.hpp"

/*********************************/


int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
