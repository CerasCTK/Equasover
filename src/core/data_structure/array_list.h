#pragma once

#ifndef GENETICALGORITHM_ARRAY_LIST_H
#define GENETICALGORITHM_ARRAY_LIST_H

namespace da_st {
    template<class element_type>
    class array_list {
    private:
        static const int C_DEFAULT_SIZE = 10;

        int list_size{C_DEFAULT_SIZE};
        element_type *obj_list;

        int top_index{-1};

        void resize();

        bool need_to_resize();

        void init_array_list(int size);

    public:
        array_list();

        ~array_list();

        void add(element_type obj);

        int get_list_size();

        element_type get(int index);

        void clear();

        bool contains(element_type obj);

        int index_of(element_type obj);

        bool is_empty();

        int last_index_of(element_type obj);

        void remove(int index);

        void remove(element_type obj);
    };
}

#endif
