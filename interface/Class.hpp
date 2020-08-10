//
// Created by piotr@janczura.pl on 2020.08.08
//

#ifndef INTERFACE_CLASS_HPP
#define INTERFACE_CLASS_HPP

#include "Interface.hpp"

class Class {
public:
    virtual ~Class() = default;
};


class C1 : public Class {
public:
    ~C1() override = default;
};

class C11 : public C1, public virtual I1, public virtual I2, public virtual I12 {
public:
    ~C11() override = default;
    int version() override ;
    void i1() override;
    void i2() override;
    void i12() override;
};

class C12 : public C1, public virtual I1 {
public:
    ~C12() override = default;
    void i1() override;
    int version() override;
};

class C13 : public Class, public virtual I1, public virtual I2 {
public:
    ~C13() override = default;
};

class C14 : public Class, public virtual I1, public virtual I12 {
public:
    ~C14() override = default;
};

class C111 : public C11, public virtual I1  {
public:
    ~C111() override = default;

};


#endif //INTERFACE_CLASS_HPP
