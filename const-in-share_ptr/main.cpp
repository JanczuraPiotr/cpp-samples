#include <string>
#include <utility>
#include <vector>
#include <memory>

#include "../Logger.hpp"

class C1 {
public:
    using Ptr = std::shared_ptr<C1>;
    using CPtr = std::shared_ptr<const C1>;

    explicit C1(std::string &&name) : _name(std::move(name)) {
        logger.log(__PRETTY_FUNCTION__, __LINE__);
    }
    virtual ~C1() = default;

    void name(const std::string &name) {
        logger.log(__PRETTY_FUNCTION__, __LINE__);
        _name = name;
    }
    std::string name() const {
        logger.log(__PRETTY_FUNCTION__, __LINE__);
        return _name;
    }

private:
    std::string _name;
};

int main()
{
    {
        C1::Ptr ptr = std::make_shared<C1>("C1");
        ptr->name("");
        ptr->name();

        C1::CPtr cptr = ptr;
        // cptr->name(""); błąd kompilacji.
    }
    {
        C1::CPtr ptr = std::make_shared<const C1>("const C1");
        //ptr->name(""); błąd kompilacji.
        ptr->name();
    }
    {
        C1::Ptr ptr = std::make_shared<C1>("C1");
        C1::CPtr cptr = std::make_shared<const C1>("const C1");
        //ptr->name(""); błąd kompilacji.
        ptr->name();

        auto cptr1 = cptr;
        //cptr1->name(""); błąd kompilacji.
        cptr1->name();

        // C1::Ptr cptr2 = cptr; błąd kompilacji.
    }
}