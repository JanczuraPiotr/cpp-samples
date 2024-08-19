#include <utility>
#include <vector>
#include <memory>
#include "classes/ControlledConstruction.hpp"


#include "../Logger.hpp"

int main()
{
    try {
        ControlledConstruction::Ptr cd1 = ControlledConstruction::create("c");
        logger.log(Logger::KeyValue{{"cd1"}, {cd1->name()}}, __LINE__, "Napis jest poprawny.");
    } catch (std::exception &ex) {
        logger.log(Logger::KeyValue{"exception", ex.what()}, __LINE__);
    }

    try
    {
        ControlledConstruction::Ptr cd2 = ControlledConstruction::create("cd2");
        logger.log(Logger::KeyValue{{"cd2"}, {cd2->name()}}, __LINE__, "Napis jest poprawny.");
    } catch (std::exception &ex) {
        logger.log(Logger::KeyValue{"exception", ex.what()}, __LINE__);

    }

}