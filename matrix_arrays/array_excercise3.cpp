#include <iostream>
#include <array>

void statistics(const std::array<double,N> data[],int size);

int main(void){
  const int N=2;
  std::array<double,N>array={0.0,1.0};
  statistics(array,N);
  return 0;
}

void statistics(const std::array<double,N> data,int size){
  double sum=0 ;
  for (int ii = 0; ii<size;ii++){
    sum+=data[ii];
  }
  std::cout<<"El promedio es: "<<sum/size<<std::endl;
}
  
