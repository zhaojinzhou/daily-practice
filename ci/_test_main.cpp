#include <iostream>
#include <vector>
#include "gtest/gtest.h"
// using std::vector;
namespace my {
namespace project {
namespace {

// The fixture for testing class Foo.
class VectorTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  VectorTest() {
     // You can do set-up work for each test here.
  }

  ~VectorTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  // for Foo.
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(VectorTest, push_back) {
    std::vector<int> vec;
    vec.push_back(10);
    EXPECT_EQ(vec.size(), 1);
}

// Tests that Foo does Xyz.
TEST_F(VectorTest, pop_back) {
    // Exercises the Xyz feature of Foo.
    std::vector<int> vec;
    vec.push_back(10);
    EXPECT_EQ(vec.size(), 1);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 0);
}





}  // namespace
}  // namespace project
}  // namespace my

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}