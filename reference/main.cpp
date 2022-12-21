//
// Created by piotr@janczura.pl on 2020.08.07
//

#include <tuple>
#include <iostream>

class C1 {
public:
  C1(int i) : _pointer(new int{i}) {};
  C1() : _pointer(new int{1}) {};
  C1(const C1 &src) : _pointer{src._pointer}{

  };

  C1 &operator = (const C1 &src) {
    _pointer = src._pointer;
    return *this;
  };

  ~C1() { delete _pointer; };

  void checkPointer() {
    if (_pointer == nullptr) {
      std::cout << "if (_pointer == nullptr)" << std::endl;
    }
  }

private:
  int *_pointer;
};


int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    std::cout << "reference" << std::endl;

    C1 c1;

    c1.checkPointer();

    std::cout << __FILE__ << ":" << __LINE__ << std::endl;

    int *_int;

//    int intBaza = 2;
    std::cout << __FILE__ << ":" << __LINE__ << std::endl;
//    _int = &intBaza;
    _int = new int{1};
    std::cout << __FILE__ << ":" << __LINE__ << std::endl;

    std::cout << _int << std::endl;
    std::cout << __FILE__ << ":" << __LINE__ << std::endl;
    std::cout << *_int << std::endl;

    std::cout << __FILE__ << ":" << __LINE__ << std::endl;
    delete _int;
    std::cout << __FILE__ << ":" << __LINE__ << std::endl;

    std::cout << _int << std::endl;
    std::cout << *_int << std::endl;

//    if(_int == nullptr) {
//      std::cout << "if (_pointer == nullptr)" << std::endl;
//    }
//
//    if (_int == NULL) {
//      std::cout << "if (_pointer == NULL)" << std::endl;
//    }

}