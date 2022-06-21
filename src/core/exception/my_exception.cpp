#include "my_exception.h"

#include "../../util/string_helper/string_helper.h"

my_exception::my_exception(const char* error_message) {
    util::string_helper::strcpy(this->error_message, error_message);
}

my_exception::~my_exception() noexcept {
    delete error_message;
}

const char *my_exception::what() const noexcept {
    return this->error_message;
}
