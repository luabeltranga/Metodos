#include <iostream>
#include "even_odd.h"
void odd(int x){
  if ((x%2)!=0){
    std::cout<<"it is odd. \n";
  }
  else{
    even(x);
  }

}


void even(int x){
  if ((x%2)==0){
    std::cout<<"it is even. \n";
  }
  else{
    odd(x);
  }

}
