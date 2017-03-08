#include <iostream>
#include <cmath>
#include <cstdio>


double f (double x);
double bisection(double a, double b, int N_MAX, double eps);
double regulafalsi(double a, double b, int N_MAX, double eps);
double fixedpoint(double x0,int N_MAX, double eps);
int main (void){
  // bisection(14,15,30,1.0e-7);
  //regulafalsi(0,1,30,1.0e-7);
  fixedpoint(0.5,300,1.0e-19);
  return 0;
}


double f (double x){
  //return (9.81*68.1/x)*(1-std::exp(-x*10/68.1))-40;
  return x-std::exp(-x);
}


double bisection(double a, double b, int N_MAX, double eps){
  double r, rold=a, delta;
  for(int ii = 1; ii<=N_MAX; ii++){
      r=0.5*(a+b);
      delta=std::fabs(1-r/rold);
    if(std::fabs(f(r))<eps){
      break;
    }
    else if(f(a)*f(r)>0){
      a=r;
    }
    else{
      b=r;
    }
    rold=r;
    std::printf("%d %20.16e %20.16e %20.16e %20.16e %20.16e \n",ii,a,b,r,f(r),delta);
    }
  
}


double regulafalsi(double a, double b, int N_MAX, double eps){
  double r, rold=a, delta;
  for(int ii = 1; ii<=N_MAX; ii++){
    r=b-(f(b)*(a-b))/(f(a)-f(b));
      delta=std::fabs(1-r/rold);
    if(std::fabs(f(r))<eps){
      break;
    }
    else if(f(a)*f(r)>0){
      a=r;
    }
    else{
      b=r;
    }
    rold=r;
    std::printf("%d %20.16e %20.16e %20.16e %20.16e %20.16e \n",ii,a,b,r,f(r),delta);
    }
  
}


double fixedpoint(double x0,int N_MAX, double eps){
  double xi=x0;
  for (int jj=1;jj<=N_MAX;jj++){
    if( std::fabs(xi-std::exp(-xi))<eps){
      break;
    }
    else{
      xi=std::exp(-xi);
    }
    std::printf("%d  %20.16e %20.16e \n",jj,xi,xi-std::exp(-xi));
    }
  }
