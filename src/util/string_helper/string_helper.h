#ifndef GENETICALGORITHM_STRING_HELPER_H
#define GENETICALGORITHM_STRING_HELPER_H

namespace util {
    class string_helper {
    public:
        static char* strcpy(char* destination, const char* source);

        static int strlen(const char* string);
    };
}

#endif //GENETICALGORITHM_STRING_HELPER_H
