#include "add.h"


Add::Add()
{
}

int Add::stage_operation(int ele)
{
    //     this_thread::sleep_for(chrono::milliseconds(1000));
    std::cout << "In add " << ele << std::endl;
    return ele + 2;
}
