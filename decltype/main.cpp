#include <tuple>
#include <typeinfo>

#include "../Logger.hpp"

class EnyClass {};

int main() {

    int i{1};
    double d{2.0};

    float fval = 4.1f + 0.3f;
    const std::type_info &dvalInfo = typeid(fval);
    logger.log({{"fval"}, {std::to_string(fval)}}, __LINE__);
    logger.log({{"nazwa typu zmiennej : fval"}, {dvalInfo.name()} }, __LINE__);

    decltype(i + d) aval{i + d};
    const std::type_info &avalInfo = typeid(aval);
    logger.log({{"decltype(i + d) item{i + d}"}, {std::to_string(aval)}}, __LINE__);
    logger.log({{"nazwa typu zmiennej : aval"}, {avalInfo.name()} }, __LINE__);

    EnyClass enyClass;
    const std::type_info &enyClassInfo = typeid(enyClass);
    logger.log({{"nazwa typu zmiennej : enyClassInfo"}, {enyClassInfo.name()} }, __LINE__);
}