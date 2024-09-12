#include <tuple>

#include "../Logger.hpp"

int main() {

    int i{1};
    double d{2.0};

    decltype(i + d) item{i + d};


    logger.log({{"decltype(i + d) item{i + d}"}, {std::to_string(item)}}, __LINE__);
}