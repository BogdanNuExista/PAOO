# C++ Project - Fundamental Concepts

A C++ application demonstrating object-oriented programming concepts.

Tema constă într-o aplicație scrisă în c++ în cadrul căreia să se abordeze următoarele subiecte discutate:
1. build folosind cmake respectând structura discutată la laborator (3p)
2. încapsulare (1p)
3. inițializarea membrilor din constructor (1p)
4. eliberarea heap-ului în cadrul destructorului (1p)
5. suprascrierea copy constructor-ului (2p)
6. crearea unui move constructor (2p).
Pentru subpunctele 3-6 trebuie să ilustrați exemple reprezentative, care indică clar nevoia implementării acestor concepte (e.g., arătați de ce este nevoie de copy constructor și ce se poate întâmpla dacă nu este suprascris).

## Requirements Implemented (10 points)

1. **CMake Build** (3p) - Organized project structure with CMake
2. **Encapsulation** (1p) - Private/public members
3. **Member Initialization** (1p) - Initialization list in constructor
4. **Heap Memory Management** (1p) - Destructor frees memory
5. **Copy Constructor** (2p) - Deep copy implementation
6. **Move Constructor** (2p) - Resource transfer optimization

## Project Structure

```
cpp_project/
├── CMakeLists.txt
├── include/
│   └── DynamicArray.h
└── src/
    ├── CMakeLists.txt
    ├── DynamicArray.cpp
    └── main.cpp
```

## Build and Run

```bash
# Configure
cmake -S . -B build

# Compile
cmake --build build

# Run
.\build\src\dynamic_array_demo.exe  # Windows
./build/src/dynamic_array_demo      # Linux/Mac
```

## The DynamicArray Class

A simple dynamic array implementation that demonstrates:

### 1. Encapsulation
- Private members: `data`, `size`, `capacity`
- Public interface: `push_back()`, `get()`, `print()`, etc.

### 2. Constructor with Member Initialization
```cpp
DynamicArray::DynamicArray(size_t initialCapacity) 
    : data(new int[initialCapacity]),
      size(0),
      capacity(initialCapacity)
{ }
```

### 3. Destructor
```cpp
~DynamicArray() {
    delete[] data;  // Frees heap memory
}
```

### 4. Copy Constructor
```cpp
DynamicArray::DynamicArray(const DynamicArray& other) 
    : data(new int[other.capacity]),  // Deep copy
      size(other.size),
      capacity(other.capacity)
{
    std::memcpy(data, other.data, size * sizeof(int));
}
```

**Why needed?** Without it, the default constructor does shallow copy, causing:
- Two objects pointing to same memory
- Double-free error when both objects are destroyed
- Undefined behavior

### 5. Move Constructor
```cpp
DynamicArray::DynamicArray(DynamicArray&& other) noexcept
    : data(other.data),
      size(other.size),
      capacity(other.capacity)
{
    other.data = nullptr;  // Invalidate source
    other.size = 0;
    other.capacity = 0;
}
```

**Why needed?** Optimization for temporary objects:
- Copy: allocates new memory + copies all elements (slow)
- Move: transfers pointer only (fast - O(1) vs O(n))

## Output

The program prints messages showing when each constructor/destructor is called:

```
[CONSTRUCTOR] Created with capacity 5 at 0x...
[COPY CONSTRUCTOR] Copying 3 elements from 0x... to 0x...
[MOVE CONSTRUCTOR] Moving resources from 0x...
[DESTRUCTOR] Freeing memory at 0x...
```

## Key Concepts Demonstrated

- **Encapsulation**: Data hiding and controlled access
- **RAII**: Resource Acquisition Is Initialization
- **Rule of Five**: Destructor, copy/move constructors, copy/move assignment
- **Deep vs Shallow Copy**: Independent vs shared memory
- **Move Semantics**: Performance optimization for temporaries

---

**Project Status: Complete and ready to submit**

