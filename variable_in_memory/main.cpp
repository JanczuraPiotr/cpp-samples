//
// Created by piotr@janczura.pl on 2024.07.31
//

#include <string>
#include "../Logger.hpp"


class C1 {
public:
    explicit C1(std::string name)
        : _name(std::move(name))
          , _a(1)
          , _b(2)
    { };

    void printPtr() const {
        logger.log("Address " + _name + " :........ " + std::to_string((std::uintptr_t)this), __LINE__);
        logger.log("Address " + _name + "->name :.. " + std::to_string(reinterpret_cast<std::uintptr_t>(&(this->_name))), __LINE__);
        logger.log("Address " + _name + "->a :..... " + std::to_string(reinterpret_cast<std::uintptr_t>(&(this->_a))), __LINE__);
        logger.log("Address " + _name + "->b :..... " + std::to_string(reinterpret_cast<std::uintptr_t>(&(this->_b))), __LINE__);
    }

private:
    std::string _name;
    int _a;
    int _b;
};

void f1(int line)
{
    logger.log("f1 wywołane w " + std::to_string(line) , __LINE__);
    C1 cf1("c1f1");
    cf1.printPtr();
}

void f2(int line)
{
    logger.log("f2 wywołane w " + std::to_string(line) , __LINE__);
    C1 c1f2("c1f2");
    c1f2.printPtr();
    f1(__LINE__);
}

void f3(int line)
{
    logger.log("f3 wywołane w " + std::to_string(line) , __LINE__);
    C1 c1f2("c1f3");
    c1f2.printPtr();
    f2(__LINE__);
}

void f4(int line)
{
    logger.log("f4 wywołane w " + std::to_string(line) , __LINE__);
    C1 c1f3("c1f4");
    c1f3.printPtr();
    f1(__LINE__);
    f2(__LINE__);
}

int main()
{
    C1 c1("c1");
    c1.printPtr();
    {
        C1 c2("c2");
        c2.printPtr();
    }
    auto c = new C1("c");
    logger.log("Object c leży w całkiem innym obszarze pamięci.", __LINE__);
    c->printPtr();
    {
        C1 c3("c3");
        c3.printPtr();
    }
    delete c;

    f1(__LINE__);
    {
        f1(__LINE__);
        {
            f1(__LINE__);
            f2(__LINE__);
            f3(__LINE__);
        }
    }

    f3(__LINE__);
}