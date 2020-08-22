//
// Created by piotr@janczura.pl on 2020.08.22
//

#include <tuple>
#include <iostream>

class Class {
public:
    virtual ~Class() = default;
    void m1() { std::cout << "Class::m1()" << std::endl; };
    virtual void m2() { std::cout << "Class::m2()" << std::endl; };
};

class Class1 : public Class {
public:
    virtual ~Class1() = default;
    virtual void m1() { std::cout << "Class1::m1()" << std::endl; };
    void m2() override { std::cout << "Class1::m2()" << std::endl; };
};

class Class2 : public Class1 {
public:
    virtual ~Class2() = default;
    void m1() override { std::cout << "Class2::m1()" << std::endl; };
    void m2() override { std::cout << "Class2::m2()" << std::endl; };
};


int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    std::cout << "inheritance" << std::endl;

    Class aClass;
    Class *pClass = new Class();
    Class1 aClass1;
    Class1 *pClass1 = new Class1();
    Class *pClass11 = new Class1();
    Class *pClass2  = new Class2();
    Class1 *pClass21  = new Class2();
    Class2 *pClass22  = new Class2();

    std::cout << __LINE__ << std::endl;
    aClass.m1();
    aClass.m2();
    pClass->m1();
    pClass->m2();
    std::cout << __LINE__ << std::endl;
    aClass1.m1();
    aClass1.m2();
    pClass1->m1();
    pClass1->m2();
    pClass11->m1();
    pClass11->m2();
    std::cout << __LINE__ << std::endl;
    pClass2->m1();
    pClass2->m2();
    pClass21->m1();
    pClass21->m2();
    pClass22->m1();
    pClass22->m2();
    std::cout << __LINE__ << std::endl;


    delete pClass;
    delete pClass1;
    delete pClass11;
    delete pClass2;
    delete pClass21;
    delete pClass22;
}