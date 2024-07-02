//
// Created by piotr@janczura.pl on 2024.07.01
//

#ifndef _LOGGER
#define _LOGGER

#include <string>

class Logger {
public:
    using Message = std::pair<std::string, std::string>;

    explicit Logger(int col);

    void line(const char *, int);
    void log(Message msg);
    void log(Message msg, int lineNr);
    void log(Message msg, const std::string &note, int lineNr);
    void log(const std::string &s, int lineNr);

private:
    int _col;
};


#endif //_LOGGER
