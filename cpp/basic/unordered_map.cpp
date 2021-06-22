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
    cout << res.second << endl;
}