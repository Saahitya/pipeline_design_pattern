#include "add.h"
template <class T>
Add<T>::Add()
{
}

template<class T>
T Add<T>::stage_op(T ele)
{
    //     this_thread::sleep_for(chrono::milliseconds(1000));
    std::cout << "In add " << ele << std::endl;
    return ele + 2;
}

//needed to prevent linker errors
template class Add<int>;