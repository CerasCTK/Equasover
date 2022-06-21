#include "my_exception.h"

my_exception::my_exception(char* error_message) {
    this->error_message = error_message;
}

my_exception::~my_exception() noexcept {
    delete error_message;
}

const char *my_exception::what() const noexcept {
    return error_message;
}
