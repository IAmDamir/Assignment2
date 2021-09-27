//
// Created by Damir on 9/27/2021.
//
#include <string>
#include <utility>

#pragma once
#ifndef ASSIGNMENT2_PERSON_H
#define ASSIGNMENT2_PERSON_H

using namespace std;

class Person {
public:
  Person();
  Person(string name, int age, int luck);

  ~Person();

  void changeLuck(Person&, Person&);

  const string &getName() const;
  void setName(const string &name);

  int getAge() const;
  void setAge(int age);

  int getLuck() const;
  void setLuck(int luck);

private:
  string name;
  int age{};
  int luck{};
};


#endif //ASSIGNMENT2_PERSON_H
