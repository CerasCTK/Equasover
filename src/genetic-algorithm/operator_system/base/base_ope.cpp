#include "base_ope.h"

base_ope::base_ope(da_ty::string ope_str, uint32_t priority, uint32_t influence, calculator cal)
        : ope_str(ope_str), priority(priority), influence(influence) {
    this->cal = cal;
}

base_ope::~base_ope() {
    // NOTHING TO WRITE
}

da_ty::string base_ope::get_ope_str() {
    return this->ope_str;
}

uint32_t base_ope::get_priority() {
    return this->priority;
}

uint32_t base_ope::get_influence() {
    return this->influence;
}

calculator base_ope::get_calculator() {
    return this->cal;
}

bool operator==(base_ope &left, base_ope &right) {
    return false;
}
