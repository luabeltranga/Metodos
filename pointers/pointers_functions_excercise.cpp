#include <iostream>
#include <cmath>
#include <functional>
#include <array>

double integral(std::function<double(double)> f, int n);


double my_sin(double x);

int main (void){
  
  std::cout<<integral(my_sin,5)<<std::endl;

  return 0;
}

double integral(std::function<double(double)> f,int n){
  std::array<double,10> x;
  std::array<double,10> F;
  
  double inta = 0;
  
  

  for(int ii = 0;ii<n;ii++){
    F[ii]=f(ii);
    x[ii]=2*M_PI/ii;
  }

  return 3;
}

double my_sin(double x){
  // return std::sin(x);
  return 1;
}
