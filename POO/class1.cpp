#include <iostream>
#include <cmath>

class Vector2D{
  double x = 0, y = 0 ;
public:
  Vector2D(double x0, double y0);
  ~Vector2D();
  void print(void);
  double norm(void);
  Vector2D operator+(const Vector2D & b);
  Vector2D operator-(const Vector2D & b);
  double operator*(const Vector2D & b);
};

Vector2D::Vector2D(double x0, double y0){
  //std::cout << "Me construyeron"<<std::endl;
  x = x0;
  y = y0;
}

Vector2D::~Vector2D(){
  //std::cout << "Me destruyeron"<<std::endl;
}

Vector2D Vector2D::operator+(const Vector2D & b){
  Vector2D tmp(0,0);
  tmp.x = x + b.x;
  tmp.y = y + b.y;
  return tmp;
}

Vector2D Vector2D::operator-(const Vector2D & b){
  Vector2D tmp(0,0);
  tmp.x = x - b.x;
  tmp.y = y - b.y;
  return tmp;
}

double Vector2D::operator*(const Vector2D & b){
  return x*b.x + y*b.y;
}

void Vector2D::print(void){
  std::cout << x << "\t" << y <<std::endl;
}

double Vector2D::norm(void){
  return std::sqrt(x*x+y*y);
}

int main (void){
  Vector2D a(1,0);
  Vector2D b(0,1);
  Vector2D c(0,0);
  a.print();
  c = a + b;
  c.print();
  c = a - b;
  c.print();
  std::cout << a*b << std::endl;
}
