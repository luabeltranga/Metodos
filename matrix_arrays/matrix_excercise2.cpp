#include <iostream>

template <int R,int C>

void transpose(int (&matrix)[R][C],int (&matrixT)[R][C]){
  //calculate the transpose
  for (int ii = 0; ii< R ; ii++ ){
    for (int jj = 0; jj< C ; jj++ ){
      matrixT[ii][jj] = matrix[jj][ii];
    }
  }
}



int main(void){
  //declaration
  const int N = 4;
  int A[N][N] = {{0}};
  int AT[N][N] = {{0}};
  
  //fill the matrix
  for (int ii = 0; ii< N ; ii++ ){
    for (int jj = 0; jj< N ; jj++ ){
      A[ii][jj] = ii*N+jj;
    }
  }
  
  for(int x=0;x<N;x++){
    for(int y=0;y<N;y++){
      std:: cout<<A[x][y]<<" ";  
    }
    std::cout<<std::endl; 
  }

  transpose(A,AT);
  
  //print

  for(int x=0;x<N;x++){
    for(int y=0;y<N;y++){
      std:: cout<<AT[x][y]<<" ";  
    }
    std::cout<<std::endl; 
  }
  return 0;
}


