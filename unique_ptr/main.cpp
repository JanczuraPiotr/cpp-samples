#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "../Logger.hpp"

int main()
{
  int int0 = 123;
  std::unique_ptr<int> uInt1{new int{111}};
  logger.log({"*uInt1", std::to_string(*uInt1)}, __LINE__);
  std::unique_ptr<int> uInt2{std::make_unique<int>(int0)};
  logger.log({"*uInt2", std::to_string(*uInt2)}, __LINE__);
  logger.log({"int0", std::to_string(int0)}, __LINE__);
  logger.log({"uInt2", std::to_string(static_cast<bool>(uInt2))}, __LINE__);
  std::unique_ptr<int> uInt3(std::move(uInt2));
  logger.log({"uInt2", std::to_string(static_cast<bool>(uInt2))}, __LINE__);
  logger.log({"uInt3", std::to_string(static_cast<bool>(uInt3))}, __LINE__);
  logger.log({"*uInt3", std::to_string(*uInt3)}, __LINE__);
  uInt3.release();
  logger.log({"uInt3", std::to_string(static_cast<bool>(uInt3))}, __LINE__);
}