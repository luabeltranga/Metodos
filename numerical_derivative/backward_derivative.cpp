#include<iostream>
#include<cmath>
#include<fstream>

double f(double x);
double forward_dev(double x, double h);
double dev_exact(double x);
void data(void);

int main(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  
  
 
  data();
  return 0;
}


double dev_exact(double x){
  return 2*cos(2*x);
}

double f(double x){
  return std::sin(2*x);
}

double forward_dev(double x, double h){
  return (f(x)-f(x-h))/h;
}

void data(void){
  std::ofstream fout;
  fout.precision(16), fout.setf(std::ios::scientific);
  double x = 3.7;
  double h = 1.0;
  double a = 0 ;
 fout.open("back.dat");
  for(int ii=0;ii<=7;ii++){
    
    a=std::fabs((forward_dev(x,h)-dev_exact(x))/dev_exact(x));
    fout<<h<<" "<<a<<"\n";
    h/=10;
  }
  fout.close();
}
