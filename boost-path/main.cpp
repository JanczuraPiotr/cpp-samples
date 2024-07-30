//
// Created by piotr@janczura.pl on 2022.05.011
//
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <boost/filesystem.hpp>

int main()
{
  boost::filesystem::path path{"/home/piotr/plik.cos"};

  std::cout << path.relative_path()  << std::endl;
  std::cout << path.parent_path()  << std::endl;
  std::cout << path.filename()  << std::endl;
  std::cout << path.stem()  << std::endl;
  std::cout << path.extension() << std::endl;
}