#ifndef RESOURCEMANAGERS_H
#define RESOURCEMANAGERS_H

#include <memory>
#include <string>
#include <cstring>

// Item 14: Different copying behaviors for resource-managing classes

// 1. Prohibit copying
class NoCopyResource {
private:
    int* data;
    size_t size;

public:
    NoCopyResource(size_t s);
    ~NoCopyResource();
    
    // Delete copy operations
    NoCopyResource(const NoCopyResource&) = delete;
    NoCopyResource& operator=(const NoCopyResource&) = delete;
    
    void setValue(size_t index, int value);
    int getValue(size_t index) const;
};

// 2. Reference-counted resource (using shared_ptr)
class SharedResource {
private:
    std::shared_ptr<int[]> data;
    size_t size;

public:
    SharedResource(size_t s);
    
    // Default copy operations work fine with shared_ptr
    // Multiple objects share the same resource
    
    void setValue(size_t index, int value);
    int getValue(size_t index) const;
    long useCount() const { return data.use_count(); }
};

// 3. Deep copy resource
class DeepCopyResource {
private:
    int* data;
    size_t size;

public:
    DeepCopyResource(size_t s);
    DeepCopyResource(const DeepCopyResource& other);  // Deep copy
    DeepCopyResource& operator=(const DeepCopyResource& other);  // Deep copy
    ~DeepCopyResource();
    
    void setValue(size_t index, int value);
    int getValue(size_t index) const;
};

// 4. Transfer ownership (using unique_ptr)
class UniqueResource {
private:
    std::unique_ptr<int[]> data;
    size_t size;

public:
    UniqueResource(size_t s);
    
    // Move semantics for transfer of ownership
    UniqueResource(UniqueResource&& other) noexcept;
    UniqueResource& operator=(UniqueResource&& other) noexcept;
    
    // Delete copy operations
    UniqueResource(const UniqueResource&) = delete;
    UniqueResource& operator=(const UniqueResource&) = delete;
    
    void setValue(size_t index, int value);
    int getValue(size_t index) const;
};

#endif // RESOURCEMANAGERS_H
