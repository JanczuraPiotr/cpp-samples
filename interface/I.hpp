#ifndef INTERFACE_INTERFACE_HPP
#define INTERFACE_INTERFACE_HPP

#include <iostream>

#include "../Logger.hpp"

class I0 {
public:
    I0() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    virtual ~I0() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
};

class I : public I0 {
public:

    I() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    ~I() override { logger.log(__PRETTY_FUNCTION__ , __LINE__); }

    virtual int version() = 0;
};

class I1 : public I {
public:
    I1() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    ~I1() override { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    int version() override = 0;
    virtual void i1() = 0;
};

class I12 : public I {
public:
    I12() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    ~I12() override {  logger.log(__PRETTY_FUNCTION__ , __LINE__);  };

    int version() override = 0;
    virtual void i1() = 0;
    virtual void i12() = 0;
};

class I2 : public I {
public:
    I2() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    ~I2() override { logger.log(__PRETTY_FUNCTION__ , __LINE__); };

    int version() override = 0;
    virtual void i2() = 0;
};

#endif
