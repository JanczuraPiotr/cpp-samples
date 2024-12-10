#include "Wrapper.hpp"
#include "../first_directory/DuplicateName.hpp"
#include <memory>

namespace first {

static std::shared_ptr<DuplicateName> dn = std::make_shared<DuplicateName>();

//DuplicateName &duplicateName() {
//    static DuplicateName dn;
//    return dn;
//}

std::string Wrapper::name() const {
    return dn->name();
};


}
