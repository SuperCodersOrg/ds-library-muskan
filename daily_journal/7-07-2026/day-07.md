# Day 2 Journal
**Date:** July 7, 2026

---

# Section 1 – Specific Bug

No major compiler errors or runtime issues were encountered during today's implementation. All remaining LinkedList methods were completed successfully. After implementing each method, I verified its behavior and made small improvements where necessary.

---

# Section 2 – Failed Attempt

There was no significant failed attempt during today's work. Instead of implementing every remaining function first, I completed one function at a time and verified its behavior before moving to the next. This incremental approach made it easier to ensure correctness and reduced the likelihood of introducing errors into previously completed methods.

---

# Section 3 – Memory Diagram

**(Hand-drawn memory diagram attached separately.)**

The diagram contains:

- `removeAt()`
- `removeValue()`
- `clear()`
- Copy Constructor (Deep Copy)
- Assignment Operator
- Memory after `clear()`
- Pointer movement during deletion operations

---

# Section 4 – Code Reference

### Final Commit Hash

`57161951a1533c19cc792f1491969e9ec1e4ad31`

### Development Commits

| Commit Hash | Function(s) |
|--------------|-------------|
| 4cc9bb0a280f7046451ffdfd649670e8d682fb01 | `removeValue()` |
| 1469dda53e2df363535abcde4ba32c744703f98d | `print()` improvement |
| a860e7ef42d28b2ea25eaa944e395ae2bf5ce11c | `getBack()` |
| e0b63a3baa1b7e028ee0e5a4d65da055fed1dcde | `get()` |
| 696078613a322cdeb47dd0b30e37ed140f274014 | `getSize()`, `isEmpty()` |
| 841be6819029c58487dc583f28133e0c9e6bf580 | `set()` |
| c08939f82f8ad50dc5efd1cd3b096ffec0d7aafe | Copy Constructor |
| 57161951a1533c19cc792f1491969e9ec1e4ad31 | Assignment Operator and overall improvements |

### Files

- LinkList.cpp
- LinkList.h
- LinkListTest.cpp *(or your actual test file name)*

### Approximate Line Numbers (LinkList.cpp)

| Function | Approx. Lines |
|----------|---------------|
| Copy Constructor | 21–33 |
| Assignment Operator | 34–43 |
| removeAt() | 171–205 |
| removeValue() | 207–238 |
| clear() | 240–253 |
| getFront() | 255–260 |
| getBack() | 262–267 |
| get() | 269–283 |
| set() | 285–299 |
| getSize() | 301–304 |
| isEmpty() | 306–309 |
| print() | 311–324 |

### Testing

Individual test cases were written for every public method, including:

- Constructor
- Insert operations
- Delete operations
- Search and access methods
- Empty list operations
- Single-node list operations
- Copy constructor
- Assignment operator
- Boundary index validation

---

# Section 5 – Learning Reflection

Today's work completed the LinkedList implementation by adding the remaining utility methods and deep-copy functionality. Implementing the copy constructor and assignment operator strengthened my understanding of the Rule of Three and why deep copying is necessary to prevent shared ownership of dynamically allocated memory. Reviewing and testing the complete implementation also reinforced the importance of verifying every public method and handling edge cases consistently throughout the data structure.