#include <iostream>

struct input_iter_tag {};
struct output_iter_tag {};
struct forward_iter_tag : public input_iter_tag {};
struct bid_iter_tag : public forward_iter_tag {};
struct random_iter_tag : public bid_iter_tag {};


class deque {
public:
  class Iter {
  public:
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

template<typename IterT>
struct IterTrait{
  using iterator_category = typename IterT::iter_category;
};

template<typename IterT, typename DistT>
void doAdvance(IterT &iter, DistT d, random_iter_tag) {
  std::cout << "Called random_iter_tag\n";
}

template<typename IterT, typename DistT>
void doAdvance(IterT &iter, DistT d, bid_iter_tag) {
  std::cout << "Called bid_iter_tag\n";
}

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