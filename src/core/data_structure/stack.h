#pragma once

#ifndef GENETICALGORITHM_STACK_H
#define GENETICALGORITHM_STACK_H

#include <cstdint>

namespace da_st {
    template<class element_type>
    class stack {
    private:
        int32_t last_item_index{-1};
        int32_t stack_capacity;
        element_type *stack_array;

    public:
        stack(int32_t capacity);

        ~stack();

        bool empty();

        bool is_full();

        void push(element_type data);

        void pop();

        element_type top();

        int32_t size() const;
    };
}

#endif
