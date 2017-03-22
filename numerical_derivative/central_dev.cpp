#include<iostream>
#include<cmath>
#include<fstream>

double f(double x);
double forward_dev(double x, double h);
double dev_exact(double x);
double central_dev(double x, double h);
double richardson_dev(double x, double h);
void data(void);

int main(void){ 
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
  return (f(x+h)-f(x))/h;
}

double central_dev(double x, double h){
  return (f(x+h/2)-f(x-h/2))/h;
}

double richardson_dev(double x, double h){
  double f1, f2;
  f1=central_dev(x,h);
  f2=central_dev(x,h/2);
  return (4*f2-f1)/3.0;
}

void data(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  std::ofstream fout;
  fout.precision(16), fout.setf(std::ios::scientific);
  double x = 3.7;
  double h = 1.0;
  double df = 0 ;
  double dc = 0 ;
  double dr = 0 ;
 fout.open("cd.dat");
  for(int ii=0;ii<=7;ii++){
    dc=std::fabs((central_dev(x,h)-dev_exact(x))/dev_exact(x));
    df=std::fabs((forward_dev(x,h)-dev_exact(x))/dev_exact(x));
    dr=std::fabs((richardson_dev(x,h)-dev_exact(x))/dev_exact(x));
    fout<<h<<" "<<df<<" "<<dc<<"\n";
    h/=10;
  }
  fout.close();
}
