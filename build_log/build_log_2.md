## Build Log Entry — Template Implementation Issue

**Date:** June 29, 2026
**Duration:** 1.5 hour

**Goal:**
Set up the `DynamicArray` class structure properly using separate files for declaration and implementation.

**Problem Encountered:**
Initially, I wrote my class declaration in a header file and method implementations in a `.cpp` file. This worked fine until I converted the class into a template. After that, the compiler could not find the method definitions and gave linking errors.

**What I Tried:**
At first, I kept the template implementation inside the `.cpp` file, expecting it to work the same way as normal classes. After debugging and researching, I understood that template definitions must be visible during compilation.

To solve this, I moved all template implementations into a `.tpp` file and included it inside the header file.

**Outcome:**
The issue was resolved. I understood how template instantiation works in C++ and why template definitions cannot stay only in `.cpp` files.
