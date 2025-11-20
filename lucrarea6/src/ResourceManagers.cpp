#include "../include/ResourceManagers.h"
#include <iostream>
#include <algorithm>

// 1. NoCopyResource - Prohibit copying
NoCopyResource::NoCopyResource(size_t s) : size(s) {
    data = new int[size]();
    std::cout << "NoCopyResource: Created with size " << size << "\n";
}

NoCopyResource::~NoCopyResource() {
    delete[] data;
    std::cout << "NoCopyResource: Destroyed\n";
}

void NoCopyResource::setValue(size_t index, int value) {
    if (index < size) data[index] = value;
}

int NoCopyResource::getValue(size_t index) const {
    return (index < size) ? data[index] : 0;
}

// 2. SharedResource - Reference counting
SharedResource::SharedResource(size_t s) : size(s) {
    data = std::shared_ptr<int[]>(new int[size]());
    std::cout << "SharedResource: Created with size " << size 
              << " (use_count: " << data.use_count() << ")\n";
}

void SharedResource::setValue(size_t index, int value) {
    if (index < size) data[index] = value;
}

int SharedResource::getValue(size_t index) const {
    return (index < size) ? data[index] : 0;
}

// 3. DeepCopyResource - Deep copy
DeepCopyResource::DeepCopyResource(size_t s) : size(s) {
    data = new int[size]();
    std::cout << "DeepCopyResource: Created with size " << size << "\n";
}

DeepCopyResource::DeepCopyResource(const DeepCopyResource& other) 
    : size(other.size) {
    data = new int[size];
    std::memcpy(data, other.data, size * sizeof(int));
    std::cout << "DeepCopyResource: Deep copy created\n";
}

DeepCopyResource& DeepCopyResource::operator=(const DeepCopyResource& other) {
    std::cout << "DeepCopyResource: Deep copy assignment\n";
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        std::memcpy(data, other.data, size * sizeof(int));
    }
    return *this;
}

DeepCopyResource::~DeepCopyResource() {
    delete[] data;
    std::cout << "DeepCopyResource: Destroyed\n";
}

void DeepCopyResource::setValue(size_t index, int value) {
    if (index < size) data[index] = value;
}

int DeepCopyResource::getValue(size_t index) const {
    return (index < size) ? data[index] : 0;
}

// 4. UniqueResource - Transfer ownership
UniqueResource::UniqueResource(size_t s) : size(s) {
    data = std::unique_ptr<int[]>(new int[size]());
    std::cout << "UniqueResource: Created with size " << size << "\n";
}

UniqueResource::UniqueResource(UniqueResource&& other) noexcept 
    : data(std::move(other.data)), size(other.size) {
    other.size = 0;
    std::cout << "UniqueResource: Ownership transferred (move constructor)\n";
}

UniqueResource& UniqueResource::operator=(UniqueResource&& other) noexcept {
    std::cout << "UniqueResource: Ownership transferred (move assignment)\n";
    if (this != &other) {
        data = std::move(other.data);
        size = other.size;
        other.size = 0;
    }
    return *this;
}

void UniqueResource::setValue(size_t index, int value) {
    if (data && index < size) data[index] = value;
}

int UniqueResource::getValue(size_t index) const {
    return (data && index < size) ? data[index] : 0;
}
