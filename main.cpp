#include <random>
#include <ctime>
#include <vector>
#include <iostream>

#include "Person.h"

int main() {
  // seeded a random function
  srand(time(nullptr));
  vector<Person> persons(5);
  // made a person with luck above minimal
  Person staticPerson = Person("NULL", 0, 0);

  // initialized a vector of persons with minimal luck = 1
  persons.emplace_back("Person", 2, rand()%10+1);
  persons.emplace_back("Person1", 2, rand()%10+1);
  persons.emplace_back("Person2", 2, rand()%10+1);
  persons.emplace_back("Person3", 2, rand()%10+1);
  persons.emplace_back("Person4", 2, rand()%10+1);

  // comparing the persons lucks and saving the one with the highest
  for (const Person& tempPerson : persons) {
    staticPerson = staticPerson.getLuck() > tempPerson.getLuck()? staticPerson : tempPerson;
  }

  // outputting the person with the highest luck
  cout<< "Name: " << staticPerson.getName() << endl
      << "Age: " << staticPerson.getAge() << endl
      << "Luck: " << staticPerson.getLuck() << endl;

  /* The main difference between dynamic and static memory allocation is
   * the fact that dynamic memory can be released at any time during the program.
   * This means that with dynamic memory alloc. we can use the memory manually,
   * while in static memory allocation we cannot release memory when we want.
   * Also, static memory allocation is done before program execution.
   * This means if we want to make a memory efficient program,
   * then we need to use dynamic alloc.
   * But the execution of dynamic memory alloc. is slower than static memory alloc. */
  auto *dynamicPerson = new Person();
  /* In the dynamic memory alloc. the memory is released manually.
   * This means if we don't delete the dynamically allocated memory,
   * it won't be released. Device cannot use the unreleased memory,
   * it leaves less and less memory to the device and that's what we call memory leak.
   * To prevent the memory leak we should release all dynamically allocated memory using delete function */
  delete dynamicPerson;
  return 0;
}

void theExample() {
  /* Vector allocates objects one after another, and
   * I think most methods of vector is iterating through neighbour elements,
   * so I think that vector is an example of cache-friendly code */
  vector<int> integers;
  vector<vector<int>> twoDimensionalVector;
  int integer = 0;

  // Iterating through 2D array by rows is also considered cache-friendly
  for (int i = 0; i < twoDimensionalVector.size(); ++i) {
    for (int j = 0; j < twoDimensionalVector.at(i).size(); ++j) {
      twoDimensionalVector[i][j] = integer;
      integer++;
    }
  }
}

// We can use extern "C" to call C functions, write Variables, & include headers
extern "C" {
#include<stdio.h>    // Include C Header
int n;               // Declare a Variable
void func(int,int);  // Declare a function (function prototype)
}

// We can use const keyword to show that we will not modify the pointer or reference passed in arguments.
void theExample(const string& theString, const string* theSecondString) {
  // We can use const to make sure that some object will remain the same.
  const int ten = 10;
  // ten = 9; will force errors here.
}
/* Also, we can use const at member functions.
 * In const member func.-s is not allowed to change value of attributes of its class.
 * But only const func.-s can be called by const object.
 * So if we want to call some func. with const obj. we forced to make this func. const. */

