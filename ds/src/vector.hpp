#ifndef VECTOR_H
#define VECTOR_H

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
  bool empty() const { return d_size == 0; }
  unsigned int size() const { return d_size; }
  unsigned int capacity() const { return d_capacity; }
  void reserve(unsigned int n, T t = T());
  void resize(unsigned int n);

private:
  unsigned int d_size;
  unsigned int d_capacity;
  T* d_array;
  bool checkCap();
  bool expand();
  bool shink();
};

template <typename T>
vector<T>::vector() :
  d_size(0),
  d_capacity(0)
{}

template <typename T>
vector<T>::vector(unsigned int n) :
  d_size(n),
  d_capacity(n)
{
  d_array = static_cast<T*>(malloc(d_capacity * sizeof(T)));
  memset(d_array, 0, d_capacity * sizeof(T));
}

template <typename T>
vector<T>::vector(unsigned int n, const T &t) :
  d_size(n),
  d_capacity(n)
{
  d_array = static_cast<T*>(malloc(d_capacity * sizeof(T)));
  for (int i = 0; i < n; ++i) {
    d_array[i] = t;
  }
}

template <typename T>
void
vector<T>::push_back(T &t)
{
}

template <typename T>
bool
vector<T>::expand()
{
  assert(d_size == d_capacity);
}

template <typename T>
void
vector<T>::resize(unsigned int n, T t) 
{
  if (n > 
}
}

#endif
