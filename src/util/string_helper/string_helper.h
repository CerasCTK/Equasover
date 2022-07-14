#pragma once

#ifndef GENETICALGORITHM_STRING_HELPER_H
#define GENETICALGORITHM_STRING_HELPER_H

namespace string_helper {
    char *strcpy(char *destination, const char *source);

    char *strcat(char *destination, const char *source);

    bool strcmp(const char *first, const char *sec);

    int strlen(const char *text);

    void get_text(char *container, const int number_of_chars, char stop_char = '\n');

    int count_char(const char *text, char character);

    int pos(const char *text, char character);
}

#endif
