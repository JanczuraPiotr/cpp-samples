//
// Created by piotr@janczura.pl on 2022.05.011
//
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class C1 {
public:
  C1(int i1) {}
  virtual ~C1() {}

  void p1 (int i1) {}

protected:
  C1(int i1, int i2) {}

private:
  C1(int i1, int i2, int i3) {}

};

class C11 : protected C1 {
public:
  C11(int i1) : C1(i1) {}
  C11(int i1, int i2) : C1(i1, i2) {}
  // C11(int i1, int i2, int i3) : C1(i1, i2, i3) {}
  ~C11() override {}

};

class C111 : private C1 {
public:
  C111(int i1) : C1(i1) {}
  C111(int i1, int i2) : C1(i1, i2) {}
  // C111(int i1, int i2, int i3) : C1(i1, i2, i3) {}
  ~C111() override {}

};

int main()
{


}