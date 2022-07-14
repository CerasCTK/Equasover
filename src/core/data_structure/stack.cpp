#include "stack.h"

#include "../exception/my_exception.h"

namespace da_st {
    template<class element_type>
    void stack<element_type>::init_stack(int32_t capacity) {
        this->stack_capacity = capacity;
        this->p_top = nullptr;

        this->stack_array = new element_type[capacity];
        if (this->stack_array == nullptr)
            throw my_exception((uint8_t *) ("Not enough memory"));
    }

    template<class element_type>
    stack<element_type>::stack(int32_t capacity) {
        this->init_stack(capacity);
    }

    template<class element_type>
    stack<element_type>::~stack() {
        if (this->p_top != nullptr)
            delete this->p_top;

        if (this->stack_array != nullptr)
            delete this->stack_array;
    }

    template<class element_type>
    bool stack<element_type>::is_empty() {
        if (this->top_index == -1 || this->p_top == nullptr) return true;
        return false;
    }

    template<class element_type>
    bool stack<element_type>::is_full() {
        if (this->top_index >= this->stack_capacity - 1) return true;
        return false;
    }

    template<class element_type>
    void stack<element_type>::push(element_type data) {
        if (this->is_full())
            throw my_exception((uint8_t *) ("Stack is full"));

        this->stack_array[++this->top_index] = data;
        this->p_top = &data;
    }

    template<class element_type>
    void stack<element_type>::pop() {
        if (this->is_empty())
            throw my_exception((uint8_t *) ("Stack is empty"));

        --this->top_index;
        if (this->top_index < 0) this->p_top = nullptr;
        else this->p_top = &this->stack_array[this->top_index];
    }

    template<class element_type>
    element_type stack<element_type>::top() {
        if (this->is_empty()) throw my_exception((uint8_t *) ("Stack is empty"));
        return *p_top;
    }

    template
    class stack<bool>;

    template
    class stack<char>;

    template
    class stack<uint8_t>;

    template
    class stack<int16_t>;

    template
    class stack<int32_t>;

    template
    class stack<int64_t>;

    template
    class stack<float>;

    template
    class stack<double>;
}





