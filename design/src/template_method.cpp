#include <iostream>

using namespace std;

class TemplateMethod {
 public:
  void flow() {
    step1();
    step2();
    step3();
  }

  virtual ~TemplateMethod() {};

 private:
  virtual void step1() = 0;
  virtual void step2() = 0;
  virtual void step3() = 0;
};

class ApproachA : public TemplateMethod {
  virtual void step1() override {
    cout << "ApproachA step1()" << endl;
  }
  virtual void step2() override {
    cout << "ApproachA step2()" << endl;
  }
  virtual void step3() override {
    cout << "ApproachA step3()" << endl;
  }
};

int main() {
  TemplateMethod *m = new ApproachA();
  m->flow();
  delete m;
}
