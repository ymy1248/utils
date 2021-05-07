#ifndef DS_VECTOR_HPP_
#define DS_VECTOR_HPP_

#include <iostream>
#include "ds.hpp"
namespace ymy {

static const unsigned int EXPAND_FACTOR = 2;
static const unsigned int SHINK_FACTOR = 4;

template <typename T>
class vector {
 public:
  class Iter {
   public:
     Iter(vector *owner, size_t index) : owner_(owner), index_(index) {}
    size_t getIndex() { return index_; }
    Iter& operator++() { ++index_; return *this; }
    Iter& operator--() { --index_; return *this; }
    T operator*() { return *owner_->array_[index_];}
    bool operator==(const Iter &that) { return index_ == that.getIndex(); }

   private:
    vector *owner_;
    size_t index_;
  };

  vector();
  vector(unsigned int n);
  vector(unsigned int n, const T &val);

  // rule of three
  ~vector();
  vector(const vector &that);
  vector& operator=(const vector &that);

  // rule of five
  vector(vector &&that);
  vector& operator=(vector &&that);

  T& operator[](size_t index);
  void push_back(T &t);
  void clear();
  bool empty() const { return size_ == 0; }
  size_t size() const { return size_; }
  unsigned int capacity() const { return capacity_; }
  void reserve(size_t capacity);

  Iter begin() { return Iter(this, 0); }
  Iter end() { return Iter(this, size); }

 private:
  size_t size_;
  size_t capacity_;
  T* array_;

  bool checkCap();
  bool expand();
  bool shink();
  void move_ctor(vector &&that);
};

template <typename T>
void
vector<T>::move_ctor(vector &&that) {
  size_ = that.size_;
  capacity_ = that.capacity_;
  array_ = that.array_;
  that.array_ = nullptr;
  that.size_ = 0;
  that.capacity_ = 0;
}

template <typename T>
vector<T>::vector(vector &&that) {
  move_ctor(that);
}

template <typename T>
vector<T>&
vector<T>::operator=(vector &&that) {
  move_ctor(that);
  return *this;
}

template<typename T>
void
vector<T>::reserve(size_t capacity) {
  capacity_ = capacity;
  size_t cpy_len = capacity_ < size_ ? capacity_ : size_;
  size_ = capacity_ < size_ ? capacity_ : size_;
  void *old_array = array_;
  array_ = static_cast<T*>(malloc(sizeof(T) * capacity_));
  memcpy(array_, old_array, sizeof(T) * cpy_len);
  free(old_array);
}

template <typename T>
vector<T>::~vector() {
  free(array_);
}

template <typename T>
vector<T>::vector(const vector &that) :
  size_(that.size_),
  capacity_(that.capacity_) {
  array_ = malloc(capacity_ * sizeof(T));
  memcpy(array_, that.array_, size_ * sizeof(T));
}

template <typename T>
vector<T>&
vector<T>::operator=(const vector &that) {
  size_ = that.size_;
  capacity_ = that.capacity_;
  array_ = malloc(capacity_ * sizeof(T));
  memcpy(array_, that.array_, size_ * sizeof(T));
}


template <typename T>
vector<T>::vector() :
  size_(0),
  capacity_(0),
  array_(nullptr)
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
T&
vector<T>::operator[](size_t index) {
  return array_[index];
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
  array_[size_++] = t;
  // memcpy(&array_[size_++], (void*)&t, sizeof(t));
}

template <typename T>
bool
vector<T>::expand() {
  if (capacity_ == 0) capacity_ = 1;
  else capacity_ *= EXPAND_FACTOR;
  reserve(capacity_);
  return true;
}

template<typename T>
bool
vector<T>::shink() {
  capacity_ /= SHINK_FACTOR;
  reserve(capacity_);
  return true;
}

}

#endif
