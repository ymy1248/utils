#include <gtest/gtest.h>
#include "trie.hpp"

TEST(Trie, insert) {
  ymy::Trie t;
  t.insert("Test");
  EXPECT_EQ(t.count("Test"), 1);
  t.insert("Te");
  EXPECT_EQ(t.count("Te"), 1);
  EXPECT_EQ(t.prefixCount("T"), 2);
}
