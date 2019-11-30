#include "multiply.h"

Multiply::Multiply(std::queue<int> *in, std::queue<int> *out)
{
    in_ = in; out_ = out;
}

Multiply::Multiply()
{
}


int Multiply::stage_operation(int ele)
{
    std::cout << "In multiply " << ele << std::endl;
    return ele*2;
}

