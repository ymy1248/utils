#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace ymy {
  class Trie {
    public:
      struct Node {
        uint32_t count;
        Node *next[256];
        Node() : count(0) {
          memset(&next, 0, sizeof(next));
        }
      };

      void insert(const string &word);
      void remove(const string &word);

      uint32_t count(const string &word) const;
      bool exist(const string &word) const;
      bool existPrefix(const string &pre) const;
      uint32_t prefixCount(const string &pre) const;
      uint32_t prefixCount(const char* pre) const;
    private:
      Node* getOrCreateNode(const string &word);
      const Node* getNode(const string &word) const;
      const Node* getNode(const char *word) const;
      Node root;
  };
}

#endif
