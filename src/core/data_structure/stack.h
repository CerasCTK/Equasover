#ifndef GENETICALGORITHM_STACK_H
#define GENETICALGORITHM_STACK_H

namespace da_st {
    template<class element_type>
    class stack {
    private:
        element_type* p_top;
        int top_index {-1};
        int stack_capacity;
        element_type* stack_array;

        void init_stack(int capacity);
    public:
        explicit stack(int capacity);

        ~stack();

        bool is_empty();

        bool is_full();

        void push(element_type data);

        void pop();

        element_type top();
    };
}

#endif //GENETICALGORITHM_STACK_H
