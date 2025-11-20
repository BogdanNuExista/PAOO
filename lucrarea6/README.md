# Lucrarea 6 - Effective C++ Items 13, 14

## Item 13: Use objects to manage resources

**Problem:** Manual resource management (new/delete) is error-prone - you might forget to delete, or an exception might prevent cleanup.

**Solution:** Use RAII (Resource Acquisition Is Initialization) - let objects manage resources through constructors and destructors.

**Example in code:** 
- `std::unique_ptr` and `std::shared_ptr` automatically manage memory
- Custom `FileHandler` class demonstrates RAII for file resources
- Resources are automatically released when objects go out of scope
- Exception-safe resource management

## Item 14: Think carefully about copying behavior in resource-managing classes

**Problem:** When a class manages resources, you need to decide what copying means:
- Prohibit copying?
- Reference-count the resource?
- Deep copy the resource?
- Transfer ownership?

**Solution:** Choose appropriate copying behavior based on your needs.

**Example in code:** 

1. **Prohibit copying** (`NoCopyResource`): Use `= delete` for resources that shouldn't be copied
2. **Reference counting** (`SharedResource`): Use `std::shared_ptr` to share ownership
3. **Deep copy** (`DeepCopyResource`): Create independent copies of the resource
4. **Transfer ownership** (`UniqueResource`): Use `std::unique_ptr` for exclusive ownership

## Build and Run

```bash
mkdir build
cd build
cmake ..
make
./src/lucrarea6_demo
```
