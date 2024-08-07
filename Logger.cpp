//
// Created by piotr@janczura.pl on 2024.07.01
//

#include "Logger.hpp"

#include <iostream>
#include <iomanip>

Logger::Logger(int col)
    : _col(col)
{

}

void Logger::line(const char *file, int line)
{
    std::cout << file << ':' << line << std::endl;
}

void Logger::log(Message msg)
{
    if (msg.second.empty()) {
        std::cout << std::setw(5) << "\t" << msg.first << std::endl;
    } else {
        std::cout << std::setw(5) << "\t" << msg.first << " | " << msg.second << std::endl;
    }
}

void Logger::log(Message msg, int lineNr)
{
    if (msg.second.empty()) {
        std::cout << std::setw(5) << std::right << lineNr << ":\t" << msg.first << std::endl;
    } else {
        std::cout << std::setw(5) << std::right << lineNr << ":\t" << msg.first << " | " << msg.second  << std::endl;
    }
}

void Logger::log(Message msg, const std::string &note, int lineNr)
{
    if (msg.second.empty()) {
        std::cout << std::setw(5) << std::right << lineNr << ":\t" << msg.first << " | " << note << std::endl;
    } else {
        std::cout << std::setw(5) << std::right << lineNr << ":\t" << msg.first << " | " << msg.second << " | " << note << std::endl;
    }
}

void Logger::log(const std::string &s, int lineNr)
{
    std::cout << std::setw(5) << std::right << lineNr << ":\t" << s << std::endl;
}
