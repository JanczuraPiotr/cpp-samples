#ifndef LOGGER
#define LOGGER

#include <string>

class Logger {
public:
    using KeyValue = std::pair<std::string, std::string>;

    explicit Logger(int firstColumn = 5);

    void line(const char *, int, const std::string &comment = {});
    void log(const KeyValue& msg, const std::string &comment = {});
    void log(const KeyValue& msg, int lineNr, const std::string &comment = {});
    void log(const std::string &s, int lineNr, const std::string &comment = {});

private: // methods

    void printComment(const std::string &comment) const;

private: // attributes
    int _firstColumn;
};

static Logger logger;

#endif
