#include <iostream>
long unsigned int fac1(const int &n);
long unsigned int fac2(const int &n);
void tabla (int n);

int main (void){
  //std::cout <<fac1(40)<<std::endl;
  //std::cout <<fac2(40)<<std::endl;
  tabla(65);
  
  return 0;
}

void tabla(int n){
  for (int jj=1;jj<=n;jj++){
    std::cout<<jj<<" "<<fac1(jj)<<" "<<fac2(jj)<<"\n";
    
  }

}


long unsigned int fac1(const int &n){
  if(n>1){
    return n*fac1(n-1);
  }
  else{
    return 1;
  }
}


long unsigned int fac2(const int &n){
  long unsigned int fac=1;
  for(int ii=1;ii<=n;ii++){
    fac*=ii;
  }
  return fac;
}
