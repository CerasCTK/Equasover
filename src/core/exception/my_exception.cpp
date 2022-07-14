#include "my_exception.h"

#include "../../util/string_helper/string_helper.h"

my_exception::my_exception(const uint8_t *error_message) {
    const int32_t message_length{string_helper::strlen(error_message)};
    this->error_message = new uint8_t[message_length + 1];
    string_helper::strcpy(this->error_message, error_message);
}

my_exception::~my_exception() noexcept {
    delete error_message;
}

const char *my_exception::what() const noexcept {
    return ((char *) this->error_message);
}


