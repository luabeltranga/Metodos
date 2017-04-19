#include <iostream>
#include <cmath>

const int N = 100; // tamaño del arreglo

double prod_punto(const int A[], const int B[]);
double my_norm(const int A[]);
double angulo = 0;
int main(void){
  int A[N] = {0}; //declaracion de arreglos
  int B[N] = {0};

  //se llenan los arreglos
  for (int ii = 0;ii < N ; ii++ ){
    if(ii%2==0){
      A[ii]=1;
      B[ii]=2;
    }
    else{
      A[ii]=2;
      B[ii]=1;
    }
  }
  //calculo del angulo con la funcion acos
  angulo=std::acos(prod_punto(A,B)/my_norm(A)/my_norm(B));
  
  std::cout<<"El angulo entre estos vectores en radianes es: "<<angulo<<std::endl;
  
  return 0;
}

//calculo del producto punto
double prod_punto(const int A[],const int B[]){
  double punto = 0;
  for (int jj = 0; jj < N ;jj++){
    punto+=A[jj]*B[jj];
   
  }
  return punto;
  
}

//calculo de la norma
double my_norm(const int A[]){
  double norma= 0;
  for(int kk =0 ; kk < N ; kk++){
    norma+=A[kk]*A[kk];
  }
  return std::sqrt(norma);
}
