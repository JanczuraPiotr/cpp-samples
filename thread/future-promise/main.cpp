#include <string>
#include <thread>
#include <future>
#include <optional>

#include "../../Logger.hpp"

typedef std::promise<std::string> Promise;
typedef std::future<std::string> Future;

class AnyException : public std::exception {
public:
    explicit AnyException(std::string exception) : _exception(std::move(exception)) { };
    ~AnyException() noexcept override = default;
    const char *what() const noexcept override { return _exception.c_str(); }
private:
    std::string _exception;
};

enum class SymulateException {
    no,
    yes
};

void producer(Promise promise, SymulateException symulateException)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));

    try {
        if (SymulateException::yes == symulateException) {
            throw AnyException("Exception from the producer.");
        } else {
            promise.set_value("Value from the producer.");
        }
    } catch (...) {
        promise.set_exception(std::current_exception());
    }
}

void consumer(Future future)
{
    try {
        std::string result = future.get();
        logger.log("odebrano napis : " + result, __LINE__);
    } catch (std::exception &exception) {

        logger.log("odebrano informację o wyjątku : " + std::string(exception.what()) , __LINE__);
    }
}

int main()
{
    logger.log("Example name : " + std::string(EXAMPLE_NAME), __LINE__);
    {
        Promise promise;
        Future future = promise.get_future();

        std::ignore = std::async(std::launch::async, producer, std::move(promise), SymulateException::no);
        std::ignore = std::async(std::launch::async, consumer, std::move(future));
    }
        logger.log("", __LINE__);
    {
        Promise promise;
        Future future = promise.get_future();

        std::ignore = std::async(std::launch::async, producer, std::move(promise), SymulateException::yes);
        std::ignore = std::async(std::launch::async, consumer, std::move(future));
    }
}