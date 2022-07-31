#pragma once

#ifndef GENETICALGORITHM_MY_EXCEPTION_H
#define GENETICALGORITHM_MY_EXCEPTION_H

#include <exception>

#include <cstdint>

class my_exception : public std::exception {
private:
    /**
     *
     */
    uint8_t *error_message;

public:
    /**
     *
     * @param error_message
     */
    explicit my_exception(const uint8_t *error_message);

    /**
     *
     */
    ~my_exception() noexcept override;

    /**
     *
     * @return
     */
    const char *what() const noexcept override;
};

#endif
