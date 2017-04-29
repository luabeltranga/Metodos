#include <iostream>
#include <cmath>
#include <functional>


double simpson(const double &a,const double &b,const int &n,std::function<double(double)> f);
double richardson(const double &a,const double &b,const int &n,std::function<double(double)> f);
double func1 (double x);

int main(void){
  double a = 10e-19;
  double b = 1.0;
  double exact = (1 + 2*std::exp(-5*M_PI/4))/5;
  int n = 20000000;
  std::cout << "Integral por simpson con n=" <<n<< ": " << simpson(a , b , n ,func1) << std::endl;
  std::cout << "Integral por simpson_richardson con n=" <<n<< ": " << richardson(a , b , n ,func1) << std::endl;
  std::cout << "Integral exacta: " << exact << std::endl;
  
  return 0;
}


double simpson(const double &a,const double &b,const int &n,std::function<double(double)> f){
  int n_test = n;
  if (n_test%2 !=0){
    n_test += 1;
  }
  const double h = (b-a)/n_test;
  double sum1 = 0;
  double sum2 = 0;

  for (int ii = 1; ii <= n_test/2 -1 ; ii++){
    sum1 += f(a+ 2*ii*h);
  }
  for (int ii = 1; ii<= n_test/2  ; ii++){
    sum2 += f(a+ 2*(ii-1)*h);
  }
  
  return h*(f(a)+2*sum1+4*sum2+f(b))/3.0; 
}

double richardson(const double &a,const double &b,const int &n,std::function<double(double)> f){
  return (16*simpson(a,b,2*n,f)-simpson(a,b,n,f))/15.0;
}

double func1 (double x){
 // return std::cos(2*x)/std::exp(x);
  return std::log(x)/std::sqrt(x);
}
