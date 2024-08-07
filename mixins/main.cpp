//
// Created by piotr@janczura.pl on 2022.05.011
//
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <type_traits>

#include "../Logger.hpp"

Logger logger(Logger::COL);


class C1 {
public:
    virtual ~C1() = default;
    void print() {
        logger.log(__PRETTY_FUNCTION__ , __LINE__);
    }
    virtual void vprint() {
        logger.log(__PRETTY_FUNCTION__ , __LINE__);
    }
};

template<typename T,
         typename = typename std::enable_if<std::is_class<C1>::value>::type>
class C2 : public T {
public:
    ~C2() override = default;
    void print() {
        T::print();
        logger.log(__PRETTY_FUNCTION__ , __LINE__);
    }
    void vprint() override {
        T::vprint();
        logger.log(__PRETTY_FUNCTION__ , __LINE__);
    }
};

template<typename T,
         typename = typename std::enable_if<std::is_class<C1>::value>::type>
class C3 : public T {
public:
    ~C3() override = default;
    void print() {
        T::print();
        logger.log(__PRETTY_FUNCTION__ , __LINE__);
    }
    void vprint() override {
        T::vprint();
        logger.log(__PRETTY_FUNCTION__ , __LINE__);
    }
};

int main()
{

    logger.line(__PRETTY_FUNCTION__ , __LINE__);
    C1 c1;
    c1.print();
    c1.vprint();
    logger.line(__PRETTY_FUNCTION__ , __LINE__);
    C2<C1> c2;
    c2.print();
    c2.vprint();
    logger.line(__PRETTY_FUNCTION__ , __LINE__);
    C3<C2<C1>> c3;
    c3.print();
    c3.vprint();
    logger.line(__PRETTY_FUNCTION__ , __LINE__);
}