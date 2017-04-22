#include <iostream>
#include <random>
struct complex{
  double re = 0;
  double im = 0;
  
};
complex sum (const complex &a,const complex &b);
void print (const complex &c);
int main(void){
  std::mt19937 g(2); 
  std::uniform_real_distribution<double> h(0,10);
  complex a ,b , c ;
  a.re = h(g);
  a.im = h(g);

  b.re = h(g);
  b.im = h(g);

  c = sum(a , b);
  print (c);
  return 0;
}

void print (const complex &c){
  std::cout << c.re << "  " << c.im << std::endl;
}

complex sum (const complex &a,const complex &b){
  complex c;
  c.re=a.re+b.re;
  c.im=a.im+b.im;
  return c;
}
