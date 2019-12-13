#include "stage_old.h"
#include <iostream>
#include <vector>
#include <algorithm>

void Stage1::Execute(vector<int>& input) {
  for_each(input.begin(), input.end(), [ ](int& ele){ele = ele*ele;});
  // for_each(input.begin(), input.end(), [ ](int& ele){std:cout << ele << "\t";});
  // std::cout << "\n";
}

void Stage2::Execute(vector<int>& input) {
  for_each(input.begin(), input.end(), [ ](int& ele){ele = 2*ele;});
  // for_each(input.begin(), input.end(), [ ](int& ele){std:cout << ele << "\t";});
  // std::cout << "\n";
}


