#ifndef FUCTIONAL_H
#define FUCTIONAL_H

#include <numeric>

struct add_one_f {
public:
  // template<class T>
  // T operator() (T x) const
  // {
  //   return x+1;
  // }
  int operator() (int x) const
  {
    return x+1;
  }
  vector<int> operator() (vector<int>& x) const
  {
    for_each(begin(x), end(x), [](int& ele){ele+=1;});
    return x;
  }
};

struct normalize_f {
public:
  vector<int> operator() (vector<int>& x) const
  {
    int sum = std::accumulate(x.begin(), x.end(), 0.0);
    double mean = sum / x.size();
    for_each(begin(x), end(x), [mean](int &ele){ele -= int(mean);});
    return x;
  }
};

struct mult_f {
public:

  mult_f(int n) : n(n) 
  { }
  template<class T>
  T operator() (T x) const
  {
    return x*n;
  }
private:
  int n;
};

template<class T>
class pipe_closure: public T
{
public:
  template<class... Xs>
  pipe_closure(Xs&&... xs) : T(std::forward<Xs>(xs)...)
  {}
};

template<typename L, typename F>
auto operator| (L&& x, const pipe_closure<F> p) {
  return p(x);
}


#endif