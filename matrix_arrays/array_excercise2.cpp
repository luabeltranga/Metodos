#include <iostream>

void statistics(const double data[],int size);

int main(void){
  const int N=2;
  double array[N]={0.0,1.0};
  statistics(array,N);
  return 0;
}

void statistics(const double data[],int size){
  double sum=0 ;
  for (int ii = 0; ii<size;ii++){
    sum+=data[ii];
  }
  std::cout<<"El promedio es: "<<sum/size<<std::endl;
}
  
