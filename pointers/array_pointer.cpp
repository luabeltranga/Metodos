#include <iostream>
#include <typeinfo>

int main (void){
  int numbers[9]={0,3};
  int a=0;
  std::cout<<&numbers[0]<<std::endl;
  std::cout<<numbers<<std::endl; // puntero con la direccion de memoria del 

  a=*(numbers+1);

  std::cout<<&numbers[1]<<std::endl;  // primer elemento de numbers
  std::cout<<a<<std::endl;
  std::cout<<typeid(numbers).name()<<std::endl;
  std::cout<<typeid(a).name()<<std::endl;
  
  
  return 0;
}
