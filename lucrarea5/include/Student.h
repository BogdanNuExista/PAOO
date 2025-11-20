#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// Item 12: Copy all parts of an object
// Base class
class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& n = "", int a = 0) : name(n), age(a) {}
    
    void display() const;
};

// Derived class - must copy all parts including base class
class Student : public Person {
private:
    std::string studentId;
    double gpa;

public:
    Student(const std::string& n = "", int a = 0, 
            const std::string& id = "", double g = 0.0);
    
    // Copy constructor - must copy base and derived parts
    Student(const Student& other);
    
    // Copy assignment - must copy base and derived parts
    Student& operator=(const Student& other);
    
    void display() const;
};

#endif // STUDENT_H
