#include <gtest/gtest.h>
#include "trie.hpp"

TEST(Trie, insert) {
  ymy::Trie t;
  t.insert("test");
  t.count("test");
}
