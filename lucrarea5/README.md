# Lucrarea 5 - Effective C++ Items 10, 11, 12

## Item 10: Have assignment operators return a reference to *this

**Problem:** Assignment operators should allow chaining (e.g., `a = b = c`).

**Solution:** Return `*this` by reference from assignment operators.

**Example in code:** The `Number` class demonstrates:
- Assignment operator returns `*this`
- Enables chaining: `a = b = c`
- Works with compound assignments (+=, -=, etc.)

## Item 11: Handle assignment to self in operator=

**Problem:** Self-assignment (e.g., `x = x`) can cause problems, especially with dynamic memory.

**Solution:** Check for self-assignment or use copy-and-swap idiom.

**Example in code:** The `SafeString` class demonstrates:
- Identity test: `if (this == &other) return *this;`
- Prevents deleting resources still needed
- Ensures exception safety

## Item 12: Copy all parts of an object

**Problem:** When copying objects, especially in inheritance, you might forget to copy base class members or new members added later.

**Solution:** 
- Copy all local data members
- Call base class copy functions for derived classes
- Remember to update copy functions when adding new members

**Example in code:** The `Student` (derived from `Person`) demonstrates:
- Copying base class members via base copy constructor/assignment
- Copying all derived class members
- Proper handling in both copy constructor and copy assignment

## Build and Run

```bash
mkdir build
cd build
cmake ..
make
./src/lucrarea5_demo
```
