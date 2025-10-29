#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>

// DynamicArray class demonstrates:
// - Encapsulation (private/public members)
// - Member initialization in constructor
// - Heap memory management in destructor
// - Copy constructor (deep copy)
// - Move constructor (optimization)
class DynamicArray {
private:
    int* data;
    size_t size;
    size_t capacity;
    void resize();

public:
    explicit DynamicArray(size_t initialCapacity = 10); // Constructor
    ~DynamicArray(); // Destructor  
    DynamicArray(const DynamicArray& other); // Copy constructor
    DynamicArray& operator=(const DynamicArray& other); // Copy assignment operator
    DynamicArray(DynamicArray&& other) noexcept; // Move constructor
    DynamicArray& operator=(DynamicArray&& other) noexcept; // Move assignment operator
    
    // Encapsulation - Public methods for controlled access to private members
    void push_back(int value);
    int get(size_t index) const;
    void set(size_t index, int value);
    size_t getSize() const;
    size_t getCapacity() const;
    void print() const;
    void* getDataPointer() const { return data; }
};

#endif
