#ifndef TEST_CLASS_HPP
#define TEST_CLASS_HPP

#include <string>

class TestClass {
private:
  std::string name;
  int age;

public:
  TestClass(const std::string &name, int age);
  ~TestClass();

  void setAge(int age);
  void setName(const std::string &name);

  int getAge() const;
  std::string getName() const;

  void display() const;
};

#endif // !TEST_CLASS_HPP
