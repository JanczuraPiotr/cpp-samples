//
// Created by piotr@janczura.pl on 2020.08.08
//

#ifndef INTERFACE_INTERFACE_HPP
#define INTERFACE_INTERFACE_HPP

#include <iostream>

class Interface0 {
public:
    virtual ~Interface0()  { std::cout << "~Interface0()" << std::endl; };
};

class Interface : public Interface0 {
public:
    ~Interface() override { std::cout << "~Interface()" << std::endl; };
    virtual int version() = 0;
};

class I1 : public Interface {
public:
    ~I1() override { std::cout << "~I1()" << std::endl; };
    int version() override = 0;
    virtual void i1() = 0;
};

class I12 : public Interface {
public:
    ~I12() override { std::cout << "~I12()" << std::endl; };
    int version() override = 0;
    virtual void i1() = 0;
    virtual void i12() = 0;
};

class I2 : public Interface {
public:
    ~I2() override { std::cout << "~I2()" << std::endl; };
    int version() override = 0;
    virtual void i2() = 0;
};





#endif //INTERFACE_INTERFACE_HPP
