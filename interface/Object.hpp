//
// Created by piotr@janczura.pl on 2020.08.10
//

#ifndef INTERFACE_OBJECT_HPP
#define INTERFACE_OBJECT_HPP

#include "Interface.hpp"
#include "Class.hpp"


class Object {
public:
    virtual ~Object() = default;
    void f1(C1 c1, C12 c12);
    void f2(I1 *i1, I12 *i12);
};




#endif //INTERFACE_OBJECT_HPP
