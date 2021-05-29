#include <iostream>

//! Predefined class for function overloading. These are real traits.
struct input_iter_tag {};
struct output_iter_tag {};
struct forward_iter_tag : public input_iter_tag {};
struct bid_iter_tag : public forward_iter_tag {};
struct random_iter_tag : public bid_iter_tag {};

class deque {
public:
  class Iter {
  public:
    //! Define a unified interface to support Trait's template struct.
    //! Define the trait of this class.
    using iter_category = random_iter_tag;
  };
};

class list {
public:
  class Iter {
  public:
    using iter_category = bid_iter_tag;
  };
};

//! Parrots the trait information
template<typename IterT>
struct IterTrait{
  // Effective CPP Item 42: for a nested dependent type name please use typename. Because compiler doesn't know whether this is a static val or global val or a type.
  using iterator_category = typename IterT::iter_category;
};

//! Using override techniques to do compile time if else. It's like metaprogramming
template<typename IterT, typename DistT>
void doAdvance(IterT &iter, DistT d, random_iter_tag) {
  std::cout << "Called random_iter_tag\n";
}

template<typename IterT, typename DistT>
void doAdvance(IterT &iter, DistT d, bid_iter_tag) {
  std::cout << "Called bid_iter_tag\n";
}

//! Wrapper, it makes compiler to decide which function should be used.
template<typename IterT, typename DistT>
void advance(IterT &iter, DistT d) {
  doAdvance(iter, d, typename IterTrait<IterT>::iterator_category());
}

int main() {
  list::Iter l;
  deque::Iter q;
  advance(l, 10);
  advance(q, 10);
}