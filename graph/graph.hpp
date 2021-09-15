#ifndef GRAPH_H
#define GRAPH_H

#include <list>

template<typename T>
class AdjListEdge;

template <typename T>
class Vertex {
    virtual const T& getVal() = 0;
};

template<typename T>
class AdjListVertex : public Vertex<T> {
 public:
    const T& getVal() { return _val; }
 private:
    T _val;
    std::list<AdjListEdge<T>> _adjList;
};

template<typename T>
class AdjListEdge {
 public:
 private:
    T _val;
    Vertex<T> *_to;
};


#endif
