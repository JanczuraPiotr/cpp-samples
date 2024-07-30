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

    std::cout << "relative_path :.. " << path.relative_path() << std::endl;
    std::cout << "parent_path :.... " << path.parent_path() << std::endl;
    std::cout << "filename :....... " << path.filename() << std::endl;
    std::cout << "stem :........... " << path.stem() << std::endl;
    std::cout << "extension :...... " << path.extension() << std::endl;
}