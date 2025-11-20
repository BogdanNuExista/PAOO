#include <iostream>
#include <memory>
#include "../include/FileHandler.h"
#include "../include/ResourceManagers.h"

void demonstrateSmartPointers() {
    std::cout << "=== Item 13: Smart Pointers ===\n";
    
    // unique_ptr - exclusive ownership
    std::unique_ptr<int> ptr1(new int(42));
    std::cout << "unique_ptr value: " << *ptr1 << "\n";
    
    // Can transfer ownership
    std::unique_ptr<int> ptr2 = std::move(ptr1);
    std::cout << "After move, ptr2 value: " << *ptr2 << "\n";
    
    // shared_ptr - shared ownership
    std::shared_ptr<int> sptr1(new int(100));
    std::cout << "shared_ptr value: " << *sptr1 
              << ", use_count: " << sptr1.use_count() << "\n";
    
    std::shared_ptr<int> sptr2 = sptr1;  // Share ownership
    std::cout << "After copy, use_count: " << sptr1.use_count() << "\n";
    
    std::cout << "\n";
}

void demonstrateRAII() {
    std::cout << "=== Item 13: RAII with FileHandler ===\n";
    {
        FileHandler fh("test_file.txt");
        if (fh.isFileOpen()) {
            fh.write("Hello, RAII!");
            std::cout << "File content: " << fh.read() << "\n";
        }
        // File automatically closed when fh goes out of scope
    }
    std::cout << "FileHandler scope ended - file auto-closed\n\n";
}

void demonstrateNoCopy() {
    std::cout << "=== Item 14: Prohibit Copying ===\n";
    NoCopyResource res(5);
    res.setValue(0, 100);
    std::cout << "Value at index 0: " << res.getValue(0) << "\n";
    
    // Cannot copy:
    // NoCopyResource res2 = res;  // Compilation error
    // NoCopyResource res3(res);   // Compilation error
    
    std::cout << "\n";
}

void demonstrateSharedResource() {
    std::cout << "=== Item 14: Reference Counting ===\n";
    SharedResource res1(5);
    res1.setValue(0, 200);
    std::cout << "res1 use_count: " << res1.useCount() << "\n";
    
    SharedResource res2 = res1;  // Share ownership
    std::cout << "After copy, res1 use_count: " << res1.useCount() << "\n";
    std::cout << "res2 use_count: " << res2.useCount() << "\n";
    std::cout << "res2 value at index 0: " << res2.getValue(0) << "\n";
    
    res2.setValue(0, 300);  // Modifies shared resource
    std::cout << "After modifying res2, res1 value: " << res1.getValue(0) << "\n";
    
    std::cout << "\n";
}

void demonstrateDeepCopy() {
    std::cout << "=== Item 14: Deep Copy ===\n";
    DeepCopyResource res1(5);
    res1.setValue(0, 400);
    std::cout << "res1 value at index 0: " << res1.getValue(0) << "\n";
    
    DeepCopyResource res2 = res1;  // Deep copy
    std::cout << "res2 value at index 0: " << res2.getValue(0) << "\n";
    
    res2.setValue(0, 500);  // Modifies only res2
    std::cout << "After modifying res2:\n";
    std::cout << "  res1 value: " << res1.getValue(0) << "\n";
    std::cout << "  res2 value: " << res2.getValue(0) << "\n";
    
    std::cout << "\n";
}

void demonstrateUniqueResource() {
    std::cout << "=== Item 14: Transfer Ownership ===\n";
    UniqueResource res1(5);
    res1.setValue(0, 600);
    std::cout << "res1 value at index 0: " << res1.getValue(0) << "\n";
    
    UniqueResource res2 = std::move(res1);  // Transfer ownership
    std::cout << "After move, res2 value: " << res2.getValue(0) << "\n";
    std::cout << "res1 no longer owns the resource\n";
    
    std::cout << "\n";
}

int main() {
    demonstrateSmartPointers();
    demonstrateRAII();
    demonstrateNoCopy();
    demonstrateSharedResource();
    demonstrateDeepCopy();
    demonstrateUniqueResource();
    
    std::cout << "All demonstrations completed successfully!\n";
    
    return 0;
}
