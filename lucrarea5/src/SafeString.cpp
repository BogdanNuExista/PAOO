#include "../include/SafeString.h"
#include <iostream>

SafeString::SafeString(const char* str) {
    length = std::strlen(str);
    data = new char[length + 1];
    std::strcpy(data, str);
    std::cout << "SafeString: Constructor called for \"" << data << "\"\n";
}

SafeString::SafeString(const SafeString& other) {
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
    std::cout << "SafeString: Copy constructor called\n";
}

// Item 11: Handle self-assignment
SafeString& SafeString::operator=(const SafeString& other) {
    std::cout << "SafeString: operator= called\n";
    
    // Identity test: check for self-assignment
    if (this == &other) {
        std::cout << "SafeString: Self-assignment detected, skipping\n";
        return *this;
    }
    
    // Delete old resource
    delete[] data;
    
    // Allocate new resource and copy
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
    
    return *this;
}

SafeString::~SafeString() {
    std::cout << "SafeString: Destructor called for \"" << data << "\"\n";
    delete[] data;
}

void SafeString::display() const {
    std::cout << "SafeString: \"" << data << "\" (length: " << length << ")\n";
}
