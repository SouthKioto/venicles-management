#include "../include/TestClass.hpp"
#include <iostream>
#include <string>

TestClass::TestClass(const std::string &name, int age) : name(name), age(age) {}

TestClass::~TestClass() {}

void TestClass::setAge(int age) { this->age = age; }

void TestClass::setName(const std::string &name) { this->name = name; }

int TestClass::getAge() const { return age; }

std::string TestClass::getName() const { return name; }

void TestClass::display() const {
  std::cout << "Imie: " << name << ", Wiek: " << age << std::endl;
}
