#include "../include/Student.h"
#include <iostream>

void Person::display() const {
    std::cout << "Person: " << name << ", Age: " << age << "\n";
}

Student::Student(const std::string& n, int a, 
                 const std::string& id, double g)
    : Person(n, a),  // Initialize base class
      studentId(id),
      gpa(g)
{
    std::cout << "Student: Constructor called\n";
}

// Item 12: Copy constructor must copy all parts
Student::Student(const Student& other)
    : Person(other),  // Call base class copy constructor!
      studentId(other.studentId),  // Copy derived class members
      gpa(other.gpa)
{
    std::cout << "Student: Copy constructor called\n";
}

// Item 12: Copy assignment must copy all parts
Student& Student::operator=(const Student& other) {
    std::cout << "Student: operator= called\n";
    
    if (this == &other) {
        return *this;
    }
    
    // Copy base class parts
    Person::operator=(other);  // Call base class assignment!
    
    // Copy derived class parts
    studentId = other.studentId;
    gpa = other.gpa;
    
    return *this;
}

void Student::display() const {
    std::cout << "Student: " << name << ", Age: " << age 
              << ", ID: " << studentId << ", GPA: " << gpa << "\n";
}
