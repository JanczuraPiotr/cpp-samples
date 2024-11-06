#include <string>
#include <future>

#include "../../Logger.hpp"

int async1()
{
    logger.log("", __LINE__);
    int x;
    for (int i = 0; i < 123456789; ++i) {
        x = i;
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    logger.log("", __LINE__);
    return x;
}

void async2(std::future<int> fi)
{
    logger.log("", __LINE__);
    logger.log({"FI" , std::to_string(fi.get())}, __LINE__);
}

int main()
{
    logger.log("Example name : " + std::string(EXAMPLE_NAME), __LINE__);

    // Pay attention to the order of the lines in the terminal.
    std::future<int> result = std::async(std::launch::async, async1);
    std::ignore = std::async(std::launch::async, async2, std::move(result));
}