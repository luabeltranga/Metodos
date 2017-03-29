#include <iostream>
#include <array>
#include <cmath>

int main (void){

  const int N=10;

  std::array<double, N> x;

  for (auto &z:x){
    z=4;
  }

  // compute the mean
  double sum=0, mean = 0;
  for(auto z: x){
    sum+=z ;
  }
  mean = sum/N;
  std::cout<< mean <<std::endl;

  // compute sigma
  double sum2=0, sigma = 0;
  for(auto z: x){
    sum2+=(z-mean)*(z-mean);
  }
  sigma = std::sqrt(sum2/(N-1));
  std::cout<< sigma <<std::endl;
  
  
  
  return 0;
}
