#include <iostream>
#include <cmath>
#include <functional>
double f(double x);
double trapezoid(std::function<double(double)> f ,const double & a ,const double &b,int & n);

int main(void){
  std::cout.precision(16);

    int n = 3000000;
  std::cout<< trapezoid(f,0,1.0, n) <<std::endl;
  
  return 0;
}
double f(double x){
  return 4*std::pow(1+pow(x,2),-1);
  /*if (x == 0){
    return 0; 
    }
  else {
    return std::sin(x)/x;
  }
  */
}
double trapezoid(std::function<double(double)> f ,const double & a ,const double &b,int & n){

  double *f_i = new double [n];
  double suma = 0;
  double h = (b-a)/n;
  for(int ii = 0; ii<n ; ii++ ){
    f_i[ii]=f(a+h*ii);
  }
  
  for(int jj = 1 ;  jj < n-1 ; jj++){
    suma += f_i[jj];
  }

  suma += 0.5*(f_i[0]+f_i[n-1]);
  

  delete [] f_i;
  f_i=nullptr;
  delete f_i;
  return h*suma;
}
