//
// Created by piotr@janczura.pl on 2020.08.11
//

#include <tuple>
#include <iostream>


void f(int p1, int line) { std::cout << "(int p1) <= ( " << p1 << " ) line: " << line << std::endl;}
void f(short p1, int line) { std::cout << "(short p1) <= ( " << p1 << " ) line: " << line << std::endl;}
void f(unsigned int p1, int line) { std::cout << "(unsigned int p1) <= ( " << p1 << " ) line: " << line << std::endl;}
void f(unsigned short p1, int line) { std::cout << "(unsigned short p1) <= ( " << p1 << " ) line: " << line << std::endl;}
void f(char p1, int line) { std::cout << "(char p1) <= ( " << (int)p1 << " ) line: " << line  << std::endl;}
void f(unsigned char p1, int line) { std::cout << "(unsigned char p1) <= ( " << (int)p1 << " ) line: " << line  << std::endl;}



int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    int p1 = 100;
    int p2 = 10000;
    short p3 = 10000;
    char p4 = 1;
    char p5 = 127;
    unsigned char p6 = 128;

    f(p1, __LINE__);
    f(p2, __LINE__);
    f(p3, __LINE__);
    f(p4, __LINE__);
    f(p5, __LINE__);
    f(p6, __LINE__);

    f(1u, __LINE__);
    f(0xff, __LINE__);
    f(0xffu, __LINE__);
    f(0xffff, __LINE__);
    f((char)49, __LINE__);
    f((char)49u, __LINE__);
    f((char)128, __LINE__);
    f((char)128u, __LINE__);
    f((unsigned char)-127, __LINE__);
    f(-127, __LINE__);


}