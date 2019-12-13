#include "add.h"

Add::Add()
{
}

float Add::stage_operation(float ele)
{
    //     this_thread::sleep_for(chrono::milliseconds(1000));
    std::cout << "In add " << ele << std::endl;
    return ele + 2.2;
}
