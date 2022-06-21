#ifndef GENETICALGORITHM_STACK_H
#define GENETICALGORITHM_STACK_H

namespace da_st {
    template<typename element_type>
    class stack {
    private:
        element_type* p_top;
        int top_index {-1};
        int stack_size;
        element_type* stack_array;

        void init_stack(int stack_size);
    public:
        explicit stack(int stack_size);

        ~stack();

        bool is_empty();

        bool is_full();

        void push(element_type data);

        void pop();

        element_type* top();
    };
}

#endif //GENETICALGORITHM_STACK_H
