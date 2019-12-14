#include "multiply.h"

template <class T>
Multiply<T>::Multiply(T num): num_(num)
{
}

template <class T>
T Multiply<T>::stage_op(T ele)
{
    std::cout << "In multiply " << ele << std::endl;
    return ele * num_;
}

//needed to prevent linker issues
template class Multiply<int>;