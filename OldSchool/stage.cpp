#include "stage.h"
#include <algorithm>
#include <iostream>
#include <vector>

void Stage1::Execute(vector<int>& input)
{
    for_each(input.begin(), input.end(), [](int& ele) { ele = ele * ele; });
    // for_each(input.begin(), input.end(), [ ](int& ele){std:cout << ele << "\t";});
    // std::cout << "\n";
}

void Stage2::Execute(vector<int>& input)
{
    for_each(input.begin(), input.end(), [](int& ele) { ele = 2 * ele; });
    // for_each(input.begin(), input.end(), [ ](int& ele){std:cout << ele << "\t";});
    // std::cout << "\n";
}
