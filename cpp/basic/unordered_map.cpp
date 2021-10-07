#include "env.hpp"

using namespace std;

struct PtrHash {
    size_t operator()(const size_t *i) const {
        return *i;
    }
};

struct PtrEqual {
    bool operator()(const size_t *lhs, const size_t *rhs) const {
        return *lhs == *rhs;
    }
};

int main() {
    unordered_map<size_t*, int, PtrHash, PtrEqual> i2i;
    size_t k1 = 1;
    size_t k2 = 1;
    i2i.insert({&k1, 0});
    auto res = i2i.insert({&k2, 1});
    // cout << res.second << endl;

    // this is a real copy, not like iterator
    for(auto p : i2i) {
        p.second = 2;
    }
    for(auto p : i2i) {
        cout << p.second << endl;
    }

    // this is a reference
    for(auto &p : i2i) {
        p.second = 2;
    }
    for(auto p : i2i) {
        cout << p.second << endl;
    }

    for (auto it = i2i.begin(); it != i2i.end();++it) {
        it->second = 3;
    }
    for(auto p : i2i) {
        cout << p.second << endl;
    }
}