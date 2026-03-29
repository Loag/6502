#include <emulator/placeholder.hpp>
#include <gtest/gtest.h>

TEST(PlaceholderTest, CompilesAndLinks) {
  emulator::placeholder();
  SUCCEED();
}