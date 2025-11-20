#ifndef PERSON_H
#define PERSON_H

#include <string>

// Item 4: Make sure that objects are initialized before they're used
class Person {
private:
    std::string name;
    int age;
    double height;

public:
    // Constructor with initialization list - proper way to initialize
    Person(const std::string& n, int a, double h);
    
    void display() const;
};

#endif // PERSON_H
