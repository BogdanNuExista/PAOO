#include "../include/NoCopy.h"
#include <iostream>

void NoCopy::display() const {
    std::cout << "NoCopy: id=" << id 
              << ", resource=" << resource << "\n";
}
