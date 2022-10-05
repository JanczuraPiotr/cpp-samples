//
// Created by piotr@janczura.pl on 2022.05.011
//
#include <iostream>
#include <string>
#include <vector>
#include <memory>


int main()
{

  int int0 = 123;
  std::unique_ptr<int> uInt1{new int{111}};
  std::cout<< "*uInt1     " << " = " << *uInt1 << std::endl;

  std::unique_ptr<int> uInt2{std::make_unique<int>(int0)};
  std::cout<< "uInt2      " << " = " << uInt2.get() << std::endl;


  std::unique_ptr<int> uInt3(std::move(uInt2));
  std::cout<< "(bool)uInt2      " << " = " << (bool )uInt2 << std::endl;
  std::cout<< "(bool)uInt3      " << " = " << (bool )uInt3 << std::endl;
  std::cout<< "*uInt3      " << " = " << *uInt3 << std::endl;
  uInt3.release();
  std::cout<< "(bool)uInt3      " << " = " << (bool )uInt3 << std::endl;
  std::cout<< "*uInt3      " << " = " << *uInt3 << std::endl;



}