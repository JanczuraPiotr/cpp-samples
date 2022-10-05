//
// Created by piotr@janczura.pl on 2020.08.22
//

#include <tuple>
#include <iostream>

class Class {
public:
    Class() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    virtual ~Class() { std::cout << __PRETTY_FUNCTION__ << std::endl; };
    static void s1() {std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Class1 : public Class {
public:
    Class1() : Class() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Class1() override { std::cout << __PRETTY_FUNCTION__ << std::endl; };
    void s1() { Class::s1(); };
};

class Class2 : public Class1 {
public:
    Class2() : Class1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Class2() override = default;
    void s1() { Class1::s1(); };
    virtual void v1() {s1(); };
};


int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    std::cout << __FILE__ << " " << __LINE__ << std::endl;
    Class aClass;

    std::cout << __FILE__ << " " << __LINE__ << std::endl;
    aClass.s1();


    std::cout << __FILE__ << " " << __LINE__ << std::endl;
    Class1 aClass1;

    std::cout << __FILE__ << " " << __LINE__ << std::endl;
    aClass1.s1();


    std::cout << __FILE__ << " " << __LINE__ << std::endl;
    Class2 class2;
    std::cout << __FILE__ << " " << __LINE__ << std::endl;
    class2.s1();
    std::cout << __FILE__ << " " << __LINE__ << std::endl;
    class2.v1();

    std::cout << std::endl;
    std::cout << __FILE__ << " " << __LINE__ << std::endl;
    std::cout << std::endl;
}