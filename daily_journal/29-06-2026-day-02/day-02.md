# Day 2 Journal

**Date:** 29 June 2026

---

## Section 1 — Specific Bug / Confusion

The main confusion today was understanding why my `DynamicArray<int>` implementation worked correctly, but failed when I converted it into a template.

Initially, I thought templates behave like normal classes and can have implementations inside `.cpp` files.

During compilation, the compiler produced linking errors because template definitions were not visible during instantiation.

This made me investigate how template instantiation works internally.

I learned that:

* templates are only generated when used
* compiler must see full implementation at compile time
* separating template definitions like normal classes causes linker failures

This was my first major confusion with C++ templates.

---

## Section 2 — Failed Attempt

My first attempt:

* class declaration in `.h`
* method definitions in `.cpp`

This worked for `DynamicArray<int>` when hardcoded.

After converting to:

```cpp id="e7yz4h"
template<typename T>
```

it failed.

While fixing it, I also made syntax mistakes:

* forgetting to redeclare `template<typename T>` before each function
* forgetting `DynamicArray<T>::` before method names

Example:

Wrong:

```cpp id="g2r8mu"
DynamicArray::append(T value)
```

Correct:

```cpp id="cyu1qh"
template<typename T>
void DynamicArray<T>::append(T value)
```

This helped me understand template syntax and instantiation rules.

I solved it by moving implementation into:

```text id="ajphz0"
DynamicArray.tpp
```

and including it inside the header.

---

## Section 3 — Memory Diagram

Today I also revised my mental model of object storage.

Initially, in my proposal:

* `DynamicArray` object itself was stored on heap

Today I realized:

* the object itself can live on stack
* only internal `arr` storage lives on heap

This changed my full ownership model.

The revised memory diagrams were created later and stored in:

```text id="z3i6ga"
docs/design_proposals/dynamic_array/v2/images/
```

These updated diagrams reflect:

* stack object
* heap array
* `size`, `capacity`, and `arr` pointer inside stack object

---

## Section 4 — Code Reference

**Commit Hash 1:**
ad6a8657551917232e7ad7d78ec76d08c05a7559

**Purpose:**
Implemented initial append, get, and regrow logic for integer dynamic array.

**Files:**

* `include/DynamicArray/DynamicArray.h`
* `include/DynamicArray/DynamicArray.tpp`

---

**Commit Hash 2:**
56f81a266ef8c4b09ad3d1bf0ea32690441ead2a

**Purpose:**
Observed template compilation failure.

---

**Commit Hash 3:**
5b996a3d436c7092b5e40aa56d13cd1f2961366c

**Purpose:**
Resolved template instantiation issue by moving implementation into `.tpp` and including it in header.

---

## Section 5 — Learning Reflection

Today changed my understanding in two important areas:

### Templates

I learned that templates are compile-time blueprints, not normal classes.

The compiler needs full visibility of definitions during instantiation.

This explains why `.cpp` separation fails.

---

### Object Storage

Coming from Java, I believed objects always live on the heap.

Today I understood:

* objects can live on stack
* objects can own heap memory internally

This changed how I think about container design and ownership in C++.

This was one of the most important foundational learning days in this project.
