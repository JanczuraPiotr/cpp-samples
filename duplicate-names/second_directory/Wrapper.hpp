#ifndef CPP_SAMPLES_SECOND_DUPLICATENAMEWRAPPER_HPP
#define CPP_SAMPLES_SECOND_DUPLICATENAMEWRAPPER_HPP

#include <string>


namespace second {

class Wrapper{
public:
    Wrapper() = default;
    virtual ~Wrapper() = default;

    std::string name() const;
};

}


#endif
