#include <iostream>
#include <cmath>
#include <functional>


double integral(std::function<double(double)> f, double x, double h);

double my_sin(double x);

int main (void){
  double x= M_PI/4;
  double h=0.01;
  
  std::cout<<integral(my_sin,x,h)<<std::endl;

  return 0;
}

double integral(std::function<double(double)> f, double x, double h){
  double inta = 0;
  double hh = 1.0;
  for(int ii = 0;ii<2*M_PI;ii+=1.0){
    inta+=(f(ii+1.0))/(hh);
  }

  return inta;
}

double my_sin(double x){
  // return std::sin(x);
  return 1;
}
