#include <iostream>
#include <vector>
#include <algorithm>
#include "basic_pipeline.h"
#include "functional.h"
using namespace std;

  std::string true_cxx =
#ifdef __clang__
   "clang++";
#else
   "g++";
#endif

void ver_string(int a, int b, int c) {
  cout << "Version Info " <<  a << '.' << b << '.' << c << " " << __cplusplus << endl;
}



void RunBasicPipeline();
void RunBasicFunctionalPipeline();
void RunAdvFunctionalPipeline();

int main() {

#ifdef __clang__
    ver_string(__clang_major__, __clang_minor__, __clang_patchlevel__);
#else
    ver_string(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#endif

  // RunBasicPipeline();
  //runs only in c++14
  // RunBasicFunctionalPipeline();
  // RunBasicFunctionalPipeline();
  RunAdvFunctionalPipeline();
}

void RunBasicPipeline() {
  BasicPipeline bp;
  vector<int> input {1, 2, 3};
  bp.AddStage(new Stage1());
  bp.AddStage(new Stage2());
  bp.AddStage(new Stage1());
  bp.Execute(input);
  for_each(input.begin(), input.end(), [](int ele){ cout << ele << "\t";});
  cout << "\n";
}

void RunBasicFunctionalPipeline() {
  const pipe_closure<add_one_f> add_one;
  const pipe_closure<mult_f> mult_by_n(3);
  int number_3 = 1 | add_one | add_one | add_one | mult_by_n;
  cout << number_3 << endl;
}

void RunAdvFunctionalPipeline() {
  vector<int> input {1, 2, 3};
  // const pipe_closure<add_one_f> add_one;
  const pipe_closure<normalize_f> normalize_input;
  auto output = input | normalize_input | ;
  for_each(begin(output), end(output), [](int ele){cout << ele << "\t";});
}
