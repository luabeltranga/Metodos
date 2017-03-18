#include <iostream>
int main(void){
  auto flambda = [](auto a, auto b){return a<b;};
  bool flag = flambda(3,3.14);
  std::cout<<flag<<std::endl;
  flag = flambda(3.14,3);
  std::cout<<flag<<std::endl;
  std::cout<<flambda(-5,20)<<std::endl;
  return 0;
}
