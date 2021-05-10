#ifndef DS_DEQUE_HPP
#define DS_DEQUE_HPP

#include <sys/types.h>
#include "vector.hpp"

namespace ymy {

static const size_t CHUNK_SIZE = 16;

template<typename T>
class deque {
 public:
  void push_back(const T&);
  void push_front(const T&);
 private:
  vector<T**> map_;
};

}   // namespace ymy

#endif 
