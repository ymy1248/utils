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
Trie::prefixCount(const string &pre) const{
  const Node *n = getNode(pre);
  uint32_t count = n->count;
  queue<const Node*> q;
  q.push(n);
  while (!q.empty()) {
    n = q.front();
    q.pop();
    count += n->count;
    for (auto next : n->next) {
      q.push(next);
    }
  }
  return count;
}

bool 
Trie::existPrefix(const string &pre) const{
  const Node *n = getNode(pre);
  return n == nullptr;
}

const Trie::Node* 
Trie::getNode(const string &word) const {
  const Node *n = &root;
  for (auto c : word) {
    if (!n->next[c]) {
      return nullptr;
    }
    n = n->next[c];
  }
  return n;
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
