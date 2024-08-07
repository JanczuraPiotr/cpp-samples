//
// Created by piotr@janczura.pl on 2020.08.08
//

#include "Clazz.hpp"

C1::ptr C1::create()
{
    return ptr(new C1());
}

C11::ptr C11::create()
{
    return ptr(new C11());
}

int C11::version()
{
    return 11;
}

void C11::i1() {

}

void C11::i2() {

}

void C11::i12() {

}

int C12::version() {
    return 12;
}

void C12::i1() {

}