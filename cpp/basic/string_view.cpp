#include <string_view>
#include "env.hpp"

using namespace std;

void func(string_view sv)
{
    cout << sv << endl;
}

int main() {
    // string_view is like a interface of both std::string and c_str, shadow copy. It only contains str begin ptr and length of this string
    string str("2");
    std::string_view sv1 = "1";
    std::string_view sv2 = str;
    func(sv1);
    func(sv2);
}