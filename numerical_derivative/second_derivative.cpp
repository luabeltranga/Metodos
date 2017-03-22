#include<iostream>
#include<cmath>
#include<fstream>

double f(double x);
double forward_dev(double x, double h);
double dev_exact(double x);
double central_dev(double x, double h);
double central_dev2(double x, double h);
double richardson_dev(double x, double h);
double richardson_dev2(double x, double h);
void data_h(void);
void data_x(void);

int main(void){ 

  data_x();

  return 0;
}


double dev_exact(double x){
  return std::cos(x);
}

double f(double x){
  return std::sin(x);
}

double forward_dev(double x, double h){
  return (f(x+h)-f(x))/h;
}

double central_dev(double x, double h){
  return (f(x+h/2)-f(x-h/2))/h;
}

double central_dev2(double x, double h){
  return (central_dev(x+h/2,1.0e-4)-central_dev(x-h/2,1.0e-4))/h;
}

double richardson_dev(double x, double h){
  double f1, f2;
  f1=central_dev(x,h);
  f2=central_dev(x,h/2);
  return (4*f2-f1)/3.0;
}


double richardson_dev2(double x, double h){
  double f1, f2;
  f1=central_dev2(x,h);
  f2=central_dev2(x,h/2);
  return (4*f2-f1)/3.0;
}
void data_h(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  std::ofstream fout;
  fout.precision(16), fout.setf(std::ios::scientific);
  double x = 3.7;
  double h = 1;
  double df = 0 ;
  double dc = 0 ;
  double dr = 0 ;
 fout.open("rcd_h.dat");
  for(int ii=0;ii<=7;ii++){
    dc=std::fabs((central_dev(x,h)-dev_exact(x))/dev_exact(x));
    df=std::fabs((forward_dev(x,h)-dev_exact(x))/dev_exact(x));
    dr=std::fabs((richardson_dev(x,h)-dev_exact(x))/dev_exact(x));
    fout<<h<<" "<<df<<" "<<dc<<" "<<dr<<"\n";
    h/=10;
  }
  fout.close();
}


void data_x(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  std::ofstream fout;
  fout.precision(16), fout.setf(std::ios::scientific);
  double x = 0;
  double h = 1.0e-4;
  double df = 0 ;
  double dc2 = 0 ;
  double dr = 0 ;
 fout.open("rcd_x.dat");
  for(int ii=0;ii<=300;ii++){
    dc2=central_dev2(x,h);
    df=forward_dev(x,h);
    dr=std::fabs((richardson_dev2(x,h)+std::sin(x))/std::sin(x))*100.0;
    fout<<x<<" "<<f(x)<<" "<<dr<<"\n";
    x+=1.0e-2;
  }
  fout.close();
}
