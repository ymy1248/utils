#ifndef DS_VECTOR_HPP_
#define DS_VECTOR_HPP_

#include <iostream>
#include "ds.hpp"
namespace ymy 
{

static const unsigned int EXPAND_FACTOR = 2;
static const unsigned int SHINK_FACTOR = 4;

template <typename T>
class vector
{
public:
  vector();
  vector(unsigned int n);
  vector(unsigned int n, const T &val);

  T& operator[](unsigned int index);
  void push_back(T &t);
  void clear();
  bool empty() const { return size_ == 0; }
  unsigned int size() const { return size_; }
  unsigned int capacity() const { return capacity_; }
  void reserve(unsigned int n, T t = T());
  void resize(unsigned int n);

private:
  unsigned int size_;
  unsigned int capacity_;
  T* array_;
  bool checkCap();
  bool expand();
  bool shink();
};

template <typename T>
vector<T>::vector() :
  size_(0),
  capacity_(0)
{}

template <typename T>
vector<T>::vector(unsigned int n) :
  size_(n),
  capacity_(n)
{
  array_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
  memset(array_, 0, capacity_ * sizeof(T));
}

template <typename T>
vector<T>::vector(unsigned int n, const T &t) :
  size_(n),
  capacity_(n) {
  array_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
  for (int i = 0; i < n; ++i) {
    array_[i] = t;
  }
}

template <typename T>
void
vector<T>::push_back(T &t) {
  if (size_ == capacity_) {
    expand();
  }
  memcpy(array_[++size], &t, sizeof(t));
}

template <typename T>
bool
vector<T>::expand() {
  capacity_ *= EXPAND_FACTOR;
  void *old_array = array_;
  array_ = malloc(sizeof(T) * capacity_);
  memcpy(array_, old_array, sizeof(T) * size_);
  free(old_array);
}

template <typename T>
void
vector<T>::resize(unsigned int n) 
{
}
}

#endif
