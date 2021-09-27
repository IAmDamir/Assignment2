//
// Created by Damir on 9/27/2021.

#include "Person.h"

Person::~Person() = default;

Person::Person(string name, int age, int luck) : Person() {
  this->name = std::move(name);
  this->age = age;
  this-> luck = luck;
}

Person::Person() = default;

void Person::changeLuck(Person &person1, Person &person2) {
  int temp = person1.getLuck();
  person1.setLuck(person2.getLuck());
  person2.setLuck(temp);
}

const string &Person::getName() const {
  return name;
}
void Person::setName(const string &name) {
  this->name = name;
}

int Person::getAge() const {
  return age;
}
void Person::setAge(int age) {
  this->age = age;
}

int Person::getLuck() const {
  return luck;
}
void Person::setLuck(int luck) {
  this->luck = luck;
}
