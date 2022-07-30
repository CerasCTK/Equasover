#pragma once

#ifndef GENETICALGORITHM_ARRAY_LIST_H
#define GENETICALGORITHM_ARRAY_LIST_H

#include <initializer_list>

#include <cstdint>

#define ARRAYLIST_DEFAULT_SIZE 10
#define MAX_SIZE_THRESHOLD 1000

namespace da_st {
    template<class element_type>
    class array_list {
    private:
        /**
         * Operating array
         */
        element_type *obj_list;

        /**
         * Array size
         */
        int32_t list_size{ARRAYLIST_DEFAULT_SIZE};

        /**
         * Index of the last element in the array
         */
        int32_t top_index{-1};

        /**
         * Expand the size of the array
         */
        void resize();

        /**
         * Check the size of the array
         * @return true - if the array need to resize
         */
        bool need_to_resize();

        /**
         * Initialize array
         * @param size - the size of the array
         */
        void init_array_list(int32_t size);

    public:
        /**
         * Constructor array_list
         */
        array_list();

        /**
         * Constructor array_list
         * @param il - initializer list contains data with the same type of the array_list
         */
        array_list(std::initializer_list<element_type> il);

        /**
         * Destructor array_list
         */
        ~array_list();

        /**
         * Add an element to the array
         * @param obj - element to be added
         */
        void add(element_type obj);

        /**
         * Size of array
         * @return size of array
         */
        int32_t size();

        /**
         * Get an element in the array
         * @param index - element's index
         * @return an element in array
         */
        element_type get(int32_t index);

        /**
         * Delete all values of array
         */
        void clear();

        /**
         * Check for the existence of an element in an array
         * @param obj - element want to check
         * @return true - if the element exists in the array
         */
        bool contains(element_type obj);

        /**
         * Find the position of an element
         * @param obj - element to look for
         * @return the index of the element to be searched for
         */
        int32_t index_of(element_type obj);

        /**
         * @return true - if the array is empty
         */
        bool is_empty();

        /**
         *
         * @param obj - object
         * @return last index of this object
         */
        int32_t last_index_of(element_type obj);

        /**
         * Remove the object from the collection
         * @param index - index of object
         */
        void remove(int32_t index);

        // TODO: fix
        void remove_all(element_type obj);

        // WARN: DON'T TOUCH
        array_list &operator=(std::initializer_list<element_type> il);
    };
}

#endif
