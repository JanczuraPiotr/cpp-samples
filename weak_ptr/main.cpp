//
// Created by piotr@janczura.pl on 2022.05.011
//
#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main()
{
  int i = 9;
  std::shared_ptr<int> int0 = std::make_shared<int>(i);
  std::weak_ptr<int> weakPtr0(int0);
  std::cout << "weakPtr0.expired()" << " = " << weakPtr0.expired() << std::endl;
  std::cout << "weakPtr0.use_count()" << " = " << weakPtr0.use_count() << std::endl;
  std::cout << "*weakPtr0.lock()" << " = " << *weakPtr0.lock() << std::endl;
  auto int1 = std::make_shared<int>(122);
  std::weak_ptr<int> wEmpty(int1);
  std::cout << "wEmpty.expired()" << " = " << wEmpty.expired() << std::endl;
  std::cout << "wEmpty.use_count()" << " = " << wEmpty.use_count() << std::endl;
  std::cout << "*wEmpty.lock()" << " = " << *wEmpty.lock() << std::endl;



}