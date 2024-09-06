#ifndef INTERFACE_CLASS_HPP
#define INTERFACE_CLASS_HPP

#include <memory>
#include <iostream>

#include "I.hpp"
#include "../Logger.hpp"

class C0 {
public:
    typedef std::shared_ptr<C0> SPtr;

    C0() { logger.log(__PRETTY_FUNCTION__ , __LINE__); };
    virtual ~C0() { logger.log(__PRETTY_FUNCTION__ , __LINE__); };

    virtual std::string name() { return __PRETTY_FUNCTION__; };
};

class C1 : public C0 {
public:

    C1() { logger.log(__PRETTY_FUNCTION__ , __LINE__); };
    ~C1() override { logger.log(__PRETTY_FUNCTION__ , __LINE__); };

    std::string name() override { return __PRETTY_FUNCTION__; };
};

class C11 : public C1, public virtual I1, public virtual I2, public virtual I12 {
public:

    C11() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    ~C11() override { logger.log(__PRETTY_FUNCTION__ , __LINE__); };

    int version() override { logger.log(__PRETTY_FUNCTION__ , __LINE__);
        return 11;
    };
    void i1() override { logger.log(__PRETTY_FUNCTION__ , __LINE__); };
    void i2() override { logger.log(__PRETTY_FUNCTION__ , __LINE__); };
    void i12() override { logger.log(__PRETTY_FUNCTION__ , __LINE__); };
    std::string name() override { return __PRETTY_FUNCTION__; };
private:
};

class C12 : public C1, public virtual I1 {
public:

    C12() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    ~C12() override  {  logger.log(__PRETTY_FUNCTION__, __LINE__); };

    void i1() override { logger.log(__PRETTY_FUNCTION__, __LINE__); };
    int version() override { logger.log(__PRETTY_FUNCTION__, __LINE__);
        return 12;
    };

    std::string name() override { return __PRETTY_FUNCTION__; };
};

class C13 : public C0, public virtual I1, public virtual I2 {
public:

    C13() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    ~C13() override { logger.log(__PRETTY_FUNCTION__ , __LINE__);  };

    std::string name() override { return __PRETTY_FUNCTION__; };
};

class C14 : public C0, public virtual I1, public virtual I12 {
public:

    C14() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    ~C14() override  {  logger.log(__PRETTY_FUNCTION__ , __LINE__); };
    std::string name() override { return __PRETTY_FUNCTION__; };
};

class C111 : public C11, public virtual I1  {
public:

    C111() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    ~C111() override  {  logger.log(__PRETTY_FUNCTION__ , __LINE__);  };
std::string name() override { return __PRETTY_FUNCTION__; };
};


#endif
