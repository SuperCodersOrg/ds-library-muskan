## Build Log – Session 3

**Date:** July 5, 2026

**Duration:** 2 Hours

### Goal

Create and execute a comprehensive test suite for the DynamicArray implementation to verify that every public method behaves correctly under normal and edge-case scenarios.

### Problem Encountered

No major implementation issues were encountered. The main challenge was ensuring that every operation was tested under different conditions instead of only testing common use cases.

### What I Tried

I wrote test cases covering:

- Empty array operations
- Single-element array
- Multiple insertions
- Dynamic resizing
- Element deletion
- Index validation
- Copy constructor
- Assignment operator
- Boundary conditions

After running the tests, I manually verified the outputs and confirmed that each operation behaved as expected.

### Outcome

The DynamicArray implementation successfully passed the test cases. Writing a dedicated test suite increased my confidence that the data structure handled both normal and edge-case scenarios correctly before moving on to the LinkedList implementation.