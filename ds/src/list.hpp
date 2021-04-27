#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <assert.h>
namespace ymy{

template <typename V>
class list {
public:
  list();
  list<V> &add(V val);

  // modify
  void push_back(V &val);
  void push_front(V &val);
  void pop_back();
  void pop_front();
  void clear();

  size_t size() const { return d_size; }
  bool empty() const {return d_size == 0; }
  void show() const;
  virtual ~list();

  template <typename T>
  friend std::ostream& operator<<(std::ostream &os, list<T> &l);

private:
  struct Node {
    V d_val;
    Node *d_next;
    Node *d_prev;

    Node(): 
      d_next(nullptr),
      d_prev(nullptr)
    {};

    Node(V &v): 
      d_val(v), 
      d_next(nullptr),
      d_prev(nullptr)
    {};
  };
  unsigned int d_size;
  Node *d_dummy;
};

template <typename V>
list<V>::list() :
  d_size(0),
  d_dummy(new Node())
{
  d_dummy->d_next = d_dummy;
  d_dummy->d_prev = d_dummy;
}

template <typename V>
void list<V>::push_back(V &val) 
{
  Node *node = nullptr;
  ++d_size;
  node = d_dummy->d_prev->d_next = new Node(val);
  node->d_prev = d_dummy->d_prev;
  node->d_next = d_dummy;
  d_dummy->d_prev = node;
}

template<typename V>
void list<V>::push_front(V &val)
{
  Node *node = nullptr;
  ++d_size;
  node = d_dummy->d_next->d_prev = new Node(val);
  node->d_next = d_dummy->d_next;
  node->d_prev = d_dummy;
  d_dummy->d_next = node;
}

template<typename V>
void list<V>::pop_front()
{
  assert(d_size >= 0);
  if (d_size == 0) return;
  auto node = d_dummy->d_next;
  d_dummy->d_next = node->d_next;
  node->d_next->d_prev = d_dummy;
  delete node;
}

template<typename V>
void list<V>::pop_back()
{
  assert(d_size >= 0);
  if (d_size == 0) return;
  auto node = d_dummy->d_prev;
  d_dummy->d_prev = node->d_prev;
  node->d_next->d_prev = d_dummy;
  delete node;
}

template <typename V>
void list<V>::clear(){
    Node *p = d_dummy->d_next;
    while (p != d_dummy->d_prev) {
        Node *next = p->d_next;
        delete p;
        p = next;
    }
    d_dummy->d_prev = d_dummy->d_next = d_dummy;
}

template <typename V>
void list<V>::show() const {
    #if DEBUG
    #endif
    std::cout << "[ ";
    if (!empty()) {
        Node *p = d_dummy->d_next;
        while (p->d_next != d_dummy) {
          std::cout << p->d_val << " -> ";
          p = p->d_next;
        }
        std::cout << p->d_val;
    }
    std::cout << " ]\n";
}

template <typename V>
list<V>::~list() {
    clear();
    delete d_dummy;
}

template <typename T>
std::ostream& operator<<(std::ostream &os, list<T> &l) {
  os << "[ ";
  if (!l.empty()) {
    auto p = l.d_dummy->d_next;
    while (p->d_next != l.d_dummy) {
      os << p->d_val << " -> " ;
      p = p->d_next;
    }
    os << p->d_val;
  }
  os << " ]\n";
  return os;
}

}

#endif
