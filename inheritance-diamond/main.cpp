#include <string>

#include "../Logger.hpp"

class C0 {
public:

    C0() : _i(0) {                                                          logger.log(__PRETTY_FUNCTION__, __LINE__);

    };

    virtual ~C0() {

    };

    virtual int i() {                                                       logger.log(__PRETTY_FUNCTION__, __LINE__);
        return _i;
    }

    virtual void i(int i) {                                                 logger.log(__PRETTY_FUNCTION__, __LINE__);
        _i = i;
    }


private:
    int _i;
};


// Zobacz różnicę.
// class C1 : public C0 {
class C1 : virtual public C0 {
public:
    C1() {                                                                  logger.log(__PRETTY_FUNCTION__, __LINE__);

    };

    virtual void v() {                                                      logger.log(__PRETTY_FUNCTION__, __LINE__);

    }
};

// Zobacz różnicę.
// class C2 : public C0 {
class C2 : virtual public C0 {
public:
    C2() {                                                                  logger.log(__PRETTY_FUNCTION__, __LINE__);

    };

    virtual void v() {                                                      logger.log(__PRETTY_FUNCTION__, __LINE__);

    }
};

class C3 : public C1, public C2 {
public:
    C3() : C1(), C2() {                                                     logger.log(__PRETTY_FUNCTION__, __LINE__);

    }
};

int main()
{
    logger.line(__PRETTY_FUNCTION__ , __LINE__);
    C3 c3;
    c3.i(1);
    logger.log({{"i"}, {std::to_string(c3.i())}}, __LINE__);
    // c3.v(); !!!
    {
        logger.line(__PRETTY_FUNCTION__, __LINE__);
        C3 *pc3 = new C3();
        pc3->i(2);
        logger.log({{"i"}, {std::to_string(pc3->i())}}, __LINE__);
        // pc3->v(); !!!
        delete pc3;
    }
    {
        logger.line(__PRETTY_FUNCTION__, __LINE__);
        C2 *pc2 = new C2();
        pc2->i(3);
        logger.log({{"i"}, {std::to_string(pc2->i())}}, __LINE__);
        pc2->v();
        delete pc2;
    }
}