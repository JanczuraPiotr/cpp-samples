#include <iostream>
#include <string>

#include "../Logger.hpp"

class C0 {
public:

    C0() : _i(0) {                                                          logger.log(__PRETTY_FUNCTION__ , __LINE__);

    };

    virtual ~C0() {                                                         logger.log(__PRETTY_FUNCTION__ , __LINE__);

    };

    virtual int i() {                                                       logger.log(__PRETTY_FUNCTION__, __LINE__);
        return _i;
    }

    virtual void i(int i) {                                                 logger.log(__PRETTY_FUNCTION__ , __LINE__);
        _i = i;
    }


private:
    int _i;
};



class C1 : virtual public C0 {
public:
    C1() {                                                                  logger.log(__PRETTY_FUNCTION__ , __LINE__);

    };

    ~C1() override {                                                        logger.log(__PRETTY_FUNCTION__ , __LINE__);

    };

};

class C2 : virtual public C0 {
public:
    C2() {                                                                  logger.log(__PRETTY_FUNCTION__ , __LINE__);

    };

    ~C2() override {                                                        logger.log(__PRETTY_FUNCTION__ , __LINE__);

    };

};

// Usunięcię virtual z: "virtual public C0" przy definicji jednej z klas C1 lib C2 powoduje błąd w
// wierszach 72, 74 i 81.

class C3 : public C1, public C2 {
public:
    C3() : C1(), C2() {                                                     logger.log(__PRETTY_FUNCTION__ , __LINE__);

    }

    void v() {                                                    logger.log(__PRETTY_FUNCTION__ , __LINE__);
        logger.log({{"X::i()"}, {std::to_string(C1::i())}}, __LINE__);
        logger.log({{"Y::i()"}, {std::to_string(C2::i())}}, __LINE__);

        logger.log({{"i()"}, {std::to_string(i())}}, __LINE__);

        i(1);
        C1::i(2);
        C2::i(3);

        logger.log({{"X::i()"}, {std::to_string(C1::i())}}, __LINE__);
        logger.log({{"Y::i()"}, {std::to_string(C2::i())}}, __LINE__);

        logger.log({{"i()"}, {std::to_string(i())}}, __LINE__);
    }
};

int main()
{

    logger.line(__PRETTY_FUNCTION__ , __LINE__);
    C3 c3;
    c3.v();
}