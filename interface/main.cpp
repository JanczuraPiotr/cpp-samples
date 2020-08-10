//
// Created by piotr@janczura.pl on 2020.08.07
//

#include <tuple>
#include <iostream>

#include "Interface.hpp"
#include "Class.hpp"
#include "Object.hpp"

int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    std::cout << "interface" << std::endl;

    C1 c1;
    C11 c11, *pc11; // I1,I2, I12
    C12 c12; // I1

    pc11 = new C11;

    Object object;
    object.f1(c1, c12);
    object.f2(&c11, &c11);
    object.f2(pc11, pc11);
}