#ifndef GENETICALGORITHM_CLONEABLE_H
#define GENETICALGORITHM_CLONEABLE_H

template<class type>
class cloneable {
public:
    virtual type clone() = 0;
};

#endif
