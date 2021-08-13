#include <string_view>
#include "env.hpp"

using namespace std;

int main() {
    // string_view is like a interface of both std::string and c_str, shadow copy. It only contains str begin ptr and length of this string
    std::string_view sv1 = "1";
    std::string_view sv2 = string("2");
    string str3("3");
    cout << sv1 << endl;
    cout << sv2 << endl;
}