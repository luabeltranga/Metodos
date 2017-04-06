#include <iostream>
#include <cmath>
double central_dev(double (*f)(double), double x, double h);

int main (void){
  double x= M_PI/4;
  double h=0.01;
  
  std::cout<<central_dev(std::cos,x,h)<<std::endl;

  return 0;
}


double central_dev(double (*f)(double), double x, double h){
  return (f(x+h/2)-f(x-h/2))/h;
}
