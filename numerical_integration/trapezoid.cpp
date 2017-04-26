#include <iostream>
#include <cmath>
#include <functional>

double f(double x);
double trapezoid(std::function<double(double)> f ,const double & a ,const double &b,const int & n);
double richardson(std::function<double(double)> f,const double & a ,const double &b,const int & n);

int main(void){
  std::cout.precision(16);
  
  int n = 20;
  std::cout<< trapezoid(f,0,M_PI,n) <<std::endl;
  std::cout<< richardson(f,0,M_PI,n) <<std::endl;
  
  return 0;
}
double f(double x){
  return std::sin(x);
  //return 4*std::pow(1+pow(x,2),-1);
  /*if (x == 0){
    return 0; 
    }
    else {
    return std::sin(x)/x;
    }
  */
}
double trapezoid(std::function<double(double)> f ,const double & a ,const double &b,const int & n){
  
  double suma = 0;
  double h = (b-a)/n;  
  for(int jj = 1 ;  jj < n-1 ; ++jj){
    suma += f(a+jj*h);
  }

  suma += 0.5*(f(a)+f(b));
  
  return h*suma;
}

double richardson(std::function<double(double)> f,const double & a ,const double &b,const int & n){
  return (4*trapezoid(f,a,b,2*n)-trapezoid(f,a,b,n))/3;  
}
