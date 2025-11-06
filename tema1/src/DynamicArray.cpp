#include "DynamicArray.h"
#include <cstring>

// Constructor with member initialization list
DynamicArray::DynamicArray(size_t initialCapacity)
    : data(new int[initialCapacity]), 
      size(0),
      capacity(initialCapacity)
{
    std::cout << "[CONSTRUCTOR] Created with capacity " << capacity 
              << " at " << data << std::endl;
}

// Destructor - frees heap memory
DynamicArray::~DynamicArray() {
    std::cout << "[DESTRUCTOR] Freeing memory at " << data 
              << " (size=" << size << ", capacity=" << capacity << ")" << std::endl;
    delete[] data;
    data = nullptr;
}

// Copy constructor - deep copy
DynamicArray::DynamicArray(const DynamicArray& other) 
    : data(new int[other.capacity]),
      size(other.size),
      capacity(other.capacity)
{
    std::cout << "[COPY CONSTRUCTOR] Copying " << size << " elements from " 
              << other.data << " to " << data << std::endl;
    std::memcpy(data, other.data, size * sizeof(int));
}

// Copy assignment operator
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] data;
        data = new int[other.capacity];
        size = other.size;
        capacity = other.capacity;
        std::memcpy(data, other.data, size * sizeof(int));
    }
    return *this;
}

// Move constructor - transfers resources
DynamicArray::DynamicArray(DynamicArray&& other) noexcept
    : data(other.data),
      size(other.size),
      capacity(other.capacity)
{
    std::cout << "[MOVE CONSTRUCTOR] Moving resources from " << other.data 
              << " (size=" << size << ")" << std::endl;
    
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

// Move assignment operator
DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

void DynamicArray::resize() {
    size_t newCapacity = capacity * 2;
    int* newData = new int[newCapacity];
    std::memcpy(newData, data, size * sizeof(int));
    delete[] data;
    
    data = newData;
    capacity = newCapacity;
}

void DynamicArray::push_back(int value) {
    if (size >= capacity) {
        resize();
    }
    data[size++] = value;
}

int DynamicArray::get(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void DynamicArray::set(size_t index, int value) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

size_t DynamicArray::getSize() const {
    return size;
}

size_t DynamicArray::getCapacity() const {
    return capacity;
}

void DynamicArray::print() const {
    std::cout << "Array[" << size << "/" << capacity << "]: [";
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
