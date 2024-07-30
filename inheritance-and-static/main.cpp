//
// Created by piotr@janczura.pl on 2020.08.22
//

#include <tuple>
#include "../Logger.hpp"

constexpr int COL{30};
Logger print(COL);

class Clazz {
public:
    virtual ~Clazz() = default;
    static Logger::Message stat()  { return {__PRETTY_FUNCTION__, "Pierwsza definicja."}; }
};

class Clazz1 : public Clazz {
public:
    ~Clazz1() override = default;
    Logger::Message stat()         { auto m = Clazz::stat(); return {__PRETTY_FUNCTION__, "Przys³oni³a -> " + m.first};};
    virtual Logger::Message virt() { auto m = stat();        return {__PRETTY_FUNCTION__, m.first + " " + m.second}; };
};

class Clazz2 : public Clazz1 {
public:
    ~Clazz2() override = default;
    Logger::Message stat()         { auto m = Clazz1::stat(); return {__PRETTY_FUNCTION__, "Przys³oni³a -> " + m.first};};
    Logger::Message virt() override{ auto m = stat();         return {__PRETTY_FUNCTION__, m.first + " " + m.second};};
};


int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    {
        Clazz clazz;
        print.log(clazz.stat(), __LINE__);
    }
    {
        Clazz1 clazz1;
        print.log(clazz1.stat(), __LINE__);
        print.log(clazz1.virt(), __LINE__);
    }
    {
        Clazz2 class2;
        print.log(class2.stat(), __LINE__);
        print.log(class2.virt(), __LINE__);
    }
    {
        auto *clazz1 = new Clazz1();
        auto *clazz2 = new Clazz2();

        print.log(clazz1->stat(), __LINE__);
        print.log(clazz1->virt(), __LINE__);

        print.log(clazz2->stat(), __LINE__);
        print.log(clazz2->virt(), __LINE__);

        delete clazz1;
        delete clazz2;
    }
    {
        Clazz1 *clazz1 = new Clazz2();

        print.log(clazz1->stat(), __LINE__);
        print.log(clazz1->virt(), __LINE__);

        delete clazz1;

    }
}