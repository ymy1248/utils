#include "trie.hpp"
#include <queue>

using namespace std;

namespace ymy {

void 
Trie::insert(const string &word) {
  Node *n = getOrCreateNode(word);
  ++n->count;
}

uint32_t 
Trie::count(const string &word) const{
  const Node *n = getNode(word);
  if (n) return n->count;
  return 0;
}

uint32_t
Trie::prefixCount(const char* pre) const {
  const Node *n = getNode(pre);
  uint32_t count = n->count;
  queue<const Node*> q;
  q.push(n);
  while (!q.empty()) {
    n = q.front();
    q.pop();
    count += n->count;
    for (size_t i = 0; i < 256; ++i) {
      if (n->next[i])
        q.push(n->next[i]);
    }
  }
  return count;
}

uint32_t
Trie::prefixCount(const string &pre) const{
  return prefixCount(pre.c_str());
}

bool 
Trie::existPrefix(const string &pre) const{
  const Node *n = getNode(pre);
  return n == nullptr;
}

const Trie::Node*
Trie::getNode(const char* word) const {
  const Node *n = &root;
  const char *c = word;
  while (*c) {
    if (!n->next[*c]) {
      return nullptr;
    }
    n = n->next[*c];
    ++c;
  }
  return n;
}

const Trie::Node* 
Trie::getNode(const string &word) const {
  return getNode(word.c_str());
}

Trie::Node* 
Trie::getOrCreateNode(const string &word) {
  Node *n = &root;
  for (auto c : word) {
    if (!n->next[c]) {
      n->next[c] = new Node();
    }
    n = n->next[c];
  }
  return n;
}

}
