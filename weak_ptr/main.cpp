//
// Created by piotr@janczura.pl on 2022.05.011
//
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "../Logger.hpp"

int main()
{
    int i = 9;

    std::weak_ptr<int> weak;
    logger.log("weak.expired() = " + std::to_string(weak.expired()), __LINE__);
    logger.log("weak.use_count() = " + std::to_string(weak.use_count
    ()), __LINE__);

    {
        std::shared_ptr<int> int0 = std::make_shared<int>(i);
        weak = int0;
        logger.log("weak.expired() = " + std::to_string(weak.expired()), __LINE__);
        logger.log("weak.use_count() = " + std::to_string(weak.use_count()), __LINE__);

        std::weak_ptr<int> weakPtr0(int0);
        logger.log("weakPtr0.expired() = " + std::to_string(weakPtr0.expired()), __LINE__);
        logger.log("weakPtr0.use_count() = " + std::to_string(weakPtr0.use_count()), __LINE__);
        logger.log("*weakPtr0.lock() = " + std::to_string(*weakPtr0.lock()), __LINE__);
        {
            auto shared = int0;
            logger.log("weak.expired() = " + std::to_string(weak.expired()), __LINE__);
            logger.log("weak.use_count() = " + std::to_string(weak.use_count()), __LINE__);
            {
                auto shared1 = int0;
                logger.log("weak.expired() = " + std::to_string(weak.expired()), __LINE__);
                logger.log("weak.use_count() = " + std::to_string(weak.use_count()), __LINE__);
                {
                    auto shared2 = weak.lock();
                    logger.log("weak.expired() = " + std::to_string(weak.expired()), __LINE__);
                    logger.log("weak.use_count() = " + std::to_string(weak.use_count()), __LINE__);
                }
            }
        }
        logger.log("weak.expired() = " + std::to_string(weak.expired()), __LINE__);
        logger.log("weak.use_count() = " + std::to_string(weak.use_count()), __LINE__);
    }
    logger.log("weak.expired() = " + std::to_string(weak.expired()), __LINE__);
    logger.log("weak.use_count() = " + std::to_string(weak.use_count()), __LINE__);

}