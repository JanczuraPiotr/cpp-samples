
#include <string>
#include <vector>
#include <memory>

#include "../Logger.hpp"

int main()
{
    int i = 9;

    std::weak_ptr<int> weak;
    logger.log({"weak.expired()", std::to_string(weak.expired())}, __LINE__);
    logger.log({"weak.use_count()", std::to_string(weak.use_count())}, __LINE__);

    {
        std::shared_ptr<int> sharedPtr0 = std::make_shared<int>(i);
        weak = sharedPtr0;
        logger.log({"sharedPtr0", std::to_string(*sharedPtr0)}, __LINE__);
        logger.log({"weak.expired()", std::to_string(weak.expired())}, __LINE__);
        logger.log({"weak.use_count()", std::to_string(weak.use_count())}, __LINE__);

        {
            auto sharedPtr1 = weak.lock();
            logger.log({"sharedPtr1", std::to_string(*sharedPtr1)}, __LINE__);
            logger.log({"weak.expired()", std::to_string(weak.expired())}, __LINE__);
            logger.log({"weak.use_count()", std::to_string(weak.use_count())}, __LINE__);
        }
        logger.log({"weak.expired()", std::to_string(weak.expired())}, __LINE__);
        logger.log({"weak.use_count()", std::to_string(weak.use_count())}, __LINE__);
    }
    logger.log({"weak.expired()", std::to_string(weak.expired())}, __LINE__);
    logger.log({"weak.use_count()", std::to_string(weak.use_count())}, __LINE__);
}