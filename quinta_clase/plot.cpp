#include <iostream>
#include <cmath>
#include <cstdio>


int main(void){

  for(double x=-100 ; x<=100 ; x+=0.01){
    
    std::printf("%.16e %20.16e\n",x,x*std::sin(x) );


  }





  return 0;
}
