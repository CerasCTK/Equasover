#pragma once

#ifndef GENETICALGORITHM_STACK_H
#define GENETICALGORITHM_STACK_H

#include <cstdint>

namespace da_st {
    template<class element_type>
    class stack {
    private:
        /**
         * Container
         */
        element_type *stack_array;
        /**
         * Size of the container
         */
        int32_t stack_capacity;
        /**
         * Index of the last item
         */
        int32_t last_item_index{-1};

    public:
        /**
         * Constructor stack
         * @param capacity - size of the stack
         */
        stack(int32_t capacity);

        /**
         * Destructor stack
         */
        ~stack();

        /**
         * Test whether container is empty
         * @return true - if the stack is empty
         */
        bool empty();

        /**
         * Test whether container is full
         * @return true - if the stack is full
         */
        bool is_full();

        /**
         * Inserts a new element at the top of the stack, above its current top element.
         * @param data - value to which the inserted element is initialized.
         */
        void push(element_type data);

        /**
         * Remove top element
         */
        void pop();

        /**
         * Access next element
         * @return a reference to the top element in the stack
         */
        element_type top();

        /**
         *
         * @return the number of elements in the stack
         */
        int32_t size() const;

        void print();
    };
}

#endif
