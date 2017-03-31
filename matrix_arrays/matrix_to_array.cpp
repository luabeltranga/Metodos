#include <iostream>
#include <array>

int main (void){
  const int N = 15;
  const int rows = 3;
  const int columns = 5;
  std::array<double,N> x;
  double M[rows][columns] = {0};

  for(int n = 0;n<3;n++){
    for (int m = 0;m<5;m++){
      M[n][m]=n/(m+1.0);
    }

  }


  for(int n = 0;n<3;n++){
    for (int m = 0;m<5;m++){
      x[columns*n+m]=M[n][m];
    }

  }


  
  std::cout<<M[1][3]<<std::endl;
  std::cout<<x[8]<<std::endl;
  
  return 0;
}
