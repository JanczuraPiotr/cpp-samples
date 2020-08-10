//
// Created by piotr@janczura.pl on 2020.08.10
//

#include "Object.hpp"
#include <tuple>

void Object::f1(C1 c1 , C12 c12)
{
    std::ignore = c1;
    std::ignore = c12;
}

void Object::f2(I1 *i1, I12 *i12)
{
    std::ignore = i1;
    std::ignore = i12;
}