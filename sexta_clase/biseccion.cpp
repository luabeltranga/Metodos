#include <iostream>
#include <cmath>
#include <cstdio>


double f (double x);
const int N_MAX = 30;
const double eps = 1.0e-9;

int main (void){
  double xl=14;
  double xu=15;
  double xr=0;
  double xm=1;
  double err = 0;
  for(int ii = 0; ii<=N_MAX; ii++){
    xr=0.5*(xu+xl);
    if(std::fabs(f(xr))<eps){
      break;
    }
    else if(f(xu)*f(xr)>0){
      xu=xr;
    }
    else{
      xl=xr;
    }
    err = std::fabs(1-xm/xr)*100;
    xm=xr;
    
    std::printf("%d %20.16e %20.16e %20.16e %20.16e \n",ii,xl,xu,xr,err);
      }
  

}


double f (double x){
  return (9.81*68.1/x)*(1-std::exp(-x*10/68.1))-40;
}
