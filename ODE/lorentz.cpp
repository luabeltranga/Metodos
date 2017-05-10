#include <iostream>
#include <vector>
#include <fstream>

const double DELTA = 10;
const double RHO = 28;
const double BETA = 8.0/3.0;


void euler (std::vector<double> &xyz, double h, double t);
double f1 (double x,double y, double z);
double f2 (double x,double y, double z);
double f3 (double x,double y, double z);

int main(void){
  std::vector<double> xyz {1.0,1.0,1.0};
  std::ofstream lorentz;
  const double h = 0.01;
  const int  N = 10000;

  double t = 0.0;

  lorentz.open("Lorentz.dat");
  
  for(int step = 0; step < N ; step++){
    t += h;
    lorentz << t << "  " << xyz[0] << " " << xyz[1] << " " << xyz[2] << "\n"; 
    euler(xyz,h,t);
  }

  lorentz.close();
  
  return 0;
}
double f1 (double x,double y, double z){
  return DELTA*(y-x);
}
double f2 (double x,double y, double z){
  return x*(RHO-z)-y;
}
double f3 (double x,double y, double z){
  return x*y-BETA*z;
}

void euler (std::vector<double> &xyz, double h, double t){
  std::vector<double> xyz_tmp = xyz ;
  xyz[0] = xyz_tmp[0] + h*f1(xyz_tmp[0],xyz_tmp[1],xyz_tmp[2]);
  xyz[1] = xyz_tmp[1] + h*f2(xyz_tmp[0],xyz_tmp[1],xyz_tmp[2]);
  xyz[2] = xyz_tmp[2] + h*f3(xyz_tmp[0],xyz_tmp[1],xyz_tmp[2]);  
  
  
}


