//
// Created by piotr@janczura.pl on 2020.08.08
//

#ifndef INTERFACE_CLASS_HPP
#define INTERFACE_CLASS_HPP

#include <memory>
#include <iostream>

#include "Interface.hpp"
#include "../Logger.hpp"

class Clazz {
public:
    typedef std::shared_ptr<Clazz> ptr;
    virtual ~Clazz() { std::cout << "~Class()" << std::endl; };
};

class C1 : public Clazz {
public:
    static ptr create();
    C1() = default;
    ~C1() override  { std::cout << "~C1()" << std::endl; };
};

class C11 : public C1, public virtual I1, public virtual I2, public virtual I12 {
public:
    typedef std::shared_ptr<C11> ptr;
    static ptr create();

    ~C11() override  { std::cout << "~C11()" << std::endl; };
    int version() override ;
    void i1() override;
    void i2() override;
    void i12() override;

private:
};

class C12 : public C1, public virtual I1 {
public:
    ~C12() override  { std::cout << "~C12()" << std::endl; };
    void i1() override;
    int version() override;
};

class C13 : public Clazz, public virtual I1, public virtual I2 {
public:
    ~C13() override  { std::cout << "~C13()" << std::endl; };
};

class C14 : public Clazz, public virtual I1, public virtual I12 {
public:
    ~C14() override  { std::cout << "~C14()" << std::endl; };
};

class C111 : public C11, public virtual I1  {
public:
    ~C111() override  { std::cout << "~C111()" << std::endl; };

};


#endif //INTERFACE_CLASS_HPP
