#ifndef GENETICALGORITHM_STRING_HELPER_H
#define GENETICALGORITHM_STRING_HELPER_H

namespace util {
    class string_helper {
    public:
        static char* strcpy(char* destination, const char* source);

        static int strlen(const char* string);

        static void get_text(char* container, const int number_of_chars, char stop_char = '\n');
    };
}

#endif //GENETICALGORITHM_STRING_HELPER_H
