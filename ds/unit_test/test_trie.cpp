#include "../trie.hpp"
#include "gtest/gtest.h"

TEST(Trie, Insert){
  ymy::Trie trie;
  trie.insert("test");
  EXPECT_EQ(7 * 6, 42);
}
