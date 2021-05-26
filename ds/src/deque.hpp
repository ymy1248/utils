#ifndef DS_DEQUE_HPP
#define DS_DEQUE_HPP

#include <sys/types.h>
#include "vector.hpp"

std::deque<int> a;
namespace ymy {

static const size_t CHUNK_SIZE = 16;


template<typename T>
class deque {
 public:
  class Iter;
  class Map;
  void push_back(const T&);
  void push_front(const T&);
  void pop_front();
  void pop_back();
 private:
  Map map_;

 public:
  class Map {
   public:
     void push_back(const T*);
     void push_front(const T*);
   private:
    T** array_;
  };
  class Iter {
   public:
   private:
    T* first_;
    T* last_;
    T* cur_;
    T** node_;
  };
};


template<typename T>
void
deque<T>::push_back(const T& val) {
}

template<typename T>
void
deque<T>::push_front(const T& val) {
}

template<typename T>
void
deque<T>::pop_back() {
}

}

}   // namespace ymy

#endif 
