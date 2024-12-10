#include <tuple>

#include "../Logger.hpp"

#include "first_directory/Wrapper.hpp"
#include "second_directory/Wrapper.hpp"

int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    first::Wrapper fdn;
    logger.log(fdn.name(), __LINE__);

    second::Wrapper sdn;
    logger.log(sdn.name(), __LINE__);

}