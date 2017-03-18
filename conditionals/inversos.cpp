#include <iostream>

int main(void){

  const int min = 1;
  int max=1  ;
  double suma = 0 ;
  int i=1 ;
  while(max<1000){
    
  while(i<=max){
    
    suma+=1.0/i;
    i++;
    std::cout<<max<<"\t"<<suma<<std::endl;
    
  }
  
  max++;
  }




  return 0;
}
