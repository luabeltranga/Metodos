#include<iostream>
#include<cmath>


int main(void){

  int n,ii;
  bool isprime = true;
  std::cin>>n;

  for(ii=2;ii<=std::sqrt(n);ii++){
    if (n%ii == 0){
      isprime = false; 
    }
  }
  
  if (isprime == true){
    std::cout<<"Si es primo"<<std::endl;
  }
  else{
    std::cout<<"No es primo"<<std::endl;
  }
  return 0;
}
