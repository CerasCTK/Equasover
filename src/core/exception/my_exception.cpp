#include "my_exception.h"

#include "../../util/string_helper/string_helper.h"

my_exception::my_exception(const char* error_message) {
    const int message_length = util::string_helper::strlen(error_message);
    this->error_message = new char[message_length];
    util::string_helper::strcpy(this->error_message, error_message);
}

my_exception::~my_exception() noexcept {
    delete error_message;
}

const char *my_exception::what() const noexcept {
    return this->error_message;
}
