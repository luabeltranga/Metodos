#include<iostream>
#include<cstdio>
#include<cmath>
double newton(double x0, double eps, int n);
double g(double x);
double f(double x);

int main(void){
  
  newton(0,1.0e-16,5);
  return 0;
}

double g(double x){
  return -std::exp(-x)-1;
}

double f(double x){
  return std::exp(-x)-x;
}

double newton(double x0, double eps, int n){
  double xi=x0;
  double xo=1;
  double delta =0;
  for (int jj=0;jj<=n;jj++){
    xo=xi;
    xi=xi-(f(xi))/(g(xi));
    if (std::fabs(f(xi))<eps){
      break;
    }
    else{
    }
    delta = std::fabs(1-xo/xi);
    std::printf("%d %24.16e %24.16e %24.16e \n",jj,xi,f(xi), delta); 
  }

  
}



