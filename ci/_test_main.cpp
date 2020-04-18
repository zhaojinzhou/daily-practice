#include <iostream>
#include <random>
#include <vector>
#include <list>
#include <algorithm>
#include "gtest/gtest.h"
/*********************************/
#include "quicksort.hpp"
#include "container_print.hpp"

/*********************************/

namespace my {
namespace project {

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

}  // namespace project
}  // namespace my



int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
