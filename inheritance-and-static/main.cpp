#include <tuple>
#include "../Logger.hpp"


class C1 {
public:
    virtual ~C1() = default;
    static Logger::KeyValue stat()      { return {__PRETTY_FUNCTION__, "Pierwsza definicja."}; }
};

class C2 : public C1 {
public:
    ~C2() override = default;
    static Logger::KeyValue stat()      { auto m = C1::stat(); return {__PRETTY_FUNCTION__, "Przysłoniła -> " + m.first};};
    virtual Logger::KeyValue virt()     { auto m = stat();     return {__PRETTY_FUNCTION__, m.first + " " + m.second}; };
};

class C3 : public C2 {
public:
    ~C3() override = default;
    static Logger::KeyValue stat()      { auto m = C2::stat(); return {__PRETTY_FUNCTION__, "Przysłoniła -> " + m.first};};
    Logger::KeyValue virt() override    { auto m = stat();     return {__PRETTY_FUNCTION__, m.first + " " + m.second};};
};


int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    {
        C1 c1;
        logger.log(c1.stat(), __LINE__);
    }
    {
        C2 c1;
        logger.log(c1.stat(), __LINE__);
        logger.log(c1.virt(), __LINE__);
    }
    {
        C3 c3;
        logger.log(c3.stat(), __LINE__);
        logger.log(c3.virt(), __LINE__);
    }
    {
        auto *c2 = new C2();
        auto *c3 = new C3();

        logger.log(c2->stat(), __LINE__);
        logger.log(c2->virt(), __LINE__);

        logger.log(c3->stat(), __LINE__);
        logger.log(c3->virt(), __LINE__);

        delete c3;
        delete c2;
    }
    {
        C2 *c3 = new C3();

        logger.log(c3->stat(), __LINE__);
        logger.log(c3->virt(), __LINE__);

        delete c3;

    }
}