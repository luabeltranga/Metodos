#include <iostream>
#include <array>

int main (void){
  const int N = 15;
  const int rows = 3;
  const int columns = 5;

  std::array<double,N> x;

  double M[rows][columns] = {0};

  for (int m = 0;m<15;m++){
    x[m]=m;
  }
  
  
  
  for(int n = 0;n<3;n++){
    for (int m = 0;m<5;m++){
      M[n][m]=x[columns*n+m];
    }
    
  }
   for (int m = 0;m<15;m++){
      std::cout<<x[m]<<std::endl;
  } 
      std::cout<<" "<<std::endl;
 
   for(int n = 0;n<3;n++){
    for (int m = 0;m<5;m++){
      std::cout<<M[n][m]<<std::endl;
    }
    
  }

  return 0;
}
