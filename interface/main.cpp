#include <tuple>
#include <iostream>

#include "C.hpp"
#include "O.hpp"

#include "../Logger.hpp"

int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    logger.log(__PRETTY_FUNCTION__ , __LINE__, "C1 c1");
    C1 c1;
    logger.log(c1.name(), __LINE__);

    logger.log(__PRETTY_FUNCTION__ , __LINE__, "C11 c11 gdzie class C11 : public C1, public virtual I1, public virtual I2, public virtual I12");
    C11 c11; // I1, I2, I12
    logger.log(c11.name(), __LINE__);

    logger.log(__PRETTY_FUNCTION__ , __LINE__, "C12 c12");
    C12 c12; // I1
    logger.log(c12.name(), __LINE__);

    logger.log(__PRETTY_FUNCTION__ , __LINE__, "C1::SPtr ptrC1 = std::make_shared<C1>()");
    C1::SPtr ptrC1 = std::make_shared<C1>();
    logger.log(ptrC1->name(), __LINE__);

    logger.log(__PRETTY_FUNCTION__ , __LINE__, "C11::SPtr ptrC11 = std::make_shared<C11>()");
    C11::SPtr ptrC11 = std::make_shared<C11>();
    logger.log(ptrC11->name(), __LINE__);

    logger.log(__PRETTY_FUNCTION__ , __LINE__, "C11 *pc11 gdzie class C11 : public C1, public virtual I1, public virtual I2, public virtual I12");
    C11 *pc11; // I1,I2, I12
    pc11 = new C11;
    logger.log(pc11->name(), __LINE__);

    logger.log(__PRETTY_FUNCTION__ , __LINE__, "C0 *c0 = new C11()");
    C0 *c0 = new C11();
    logger.log(c0->name(), __LINE__);

    logger.log(__PRETTY_FUNCTION__ , __LINE__);
    O o;
    o.f1(c1, c12);
    o.f2(&c11, &c11);
    o.f2(pc11, pc11);

    // o.f1(ptrC1, c12); // wzorzec ptr uniemożliwia rozpoznawanie interfejsów
    o.fptr(ptrC1, c12);
    o.fptr(ptrC11, c12);
    // o.f2(ptrC11, c12); // wzorzec ptr uniemożliwia rozpoznawanie interfejsów

    delete c0;
    delete pc11;

    logger.log(__PRETTY_FUNCTION__, __LINE__, "END");
}