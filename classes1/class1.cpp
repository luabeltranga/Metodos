// classes example
#include <iostream>


class Rectangle {
    double width, height;
  public:
    void set_values (double,double);
    double area() {return width*height;}
};

void Rectangle::set_values (double x, double y) {
  width = x;
  height = y;
}

int main () {
  Rectangle rect;
  rect.set_values (3.1,4);
  std:: cout << "area: " << rect.area()<<"\n";
  return 0;
}
