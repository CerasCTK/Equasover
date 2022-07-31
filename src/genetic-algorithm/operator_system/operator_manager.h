#ifndef GENETICALGORITHM_OPERATOR_MANAGER_H
#define GENETICALGORITHM_OPERATOR_MANAGER_H

#include <cstdint>

#include "../../core/data_structure/array_list.h"
#include "../../core/data_structure/stack.h"

#include "../../core/data_type/string.h"

#include "base/base_ope.h"

#define DEFAULT_OPERATOR base_ope(da_ty::string(), 0, 0, nullptr)

class operator_manager {
private:
    /**
     *
     */
    da_st::array_list<base_ope> *operator_list{new da_st::array_list<base_ope>()};

    /**
     *
     */
    void init_operator_list();

    /**
     *
     * @param cal
     * @return
     */
    friend base_ope get_ope_from_fun(calculator cal);

    /**
     *
     */
    operator_manager() = default;

public:
    /**
     *
     * @return
     */
    static operator_manager *get_operator_manager();

    /**
     *
     * @param sign
     * @return
     */
    base_ope get_operator(da_ty::string sign);

    /**
     *
     * @return
     */
    da_st::array_list<da_ty::string> *get_sign_list();

    da_st::array_list<base_ope> *get_ope_list();
};

#endif
