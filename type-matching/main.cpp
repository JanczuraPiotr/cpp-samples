//
// Created by piotr@janczura.pl on 2020.08.11
//

#include <tuple>
#include <iostream>

#include "../Logger.hpp"

constexpr int COL{30};
Logger logger(COL);

Logger::Message f(int p)            { return {__PRETTY_FUNCTION__, "int{"+std::to_string(p)+"}" };}
Logger::Message f(short p)          { return {__PRETTY_FUNCTION__, "short{"+std::to_string(p)+"}" };}
Logger::Message f(unsigned int p)   { return {__PRETTY_FUNCTION__, "unsigned int{"+std::to_string(p)+"}" };}
Logger::Message f(unsigned short p) { return {__PRETTY_FUNCTION__, "unsigned short{"+std::to_string(p)+"}" };}
Logger::Message f(char p)           { return {__PRETTY_FUNCTION__, "char{"+std::to_string(p)+"}" };}
Logger::Message f(unsigned char p)  { return {__PRETTY_FUNCTION__, "unsigned char{"+std::to_string(p)+"}" };}



int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    int p1 = 100;
    int p2 = 10000;
    short p3 = 10000;
    char p4 = 1;
    char p5 = 127;
    unsigned char p6 = 128;

    logger.log( f(p1), __LINE__);
    logger.log( f(p2), __LINE__);
    logger.log( f(p3), __LINE__);
    logger.log( f(p4), __LINE__);
    logger.log( f(p5), __LINE__);
    logger.log( f(p6), __LINE__);

    logger.log( f(1u), __LINE__);
    logger.log( f(0xff), __LINE__);
    logger.log( f(0xffu), __LINE__);
    logger.log( f(0xffff), __LINE__);
    logger.log( f((char)49), __LINE__);
    logger.log( f((char)49u), __LINE__);
    logger.log( f((char)128), __LINE__);
    logger.log( f((char)128u), __LINE__);
    logger.log( f((unsigned char)-127), __LINE__);
    logger.log( f(-127), __LINE__);


}