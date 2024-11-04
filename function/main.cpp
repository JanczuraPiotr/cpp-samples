#include <functional>
#include <utility>
#include <vector>

#include "../Logger.hpp"

typedef std::function<void(void)> FVoidVoid;
typedef std::function<int(int)> FIntInt;
typedef std::vector<FIntInt> VFIntInt;

class C1 {
public:
    explicit C1(FVoidVoid fVoidVoid)
        : _fVoidVoid(std::move(fVoidVoid)) {

    };

    void replace(FVoidVoid fVoidVoid) {
        _fVoidVoid = std::move(fVoidVoid);
    }

    void call() {
        _fVoidVoid();
    }

private:
    FVoidVoid _fVoidVoid;
};

class C2 {
public:
    C2() = default;

    void callback() { logger.log(__PRETTY_FUNCTION__ , __LINE__); }
    int callback(int i) { logger.log(__PRETTY_FUNCTION__ , __LINE__); return i;}

};


int main()
{
    {
        FVoidVoid fVoidVoid;

        try {
            fVoidVoid();
        } catch (std::bad_function_call &ex) {
            logger.log("Expected exception", __LINE__);
        } catch (...) {
            logger.log("Unexpected exception.", __LINE__);
        }

        logger.log("--------------", __LINE__);
        auto namedLambda = []() { logger.log("Named lambda", __LINE__); };
        fVoidVoid = namedLambda;
        fVoidVoid();

        logger.log("--------------", __LINE__);

        C1 c1(fVoidVoid);
        c1.call();
        c1.replace([] () { logger.log("Anonymous lambda.", __LINE__); });
        c1.call();

        logger.log("--------------",__LINE__);

        C2 c2;
        fVoidVoid = std::bind(static_cast<void(C2::*)(void)>(&C2::callback), c2);
        fVoidVoid();

        FIntInt fIntInt;
        fIntInt = std::bind(static_cast<int(C2::*)(int)>(&C2::callback), c2, std::placeholders::_1);
        logger.log({"fIntInt(3)", std::to_string(fIntInt(3))}, __LINE__);
    }

    logger.log("--------------",__LINE__);
    {
        VFIntInt vIntInt;
        for (int ix = 0; ix < 5; ++ix) {
            vIntInt.emplace_back(
                [ix] (int number) -> int {
                    int iteration = ix; // <- Important
                    logger.log({"Iteration{" + std::to_string(iteration) + "}",
                                "Number{" + std::to_string(number) + "}"},
                               __LINE__);
                    return iteration;
                }
            );
        }

        for(auto &it : vIntInt) {
            static int number{10};
            it(number++);
        }

    }


}