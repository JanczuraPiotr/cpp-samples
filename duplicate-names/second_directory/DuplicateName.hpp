#ifndef CPP_SAMPLES_SECOND_DUPLICATENAME_HPP
#define CPP_SAMPLES_SECOND_DUPLICATENAME_HPP


#include <string>
#include "../../Logger.hpp"

class DuplicateName {

public:
    DuplicateName() : _name("SECOND: "+ std::string(__PRETTY_FUNCTION__)) {
        logger.log(_name, __LINE__ , "constructor");
    }
    virtual ~DuplicateName() = default;
    std::string name() const { return _name; }

private:
    std::string _name;
};


#endif
