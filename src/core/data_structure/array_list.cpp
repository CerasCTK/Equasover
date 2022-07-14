#include "array_list.h"

#include "../exception/my_exception.h"

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

    }

    template<class element_type>
    bool array_list<element_type>::need_to_resize() {
        if (this->top_index >= this->list_size - 1) return true;
        return false;
    }

    template<class element_type>
    void array_list<element_type>::add(element_type obj) {
        if (this->need_to_resize())
            this->resize();

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
        delete this->obj_list;
        this->init_array_list(this->list_size);
    }

    template<class element_type>
    bool array_list<element_type>::contains(element_type obj) {
        // TODO:
        return false;
    }

    template<class element_type>
    int32_t array_list<element_type>::index_of(element_type obj) {
        return 0;
    }

    template<class element_type>
    bool array_list<element_type>::is_empty() {
        if (this->top_index < 0) return true;
        return false;
    }

    template<class element_type>
    int32_t array_list<element_type>::last_index_of(element_type obj) {
        // TODO:
        return 0;
    }

    template<class element_type>
    void array_list<element_type>::remove(int32_t index) {
        if (index > this->top_index)
            throw my_exception((uint8_t *) ("Index out of bound"));
        // TODO:
    }

    template<class element_type>
    void array_list<element_type>::remove(element_type obj) {
        // TODO:
    }
}