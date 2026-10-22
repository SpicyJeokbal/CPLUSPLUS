```
+--------------------+
| Code Segment       |
+--------------------+
| Data Segment       | <-- global/static variables
+--------------------+
| Heap               | <-- new, malloc
|        ↑           |
|        |           |
+--------------------+
|        ↓           |
| Stack              | <-- local variables
+--------------------+
```

# DYNAMIC MEMORY ALLOCATION COMMON PROBLEMS
1. Dangling pointer
```
int* ptr = new int(5);

delete ptr;  // memory freed

std::cout << *ptr; // BAD
```
- ptr still contains the old address, but that memory no longer belongs to your program.

```
int* ptr;

{
    int x = 10;
    ptr = &x;
}

std::cout << *ptr; // BAD
```
-x is destroyed because it was on the stack.

Now ptr points to memory that no longer contains a valid x.


2. Double delete
```
int* ptr = new int(5);

delete ptr;
delete ptr; // BAD
```
- A double delete happens when you free the same memory twice.
- This can cause:
    Crashes
    Memory corruption
    Unpredictable behavior

```
int* ptr = new int(5);

delete ptr;
ptr = nullptr;

delete ptr; // Safe
```
C++ guarantees that:
```
delete ptr;
```
does nothing.

So setting a pointer to nullptr after deleting it helps prevent accidental double deletes.