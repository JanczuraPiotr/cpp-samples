//
// Created by piotr@janczura.pl on 2020.08.22
//

#include <tuple>
#include "../Logger.hpp"


class Clazz {
public:
    virtual ~Clazz() = default;
    static Logger::KeyValue stat()  { return {__PRETTY_FUNCTION__, "Pierwsza definicja."}; }
};

class Clazz1 : public Clazz {
public:
    ~Clazz1() override = default;
    Logger::KeyValue stat()         { auto m = Clazz::stat(); return {__PRETTY_FUNCTION__, "Przysłoniła -> " + m.first};};
    virtual Logger::KeyValue virt() { auto m = stat();        return {__PRETTY_FUNCTION__, m.first + " " + m.second}; };
};

class Clazz2 : public Clazz1 {
public:
    ~Clazz2() override = default;
    Logger::KeyValue stat()         { auto m = Clazz1::stat(); return {__PRETTY_FUNCTION__, "Przysłoniła -> " + m.first};};
    Logger::KeyValue virt() override{ auto m = stat();         return {__PRETTY_FUNCTION__, m.first + " " + m.second};};
};


int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    {
        Clazz clazz;
        logger.log(clazz.stat(), __LINE__);
    }
    {
        Clazz1 clazz1;
        logger.log(clazz1.stat(), __LINE__);
        logger.log(clazz1.virt(), __LINE__);
    }
    {
        Clazz2 class2;
        logger.log(class2.stat(), __LINE__);
        logger.log(class2.virt(), __LINE__);
    }
    {
        auto *clazz1 = new Clazz1();
        auto *clazz2 = new Clazz2();

        logger.log(clazz1->stat(), __LINE__);
        logger.log(clazz1->virt(), __LINE__);

        logger.log(clazz2->stat(), __LINE__);
        logger.log(clazz2->virt(), __LINE__);

        delete clazz1;
        delete clazz2;
    }
    {
        Clazz1 *clazz1 = new Clazz2();

        logger.log(clazz1->stat(), __LINE__);
        logger.log(clazz1->virt(), __LINE__);

        delete clazz1;

    }
}