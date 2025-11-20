#ifndef SAFESTRING_H
#define SAFESTRING_H

#include <cstring>

// Item 11: Handle assignment to self in operator=
class SafeString {
private:
    char* data;
    size_t length;

public:
    SafeString(const char* str = "");
    SafeString(const SafeString& other);
    SafeString& operator=(const SafeString& other);
    ~SafeString();
    
    const char* getData() const { return data; }
    void display() const;
};

#endif // SAFESTRING_H
