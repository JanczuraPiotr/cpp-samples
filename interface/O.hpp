#ifndef INTERFACE_OBJECT_HPP
#define INTERFACE_OBJECT_HPP

#include "I.hpp"
#include "C.hpp"


class O {
public:
    virtual ~O() = default;

    void fptr(C0::SPtr c1, C12 c12) { logger.log(__PRETTY_FUNCTION__, __LINE__);
        std::ignore = c1;
        std::ignore = c12;
    };

    void f1(C1 c1, C12 c12) { logger.log(__PRETTY_FUNCTION__ , __LINE__);
        std::ignore = c1;
        std::ignore = c12;
    };

    void f2(I1 *i1, I12 *i12) { logger.log(__PRETTY_FUNCTION__ , __LINE__);
        std::ignore = i1;
        std::ignore = i12;
    };
};




#endif
