// example about structures
#include <iostream>
#include <string>
#include <sstream>

struct movies_t {
  std::string title;
  int year;
} mine, yours;

void printmovie (movies_t movie);

int main ()
{
  std::string mystr;

  mine.title = "2001 A Space Odyssey";
  mine.year = 1968;

  std::cout << "Enter title: ";
  getline (std::cin,yours.title);
  std::cout << "Enter year: ";
  getline (std::cin,mystr);
  std::stringstream(mystr) >> yours.year;

  std::cout << "My favorite movie is:\n ";
  printmovie (mine);
  std::cout << "And yours is:\n ";
  printmovie (yours);
  return 0;
}

void printmovie (movies_t movie)
{
  std::cout << movie.title;
  std::cout << " (" << movie.year << ")\n";
}
