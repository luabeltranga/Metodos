#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

const double OMEGA = 1.0;
const double GAMMA = 4.0;
double f(double x ,double v, double t );
void  euler(std::vector<double> &x, double t , double h);

int main (void){
  //vector que almacena las condiciones iniciales, primero posicion
  //luego velocidad
  std::vector<double> xv {10.0 , 0.0};
  std::ofstream datos;
  const double h = 0.001;
  const int N = 10.0/h;
  
  double t = 0;
  datos.open("Oscilador_amortiguado.dat");
  //imprime tiempo, posicion, velocidad
  for(int step = 0; step < N; ++step){
    t = 0.0 + step*h;
    datos << step*h << "   " << xv[0] << "  " << xv[1] << "\n";
    euler(xv,t,h);
  }

  datos.close();
  return  0;
}

double f(double x ,double v, double t ){
  return -OMEGA*OMEGA*x-GAMMA*v;
}

void  euler(std::vector<double> &x, double t , double h){
  std::vector<double> x_tmp = x;  
  
  x[1] = x_tmp[1] + h*f(x_tmp[0],x_tmp[1],t);
  x[0] = x_tmp[0] + h*x_tmp[1];
  
}
