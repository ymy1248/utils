#include <string>
#include <iostream>

using namespace std;

class Person {
 public:
  explicit Person(const string &n) : name(n) {
    cout << "ctor copy for '" << name << "'\n";
  }
  explicit Person(string &&n) : name(std::move(n)) {
    cout << "ctor move for '" << name << "'\n";
  }
  Person(const Person &p) : name(p.name) {
    cout << "copy ctor for '" << name << "'\n";
  }
  Person(Person &&p) : name(std::move(p.name)) {
    cout << "move ctor for '" << name << "'\n";
  }
 private:
  string name;
};

class TmplPerson {
 public:
  template<typename STR>
  explicit TmplPerson(STR &&n) : name(std::forward<STR>(n)) {
    cout << "TMPL ctor for '" << name << "'\n";
  }

  TmplPerson(const TmplPerson & p) : name(p.name) {
    cout << "TMPL copy ctor " << name << endl;
  }

  TmplPerson(const TmplPerson &&p) : name(p.name) {
    cout << "TMPL move ctor " << name << endl;
  }

 private:
  string name;
};

int main() {
  string s = "ymy";
  Person p1(s);
  Person p2("tmp");
  Person p3(p1);
  Person p4(std::move(p1));

  string tmp = "tmpl";
  TmplPerson t1(tmp);
  // !STR is deduced to const char*
  TmplPerson t2("test");
  // !error out, because overload resolution rule prefers template STR&& ctor over copy ctor
  // !However, std::string doesn't have non-const copy ctor.
  // TmplPerson t3(t1);
}