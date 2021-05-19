#include <iostream>
#include "boost/signals2.hpp"
#include <boost/timer/timer.hpp>

using namespace std;

struct Observer1 {
  int test = 10;
  void operator()() {
    cout << "Observer1: " << test << endl;
  }

  bool operator==(const Observer1 &that) const {
    return test == that.test;
  }
};

struct Observer2 {
  void operator()() {
    cout << "Observer2" << endl;
  }
};

int main() {
  boost::signals2::signal<void()> sig;
  Observer1 o1;
  Observer2 o2;
  // attach
  boost::signals2::connection c1 = sig.connect(o1);
  boost::signals2::connection c2 = sig.connect(o2);
  cout << "Attach o1, o2" << endl;
  sig();

  // detach
  cout << "Detach o1" << endl;
  c2.disconnect();
  sig.disconnect(o1);
  sig();


  // performance
  // boost::timer::cpu_timer timer;
  // timer.start();
  // int data_size = 1E6;
  // boost::signals2::signal<void()> s;
  // for (int i = 0; i < data_size(); ++i) {
  // }
  // timer.stop();
  // cout << timer.format() << endl;
}
