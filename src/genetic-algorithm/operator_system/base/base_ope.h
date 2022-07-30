#ifndef GENETICALGORITHM_BASE_OPE_H
#define GENETICALGORITHM_BASE_OPE_H

#include <cstdint>

#include "../../../core/data_structure/array_list.h"

#include "../../../core/data_type/string.h"

typedef double(*calculator)(da_st::array_list<da_ty::string> *polish_stack);

class base_ope {
private:
    da_ty::string ope_str;
    uint32_t priority;
    uint32_t influence;

    calculator cal;

public:
    /***
     *
     */
    base_ope() = default;

    /***
     *
     * @param ope_str
     * @param priority
     * @param influence
     * @param cal
     */
    base_ope(da_ty::string ope_str, uint32_t priority, uint32_t influence, calculator cal);

    /***
     *
     */
    ~base_ope();

    /***
     *
     * @return
     */
    da_ty::string get_ope_str();

    /***
     *
     * @return
     */
    uint32_t get_priority();

    /***
     *
     * @return
     */
    uint32_t get_influence();

    /***
     *
     * @return
     */
    calculator get_calculator();

    /***
     *
     * @param left
     * @param right
     * @return
     */
    friend bool operator==(base_ope &left, base_ope &right);
};

#endif
