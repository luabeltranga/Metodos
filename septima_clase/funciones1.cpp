#include <iostream>

double seno (double x);

int main(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);

  double x = 0.1;
  std::cout<<seno(x)<<std::endl;
  std::cout<<"&x en main: "<<&x<<std::endl;
  return 0;
}


double seno (double x){
  std::cout<<"&x en seno: "<<&x<<std::endl;
  return x-x*x*x/6.0;
}
