#include <iostream>

double seno (const double &x);

int main(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);


  double x = 0.1;
  std::cout<<"&x en main: "<<&x<<std::endl;
  std::cout<<seno(x)<<std::endl;
  std::cout<<"valor de x: "<<x<<std::endl;
  return 0;
}


double seno (const double &x){
  std::cout<<"&x en seno: "<<&x<<std::endl;
  return x-x*x*x/6.0;
   x = 2*x;
  
}


/* al pasar por referencia '&' si se modifica el valor de la variable
   esto cambia globalmente el valor de la variable, para evitar esto se debe agragar const*/
