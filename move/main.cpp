#include <string>
#include <utility>

#include "../Logger.hpp"


class C1 {
public:

    explicit C1(std::string &&name) : _name(std::move(name)) {
        logger.log(__PRETTY_FUNCTION__, __LINE__);
    }
    virtual ~C1() = default;

    std::string name() const { return _name;  }

private:
    std::string _name;
};

class C2 {
public:

    explicit C2(std::string name) : _name(std::move(name)) {
        logger.log(__PRETTY_FUNCTION__, __LINE__);
    }
    virtual ~C2() = default;

    std::string name() const { return _name;  }

private:
    std::string _name;
};

int main()
{
    {
        std::string str("str");
//         C1 c1(str); nie kompiluje.
        C1 c1(std::move(str));
        if (str.empty()) {
            logger.log(str, __LINE__, "Treść ze zmiennej str została przesunięta.");
        } else {
            logger.log(str, __LINE__, "Treść ze zmiennej str została skopiowana.");
        }
        logger.log(c1.name(), __LINE__);
    }

    {
        std::string str("str");
        C2 c21(str);
        if (str.empty()) {
            logger.log(str, __LINE__, "Treść ze zmiennej str została przesunięta.");
        } else {
            logger.log(str, __LINE__, "Treść ze zmiennej str została skopiowana.");
        }
        logger.log(c21.name(), __LINE__);

        C2 c22(std::move(str));
        if (str.empty()) {
            logger.log(str, __LINE__, "Treść ze zmiennej str została przesunięta.");
        } else {
            logger.log(str, __LINE__, "Treść ze zmiennej str została skopiowana.");
        }
        logger.log(c22.name(), __LINE__);
    }
}