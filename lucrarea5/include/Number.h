#ifndef NUMBER_H
#define NUMBER_H

// Item 10: Have assignment operators return a reference to *this
class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}
    
    // Assignment operator returns reference to *this
    Number& operator=(const Number& other);
    
    // Compound assignment operators also return *this
    Number& operator+=(const Number& other);
    Number& operator-=(const Number& other);
    
    int getValue() const { return value; }
    void display() const;
};

#endif // NUMBER_H
