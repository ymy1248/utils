#ifndef GRAPH_H
#define GRAPH_H

#include <list>

template<typename T>
class Vertext {
private:
  T val;
  std::list<Edge<>> adjacent_list;
};

template<typename V>
class Edge {
  V weight;
};

#endif
