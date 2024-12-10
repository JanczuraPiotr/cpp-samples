#ifndef CPP_SAMPLES_FIRST_DUPLICATENAMEWRAPPER_HPP
#define CPP_SAMPLES_FIRST_DUPLICATENAMEWRAPPER_HPP

#include <string>


namespace first {

class Wrapper {
public:
    Wrapper() = default;
    virtual ~Wrapper() = default;

    std::string name() const;
};

}


#endif
