#include "DynamicArray.h"
#include <iostream>
#include <string>

void separator(const std::string& title) {
    std::cout << "\n======================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "======================================\n" << std::endl;
}

void functionByValue(DynamicArray arr) {
    std::cout << "In functie, array la: " << arr.getDataPointer() << std::endl;
    arr.print();
}

DynamicArray createArray(int n) {
    DynamicArray temp(5);
    for (int i = 0; i < n; ++i) {
        temp.push_back(i * 10);
    }
    return temp;
}

int main() {
    std::cout << "\n=== C++ CONCEPTS DEMO ===\n" << std::endl;

    // 1. ENCAPSULATION
    separator("1. ENCAPSULATION");
    std::cout << "Private members cannot be accessed directly.\n" << std::endl;
    DynamicArray arr1(5);
    arr1.push_back(10);
    arr1.push_back(20);
    arr1.push_back(30);
    
    std::cout << "Size: " << arr1.getSize() << std::endl;
    std::cout << "Capacity: " << arr1.getCapacity() << std::endl;
    arr1.print();

    // 2. CONSTRUCTOR WITH MEMBER INITIALIZATION
    separator("2. CONSTRUCTOR");
    DynamicArray arr2(3);
    arr2.push_back(100);
    arr2.push_back(200);
    arr2.print();

    // 3. DESTRUCTOR
    separator("3. DESTRUCTOR");
    {
        DynamicArray arr3(4);
        arr3.push_back(1);
        arr3.push_back(2);
        arr3.print();
    }
    // arr3 goes out of scope here -> the destructor is called
    std::cout << "Memory freed automatically!\n" << std::endl;

    // 4. COPY CONSTRUCTOR
    separator("4. COPY CONSTRUCTOR");
    std::cout << "Deep copy prevents double-free errors.\n" << std::endl;
    
    DynamicArray original(4);
    original.push_back(111);
    original.push_back(222);
    original.push_back(333);
    std::cout << "Original at: " << original.getDataPointer() << std::endl;
    original.print();
    
    DynamicArray copy = original;
    std::cout << "Copy at: " << copy.getDataPointer() << std::endl;
    copy.print();
    
    copy.push_back(444);
    std::cout << "\nOriginal (unchanged):" << std::endl;
    original.print();
    std::cout << "Copy (modified):" << std::endl;
    copy.print();

    // 4b. Copy with function
    separator("4b. COPY - Function by value");
    DynamicArray arr4(3);
    arr4.push_back(77);
    arr4.push_back(88);
    functionByValue(arr4);
    // 5. MOVE CONSTRUCTOR
    separator("5. MOVE CONSTRUCTOR");
    std::cout << "Move transfers resources without copying.\n" << std::endl;
    
    DynamicArray arr5 = createArray(3);
    std::cout << "Received at: " << arr5.getDataPointer() << std::endl;
    arr5.print();
    
    std::cout << "\nExplicit move:" << std::endl;
    DynamicArray arr6(3);
    arr6.push_back(555);
    arr6.push_back(666);
    std::cout << "Before move: " << arr6.getDataPointer() << std::endl;
    
    DynamicArray arr7 = std::move(arr6);
    std::cout << "After move: " << arr7.getDataPointer() << std::endl;
    arr7.print();

    return 0;
}
