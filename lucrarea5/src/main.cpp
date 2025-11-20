#include <iostream>
#include "../include/Number.h"
#include "../include/SafeString.h"
#include "../include/Student.h"

int main() {
    std::cout << "=== Item 10: Return reference to *this ===\n";
    Number a(10), b(20), c(30);
    
    std::cout << "Before chaining: ";
    a.display();
    
    // Chaining assignments: a = b = c
    a = b = c;  // Equivalent to: a.operator=(b.operator=(c))
    
    std::cout << "After a = b = c: ";
    a.display();
    b.display();
    c.display();
    
    // Compound assignments
    a += Number(5);
    std::cout << "After a += 5: ";
    a.display();
    std::cout << "\n";

    std::cout << "=== Item 11: Handle self-assignment ===\n";
    SafeString s1("Hello");
    s1.display();
    
    SafeString s2("World");
    s2.display();
    
    s2 = s1;  // Normal assignment
    s2.display();
    
    s1 = s1;  // Self-assignment (should be handled safely)
    s1.display();
    std::cout << "\n";

    std::cout << "=== Item 12: Copy all parts of an object ===\n";
    Student st1("Alice", 20, "S12345", 3.8);
    st1.display();
    
    // Copy constructor - copies all parts
    Student st2 = st1;
    st2.display();
    
    // Copy assignment - copies all parts
    Student st3("Bob", 21, "S67890", 3.5);
    st3.display();
    
    st3 = st1;
    std::cout << "After assignment:\n";
    st3.display();
    std::cout << "\n";

    return 0;
}
