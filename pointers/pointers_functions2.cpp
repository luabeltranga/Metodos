#include <iostream>
#include <cmath>
#include <functional>
double central_dev(std::function<double(double)> f, double x, double h);
double my_sin(double x);
int main (void){
  double x= M_PI/4;
  double h=0.01;
  
  std::cout<<central_dev(my_sin,x,h)<<std::endl;

  return 0;
}

double central_dev(std::function<double(double)> f, double x, double h){
  return (f(x+h/2)-f(x-h/2))/h;
}

double my_sin(double x){
  return std::sin(x);
}
