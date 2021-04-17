/*
 * function for C++ string splig
 */
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;

    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

// leetcode version
vector<string> split(string &s, char delim) {
  vector<string> strs;
  string str;
  istringstream iss(s);
  while (getline(iss, str, delim)) {
    strs.push_back(str);
  }
  return strs;
}
