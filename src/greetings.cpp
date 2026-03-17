#include "../include/greetings.hpp"
#include "../include/TestClass.hpp"
#include <iostream>

using namespace std;

void greetings() {
  TestClass test("Jan", 20);
  test.display();

  cout << "Witaj" << endl;
}
