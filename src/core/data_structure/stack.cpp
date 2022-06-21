#include "stack.h"

#include "../exception/my_exception.h"

namespace da_st {

    template<typename element_type>
    void stack<element_type>::init_stack(int stack_size) {
        this->stack_size = stack_size;
        this->p_top = nullptr;

        this->stack_array = new element_type[stack_size];
        if (this->stack_array == nullptr)
            throw my_exception("Not enough memory");
    }

    template<typename element_type>
    stack<element_type>::stack(int stack_size) {
        this->init_stack(stack_size);
    }

    template<typename element_type>
    stack<element_type>::~stack() {
        delete this->p_top;
        delete this->stack_array;
    }

    template<typename element_type>
    bool stack<element_type>::is_empty() {
        if (this->top_index == -1 || this->p_top == nullptr) return true;
        return false;
    }

    template<typename element_type>
    bool stack<element_type>::is_full() {
        if (this->top_index >= this->stack_size - 1) return true;
        return false;
    }

    template<typename element_type>
    void stack<element_type>::push(element_type data) {
        if (this->is_full())
            throw my_exception("Stack is full");

        this->stack_array[++this->top_index] = data;
        this->p_top = &data;
    }

    template<typename element_type>
    void stack<element_type>::pop() {
        if (this->is_empty())
            throw my_exception("Stack is empty");

        --this->top_index;
    }

    template<typename element_type>
    element_type *stack<element_type>::top() {
        if (this->is_empty()) return nullptr;
        return p_top;
    }
}





