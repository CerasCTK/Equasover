#include "array_list.h"

#include "../exception/my_exception.h"

#define MAX_SIZE_THRESHOLD 1000

template<class type>
void copy_array(type source, int32_t src_pos, type destination, int32_t des_pos, int32_t length);

namespace da_st {
    template<class element_type>
    array_list<element_type>::array_list() {
        this->init_array_list(this->list_size);
    }

    template<class element_type>
    array_list<element_type>::~array_list() {
        if (this->obj_list != nullptr)
            delete this->obj_list;
    }

    template<class element_type>
    void array_list<element_type>::init_array_list(int32_t size) {
        this->obj_list = new element_type[size];

        if (this->obj_list == nullptr)
            throw my_exception((uint8_t *) ("Not enough memory"));
    }

    template<class element_type>
    void array_list<element_type>::resize() {
        if ((this->list_size * 3 / 2 + 1) > MAX_SIZE_THRESHOLD)
            throw my_exception(
                    (uint8_t *) ("Unable to allocate memory for array (Arraylist size exceeds the allowable limit)"));

        int32_t new_size{this->top_index * 3 / 2 + 1};
        element_type *new_array{new element_type[new_size]};

        copy_array(this->obj_list, 0, new_array, 0, this->top_index);

        delete this->obj_list;

        this->obj_list = new_array;
        this->list_size = new_size;
    }

    template<class element_type>
    bool array_list<element_type>::need_to_resize() {
        if (this->top_index >= this->list_size - 1
            || (this->top_index >= C_DEFAULT_SIZE && this->top_index < list_size / 4))
            return true;

        return false;
    }

    template<class element_type>
    void array_list<element_type>::add(element_type obj) {
        if (this->need_to_resize())
            this->resize();

        *(this->obj_list + (++this->top_index)) = obj;
    }

    template<class element_type>
    void array_list<element_type>::add(element_type obj, int32_t index) {
        if (index >= this->top_index + 1)
            return;

        int32_t new_arr_length{++this->top_index};

        if (this->need_to_resize())
            this->resize();

        element_type *new_arr{new element_type[new_arr_length]};

        copy_array(this->obj_list, 0, new_arr, 0, index);
        *(new_arr + index) = obj;

        int32_t num_of_remaining_elements{this->top_index - index - 1 - 1};
        copy_array(this->obj_list, index, new_arr, index + 1, num_of_remaining_elements);
    }

    template<class element_type>
    int32_t array_list<element_type>::get_list_size() {
        if (this->top_index < 0) return 0;
        return this->top_index + 1;
    }

    template<class element_type>
    element_type array_list<element_type>::get(int32_t index) {
        if (index > this->top_index) throw my_exception((uint8_t *) ("Index out of bound"));

        return *(this->obj_list + index);
    }

    template<class element_type>
    void array_list<element_type>::clear() {
        if (this->obj_list != nullptr)
            delete this->obj_list;

        this->top_index = -1;

        this->init_array_list(this->list_size);
    }

    template<class element_type>
    bool array_list<element_type>::contains(element_type obj) {
        for (int32_t i{0}; i < this->top_index; i++)
            if (*(this->obj_list + i) == obj)
                return true;

        return false;
    }

    template<class element_type>
    int32_t array_list<element_type>::index_of(element_type obj) {
        for (int32_t i{0}; i < this->top_index; i++)
            if (*(this->obj_list + i) == obj) return i;
        return -1;
    }

    template<class element_type>
    bool array_list<element_type>::is_empty() {
        if (this->top_index < 0) return true;
        return false;
    }

    template<class element_type>
    int32_t array_list<element_type>::last_index_of(element_type obj) {
        for (int32_t i{this->top_index - 1}; i >= 0; i--)
            if (*(this->obj_list + i) == obj) return i;
        return -1;
    }

    template<class element_type>
    void array_list<element_type>::remove(int32_t index) {
        if (index > this->top_index || index < 0)
            throw my_exception((uint8_t *) ("Index out of bound"));

        int32_t new_arr_length{this->top_index - 1};
        element_type *new_arr{new element_type[new_arr_length]};

        copy_array(this->obj_list, 0, new_arr, 0, index);

        int32_t num_of_remaining_elements{this->top_index - index - 1};
        copy_array(this->obj_list, index + 1, new_arr, index, num_of_remaining_elements);

        delete this->obj_list;

        this->obj_list = new_arr;
        this->top_index -= 1;
    }

    template<class element_type>
    void array_list<element_type>::remove(element_type obj) {
        int32_t obj_index{index_of(obj)};

        if (obj_index < 0) return;

        int32_t new_arr_length{this->top_index - 1};
        element_type *new_arr{new element_type[new_arr_length]};

        copy_array(this->obj_list, 0, new_arr, 0, obj_index);

        int32_t num_of_remaining_elements{this->top_index - obj_index - 1};
        copy_array(this->obj_list, obj_index + 1, new_arr, obj_index, num_of_remaining_elements);

        delete this->obj_list;

        this->obj_list = new_arr;
        this->top_index -= 1;
    }
}

template<class type>
void copy_array(type source, int32_t src_pos, type destination, int32_t des_pos, int32_t length) {
    if (destination == nullptr)
        throw my_exception((uint8_t *) ("Destination is null"));

    for (int32_t i{0}; i < length; i++)
        *(destination + des_pos + i) = *(source + src_pos + i);
}