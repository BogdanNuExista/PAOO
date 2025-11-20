#include "../include/Number.h"
#include <iostream>

// Item 10: Return *this to enable chaining
Number& Number::operator=(const Number& other) {
    std::cout << "Number: operator= called\n";
    value = other.value;
    return *this;  // Return reference to this object
}

Number& Number::operator+=(const Number& other) {
    value += other.value;
    return *this;  // Return reference to this object
}

Number& Number::operator-=(const Number& other) {
    value -= other.value;
    return *this;  // Return reference to this object
}

void Number::display() const {
    std::cout << "Number value: " << value << "\n";
}
