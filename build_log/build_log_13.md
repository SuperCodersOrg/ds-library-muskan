## Build Log – Session 3

**Date:** July 7, 2026

**Duration:** 2 Hours

### Goal

Complete the remaining LinkedList functionality and convert the implementation into a reusable template class.

### Problem Encountered

No major implementation issues were encountered. The primary objective was to ensure that the LinkedList logic worked with multiple data types before converting it into a generic implementation.

### What I Tried

I first completed the remaining LinkedList methods using integer values. I then verified the same implementation using `std::string` objects to ensure that object storage behaved correctly.

After confirming that both versions worked correctly, I converted the implementation into a template by replacing the concrete data type with `template<typename T>` throughout the class.

The following functionality was completed:

- `removeAt()`
- `removeValue()`
- `clear()`
- `getFront()`
- `getBack()`
- `get()`
- `set()`
- `getSize()`
- `isEmpty()`
- `print()`
- Copy Constructor
- Assignment Operator

### Outcome

The LinkedList became a fully generic data structure capable of storing different data types while maintaining the same implementation.