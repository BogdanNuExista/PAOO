#ifndef NOCOPY_H
#define NOCOPY_H

#include <string>

// Item 6: Explicitly disallow the use of compiler-generated functions
// Use = delete to prevent copying
class NoCopy {
private:
    int id;
    std::string resource;

public:
    NoCopy(int i, const std::string& r) : id(i), resource(r) {}
    
    // Explicitly delete copy constructor and copy assignment
    NoCopy(const NoCopy&) = delete;
    NoCopy& operator=(const NoCopy&) = delete;
    
    void display() const;
};

#endif // NOCOPY_H
