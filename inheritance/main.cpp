#include <tuple>
#include <iostream>
#include <iomanip>

#include "../Logger.hpp"

class C0 {
public:
    virtual ~C0() = default;
    Logger::KeyValue m1()             { return {__PRETTY_FUNCTION__, "metoda zwykła"} ; };
    virtual Logger::KeyValue m2()     { return {__PRETTY_FUNCTION__, "metoda virtual"}; };
    static Logger::KeyValue stat()    { return {__PRETTY_FUNCTION__, "metoda static"};}
};

class C1 : public C0 {
public:
    ~C1() override = default;
    virtual Logger::KeyValue m1()     { return {__PRETTY_FUNCTION__, "metoda wirtualna przysłaniająca metodę zwykłą"}; };
    Logger::KeyValue m2() override    { return {__PRETTY_FUNCTION__, "metoda override"}; };
};

class C2 : public C1 {
public:
    ~C2() override = default;
    Logger::KeyValue m1() override    { return {__PRETTY_FUNCTION__, "metoda override. Pierwotna definicja w C jako nie wirtualna."}; };
    Logger::KeyValue m2() override    { return {__PRETTY_FUNCTION__, "metoda override."}; };
    static Logger::KeyValue stat()    { return {__PRETTY_FUNCTION__, "metoda static definiowana w C2"};}
};


int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    {
        C0 c0;
        C0 *pC0 = new C0();

        logger.log(c0.m1(), __LINE__);
        logger.log(c0.m2(), __LINE__);
        logger.log(c0.stat(),__LINE__, "Obiekt utworzono : C0 c0;");

        logger.log(pC0->m1(), __LINE__);
        logger.log(pC0->m2(), __LINE__);
        logger.log(pC0->stat(), __LINE__, "Obiekt utworzono : C0 *pC0 = new C0();");

        delete pC0;
    }

    {
        C1 *pC1 = new C1();
        C0 *pC  = new C1();

        logger.log(pC1->m1(), __LINE__);
        logger.log(pC1->m2(), __LINE__);
        logger.log(pC1->stat(), __LINE__, "Obiekt utworzono : C1 *pC1 = new C1();");

        logger.log(pC->m1(), __LINE__);
        logger.log(pC->m2(), __LINE__);
        logger.log(pC->stat(), __LINE__, "Obiekt utworzono : C  *pC  = new C1();");

        delete pC1;
        delete pC;
    }

    {
        C0 *pC2  = new C2();
        C1 *pC12 = new C2();
        C2 *pC22 = new C2();

        logger.log(pC2->m1(), __LINE__);
        logger.log(pC2->m2(), __LINE__);
        logger.log(pC2->stat(), __LINE__, "Obiekt utworzono : C *pC2 = new C2();");

        logger.log(pC12->m1(), __LINE__);
        logger.log(pC12->m2(), __LINE__);
        logger.log(pC12->stat(), __LINE__, "Obiekt utworzono : C1 *pC21 = new C2();");

        logger.log(pC22->m1(), __LINE__);
        logger.log(pC22->m2(), __LINE__);
        logger.log(pC22->stat(),__LINE__, "Obiekt utworzono : C2 *pC22 = new C2();");

        delete pC22;
        delete pC12;
        delete pC2;

    }

}