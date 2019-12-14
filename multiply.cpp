#include "multiply.h"

Multiply::Multiply()
{
}

int Multiply::stage_op(int ele)
{
    std::cout << "In multiply " << ele << std::endl;
    return ele * 2;
}
