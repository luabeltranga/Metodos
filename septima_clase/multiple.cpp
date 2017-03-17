#include<iostream>

void odd(int x);
void even(int x);

int main (void){

  int i = 5;
  odd(i);

  return 0;
}



void odd(int x){
  if ((x%2)!=0){
    std::cout<<"it is odd. \n";
  }
  else{
    even(x);
  }

}


void even(int x){
  if ((x%2)!=0){
    std::cout<<"it is even. \n";
  }
  else{
    odd(x);
  }

}
/* se puede implementar esto mismo de otra manera */
