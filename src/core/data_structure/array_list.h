#pragma once

#ifndef GENETICALGORITHM_ARRAY_LIST_H
#define GENETICALGORITHM_ARRAY_LIST_H

#include <cstdint>

#define C_DEFAULT_SIZE 10
#define MAX_SIZE_THRESHOLD 1000

namespace da_st {
    template<class element_type>
    class [[maybe_unused]] array_list {
    private:
        int32_t list_size{C_DEFAULT_SIZE};
        element_type *obj_list;

        int32_t top_index{-1};

        void resize();

        bool need_to_resize();

        void init_array_list(int32_t size);

    public:
        array_list();

        ~array_list();

        void add(element_type obj);

        int32_t size();

        element_type get(int32_t index);

        void clear();

        bool contains(element_type obj);

        int32_t index_of(element_type obj);

        bool is_empty();

        int32_t last_index_of(element_type obj);

        void remove(int32_t index);
    };
}

#endif
