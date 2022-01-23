#pragma once

#include <iostream>
#include <list>

namespace ymy {

template<typename Data, typename VertexData>
class Edge;

template<typename Data, typename EdgeData>
class Vertex
{
public:
private:
    std::list<Edge<EdgeData, Data>*> _in;
    std::list<Edge<EdgeData, Data>*> _out;
    Data _data;
    bool _driver;
};

template<typename Data, typename VertexData>
class Edge
{
public:
private:
    std::list<Vertex<VertexData, Data>*> _vertex;
    Data _data;
};

} // namespace ymy