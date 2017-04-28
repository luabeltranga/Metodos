#include <iostream>
#include <cmath>
#include <functional>
#include <vector>


double trapezoid(std::function<double(double)> f ,const double &a,const  double &b, const int &n);
double richardson(std::function<double(double)> f ,const double &a,const  double &b, const int &n);

double fun1(const double &x);
double fun2(const double &x);
double fun3(const double &x);
double fun4(const double &x);

int main(void){
  double a = 0.0;
  double b = M_PI;
  int n = 4;
  std::cout << trapezoid(fun4,a,b,n) << std::endl;
  std::cout << richardson(fun4,a,b,n) << std::endl;

  return 0;
}



double trapezoid(std::function<double(double)> f ,const double &a,const double &b,const int &n){
  double h = (b-a)/n;
  double sum = 0.0;

  for (int ii = 1 ; ii < n ; ii++ ){

    sum += f(a+ii*h);
    
  }
  sum += 0.5*(f(a)+f(b));
  return sum*h;
}

double richardson(std::function<double(double)> f ,const double &a,const  double &b, const int &n){
  return (4*trapezoid(f,a,b,2*n)-trapezoid(f,a,b,n))/3;
}

// a = 0, b= 10000  y n= 20000
double fun1(const double &x){
  return std::exp(-1*x)*std::sqrt(1-std::sin(x));
}

// a=0 ,b=1 y n= 40 
double fun2(const double &x){
  if(x==0){
    return 0;
  }
  return std::sin(x)/std::sqrt(x);
}

//a=1, b=2 y n=200
double fun3(const double &x){
  return std::pow(x,-1);
}

//a=0, b= pi y n = 4
double fun4(const double &x){
  return std::cos(std::sin(x))/M_PI;
}
