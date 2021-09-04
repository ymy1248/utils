#include "env.hpp"

class Node {
public:
    Node(int n) : _n(n) {}
    void set(int i) { _n = i; }
    bool operator<(const Node &that) {
        return _n < that._n;
    }
    int _n;
};

int main() 
{
    // std::set<std::reference_wrapper<Node>> s;
    std::vector<Node> v;
    std::vector<Node> refV;
    for (int i = 0; i < 100; ++i) {
        v.push_back(Node(i));
        std::reference_wrapper<Node> node(v[i]);
        refV.push_back(v[i]);
    }
    for (int i = 0; i < 100; ++i) {
        std::cout << refV[i]._n << std::endl;
    }
}