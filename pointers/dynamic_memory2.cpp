#include <iostream>
#include <random>
#include <vector>

int main(void){

  int size = 0;

  std::mt19937 g1 (135);
  std::uniform_int_distribution<int> h(0,10);
  std::cout<<"Introduzca el tamaño de arreglo: ";
  std::cin>>size;
  std::vector<int> test (size);
  
  for (int ii = 0;ii<size; ii++){
    test[ii]=h(g1);
  }

  for (int ii = 0;ii<size; ii++){
    std::cout<<test[ii]<<" ";
  }
  std::cout<<std::endl;
  return 0;
}
