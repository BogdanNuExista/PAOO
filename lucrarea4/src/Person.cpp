#include "../include/Person.h"
#include <iostream>

// Item 4: Initialize members using initialization list
// Order matches declaration order in the class
Person::Person(const std::string& n, int a, double h) 
    : name(n),      // Initialize in declaration order
      age(a),
      height(h)
{
    // Body is empty - initialization already done
    // This is more efficient than assignment in body
}

void Person::display() const {
    std::cout << "Person: " << name 
              << ", Age: " << age 
              << ", Height: " << height << "m\n";
}
