#ifndef DS_LIST_HPP
#define DS_LIST_HPP

#include <iostream>
#include <string>
#include <assert.h>
namespace ymy{

template <typename V>
class list {
 private:
  struct Node;
 public:
  class Iter {
   public:
    Iter(Node *node) : node_(node) {}
    bool operator==(const Iter &that) { return node_ == that.node_; }
    bool operator!=(const Iter &that) { return !operator==(that); }
    Iter& operator++() { node_ = node_->next_; return *this; }
    Iter& operator--() { node_ = node_->prev_; return *this; }
    V& operator*() { return node_->val_; }
   private:
    Node *node_;
  };

  list();
  list<V> &add(V val);

  // modify
  void push_back(V &val);
  void push_front(V &val);
  void pop_back();
  void pop_front();
  void clear();
  Iter begin() { return Iter(dummy_->next_); }
  Iter end() { return Iter(dummy_); }

  size_t size() const { return size_; }
  bool empty() const {return size_ == 0; }
  void show() const;
  virtual ~list();

  template <typename T>
  friend std::ostream& operator<<(std::ostream &os, list<T> &l);

private:
  struct Node {
    V val_;
    Node *next_;
    Node *prev_;

    Node(): 
      next_(nullptr),
      prev_(nullptr)
    {};

    Node(V &v) :
      val_(v), 
      next_(nullptr),
      prev_(nullptr)
    {};
  };
  unsigned int size_;
  Node *dummy_;
};

template <typename V>
list<V>::list() :
  size_(0),
  dummy_(new Node())
{
  dummy_->next_ = dummy_;
  dummy_->prev_ = dummy_;
}

template <typename V>
void list<V>::push_back(V &val) 
{
  Node *node = nullptr;
  ++size_;
  node = dummy_->prev_->next_ = new Node(val);
  node->prev_ = dummy_->prev_;
  node->next_ = dummy_;
  dummy_->prev_ = node;
}

template<typename V>
void list<V>::push_front(V &val)
{
  Node *node = nullptr;
  ++size_;
  node = dummy_->next_->prev_ = new Node(val);
  node->next_ = dummy_->next_;
  node->prev_ = dummy_;
  dummy_->next_ = node;
}

template<typename V>
void list<V>::pop_front()
{
  assert(size_ >= 0);
  if (size_ == 0) return;
  auto node = dummy_->next_;
  dummy_->next_ = node->next_;
  node->next_->prev_ = dummy_;
  delete node;
}

template<typename V>
void list<V>::pop_back()
{
  assert(size_ >= 0);
  if (size_ == 0) return;
  auto node = dummy_->prev_;
  dummy_->prev_ = node->prev_;
  node->next_->prev_ = dummy_;
  delete node;
}

template <typename V>
void list<V>::clear(){
    Node *p = dummy_->next_;
    while (p != dummy_->prev_) {
        Node *next = p->next_;
        delete p;
        p = next;
    }
    dummy_->prev_ = dummy_->next_ = dummy_;
}

template <typename V>
void list<V>::show() const {
    #if DEBUG
    #endif
    std::cout << "[ ";
    if (!empty()) {
        Node *p = dummy_->next_;
        while (p->next_ != dummy_) {
          std::cout << p->val_ << " -> ";
          p = p->next_;
        }
        std::cout << p->val_;
    }
    std::cout << " ]\n";
}

template <typename V>
list<V>::~list() {
    clear();
    delete dummy_;
}

template <typename T>
std::ostream& operator<<(std::ostream &os, list<T> &l) {
  os << "[ ";
  if (!l.empty()) {
    auto p = l.dummy_->next_;
    while (p->next_ != l.dummy_) {
      os << p->val_ << " -> " ;
      p = p->next_;
    }
    os << p->d_val;
  }
  os << " ]\n";
  return os;
}

}

#endif
