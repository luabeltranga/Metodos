#include <iostream>
#include <cmath>
#include <functional>
#include <array>
const int N = 100;
void integral(std::function<double(double)> f, double &low,double &up);
double my_fun(double x);

int main (void){
  double up = 2*M_PI; // limite superior de integracion
  double low = 0; // limite inferior de  integracion, que se sobreescribe con
                  // con la integral 
  
  integral(my_fun,low,up); // llamado de la funcion integral

  std::cout<<low<<std::endl; // impresion de la respuesta

  return 0;
}

void integral(std::function<double(double)> f, double &low, double &up){
  std::array<double,N> x; //arreglo para guardar las particiones del intervalo
  std::array<double,N> F; //arreglo para guardar los valor de f
  up = (up-low)/(N-1);
  low = 0;

  //llenado de los arreglos
  for(int ii = 0;ii<N;ii++){  
    F[ii]=f(up*ii);
    x[ii]=up*ii;
  }
  //calculo de la integral
  for(int ii = 0;ii<N-1;ii++){
    low+=F[ii+1]*(x[ii+1]-x[ii]);
  }


}

//funcion a integrar
double my_fun(double x){
  // return std::sin(x);
  return 1;
}
