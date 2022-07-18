#include "stack.h"

#include "../exception/my_exception.h"

#include "../data_type/string.h"

namespace da_st {
    template<class element_type>
    stack<element_type>::stack(int32_t capacity) {
        this->stack_capacity = capacity;

        this->stack_array = new element_type[capacity];
        if (this->stack_array == nullptr)
            throw my_exception((uint8_t *) ("Not enough memory"));
    }

    template<class element_type>
    stack<element_type>::~stack() {
//        if (this->stack_array != nullptr)
//            delete this->stack_array;
    }

    template<class element_type>
    bool stack<element_type>::empty() {
        if (this->last_item_index == -1) return true;
        return false;
    }

    template<class element_type>
    bool stack<element_type>::is_full() {
        if (this->last_item_index == this->stack_capacity - 1) return true;
        return false;
    }

    template<class element_type>
    void stack<element_type>::push(element_type data) {
        if (this->is_full())
            throw my_exception((uint8_t *) ("Stack is full"));

        this->stack_array[++this->last_item_index] = data;
    }


    template<class element_type>
    void stack<element_type>::pop() {
        if (this->empty())
            throw my_exception((uint8_t *) ("Stack is empty"));

        --this->last_item_index;
    }

    template<class element_type>
    element_type stack<element_type>::top() {
        if (this->empty()) throw my_exception((uint8_t *) ("Stack is empty"));
        return *(this->stack_array + this->last_item_index);
    }

    template<class element_type>
    int32_t stack<element_type>::size() const {
        return this->last_item_index + 1;
    }

    template<class element_type>
    void stack<element_type>::print() {
        for (int32_t i{0}; i <= this->last_item_index; i++) {
            std::cout << *(this->stack_array + i) << " ";
        }
    }

    template
    class stack<bool>;

    template
    class stack<bool *>;

    template
    class stack<char>;

    template
    class stack<char *>;

    template
    class stack<uint8_t>;

    template
    class stack<uint8_t *>;

    template
    class stack<int16_t>;

    template
    class stack<int16_t *>;

    template
    class stack<int32_t>;

    template
    class stack<int32_t *>;

    template
    class stack<int64_t>;

    template
    class stack<int64_t *>;

    template
    class stack<float>;

    template
    class stack<float *>;

    template
    class stack<double>;

    template
    class stack<double *>;

    template
    class stack<da_ty::string>;

    template
    class stack<da_ty::string *>;
}





