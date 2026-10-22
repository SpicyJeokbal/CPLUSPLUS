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

Data Segment
- Global and Static variables. Initialized and zero-initialized objects are commonly described as belonging to the data and BSS segments

Heap
- Memory commonly used for dynamically allocated objects, such as object created with new

Stack
- Commonly holds function call information and automatic variables


