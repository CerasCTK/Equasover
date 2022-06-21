#ifndef GENETICALGORITHM_MY_EXCEPTION_H
#define GENETICALGORITHM_MY_EXCEPTION_H

#include <exception>

class my_exception : public std::exception {
private:
    char* error_message;

public:
    explicit my_exception(const char* error_message);

    ~my_exception() noexcept override;

    const char* what() const noexcept override;
};


#endif //GENETICALGORITHM_MY_EXCEPTION_H
