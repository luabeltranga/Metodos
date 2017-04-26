#include <iostream>
#include <vector>
#include <cmath>

double trapezoid_irregular(const std::vector<double> &x ,const std::vector<double> &fx);

int main (void){
  double a = 0;
  double b = M_PI;
  const int N = 2000;
  double h = (b-a)/N;
  
  std::vector<double> x (N);
  std::vector<double> fx (N);

  for (int jj = 0 ; jj<N ; jj++){
    x[jj] = a + jj*h;
    fx[jj] = std::sin(a + jj*h);
  }
  

  std::cout<<trapezoid_irregular(x,fx)<<std::endl;

  return 0;
}
double trapezoid_irregular(const std::vector<double> &x ,const std::vector<double> &fx){
  double trap = 0.0;
  const int N = x.size();

  for (int ii = 0; ii < N-1 ;ii++){
    
    trap += (x[ii+1]-x[ii])*(fx[ii+1]+fx[ii]);
    
  }


  return 0.5*trap;
}
