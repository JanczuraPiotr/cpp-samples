#include "Wrapper.hpp"
#include "../second_directory/DuplicateName.hpp"
#include <memory>

namespace second {

static std::shared_ptr<DuplicateName> dn = std::make_shared<DuplicateName>();

//DuplicateName &duplicateName() {
//    static DuplicateName dn;
//    return dn;
//}

std::string Wrapper::name() const {
    return dn->name();
}


}