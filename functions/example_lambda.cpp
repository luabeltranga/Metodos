#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

int main(void){
  std::vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto evens = std::count_if(begin(c), end(c), [](int num){
      return (num % 2) == 0;
    });
  std::cout <<evens <<std::endl;


  int x = 5;
  c.erase(std::remove_if(c.begin(),c.end(), [x](int n) { return n < x; }), c.end());

  std::cout<<"c: ";
  std::for_each(c.begin(), c.end(), [](int i){std::cout<< i << ' ';});
  std::cout<<'\n';
  return 0;
}
