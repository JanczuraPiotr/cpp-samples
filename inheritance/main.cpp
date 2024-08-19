//
// Created by piotr@janczura.pl on 2020.08.22
//

#include <tuple>
#include <iostream>
#include <iomanip>

#include "../Logger.hpp"

class Clazz {
public:
    virtual ~Clazz() = default;
    Logger::KeyValue m1()             { return {__PRETTY_FUNCTION__, "zwykŁa metoda"} ; };
    virtual Logger::KeyValue m2()     { return {__PRETTY_FUNCTION__, "metoda wirtualna"}; };
    static Logger::KeyValue stat()    { return {__PRETTY_FUNCTION__, "static definiowana w Clazz"};}
};

class Clazz1 : public Clazz {
public:
    ~Clazz1() override = default;
    virtual Logger::KeyValue m1()     { return {__PRETTY_FUNCTION__, "metoda wirtualna przysłaniająca metodę zwykłą"}; };
    Logger::KeyValue m2() override    { return {__PRETTY_FUNCTION__, "metoda override"}; };
};

class Clazz2 : public Clazz1 {
public:
    ~Clazz2() override = default;
    Logger::KeyValue m1() override    { return {__PRETTY_FUNCTION__, "Metoda override. Pierwotna definicja w Clazz jako nie wirtualna."}; };
    Logger::KeyValue m2() override    { return {__PRETTY_FUNCTION__, "Metoda override."}; };
    static Logger::KeyValue stat()    { return {__PRETTY_FUNCTION__, "static definiowana w Clazz2"};}
};


constexpr int COL{30};
int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    std::cout << "inheritance" << std::endl;

    {
        Clazz clazz;
        Clazz *pClazz = new Clazz();

        logger.log(clazz.m1(), __LINE__);
        logger.log(clazz.m2(), __LINE__);
        logger.log(clazz.stat(), "Obiekt utworzono : Clazz clazz;", __LINE__);

        logger.log(pClazz->m1(), __LINE__);
        logger.log(pClazz->m2(), __LINE__);
        logger.log(pClazz->stat(), "Obiekt utworzono : Clazz *pClazz = new Clazz();", __LINE__);

        delete pClazz;
    }

    {
        Clazz1 clazz1;
        Clazz1 *pClazz1 = new Clazz1();
        Clazz  *pClazz  = new Clazz1();

        logger.log(clazz1.m1(), __LINE__);
        logger.log(clazz1.m2(), __LINE__);
        logger.log(clazz1.stat(), "Obiekt utworzono : Clazz1 clazz1;", __LINE__);

        logger.log(pClazz1->m1(), __LINE__);
        logger.log(pClazz1->m2(), __LINE__);
        logger.log(pClazz1->stat(), "Obiekt utworzono : Clazz1 *pClazz1 = new Clazz1();", __LINE__);

        logger.log(pClazz->m1(), __LINE__);
        logger.log(pClazz->m2(), __LINE__);
        logger.log(pClazz->stat(), "Obiekt utworzono : Clazz  *pClazz  = new Clazz1();", __LINE__);

        delete pClazz1;
        delete pClazz;
    }

    {
        Clazz *pClazz2   = new Clazz2();
        Clazz1 *pClazz12 = new Clazz2();
        Clazz2 *pClazz22 = new Clazz2();

        logger.log(pClazz2->m1(), __LINE__);
        logger.log(pClazz2->m2(), __LINE__);
        logger.log(pClazz2->stat(), "Obiekt utworzono : Clazz *pClazz2   = new Clazz2();", __LINE__);

        logger.log(pClazz12->m1(), __LINE__);
        logger.log(pClazz12->m2(), __LINE__);
        logger.log(pClazz12->stat(), "Obiekt utworzono : Clazz1 *pClazz21 = new Clazz2();", __LINE__);

        logger.log(pClazz22->m1(), __LINE__);
        logger.log(pClazz22->m2(), __LINE__);
        logger.log(pClazz22->stat(), "Obiekt utworzono : Clazz2 *pClazz22 = new Clazz2();", __LINE__);

        delete pClazz2;
        delete pClazz12;
        delete pClazz22;

    }

}