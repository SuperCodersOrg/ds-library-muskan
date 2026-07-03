# Day 3 Journal

**Date:** 30 June 2026

---

## Section 1 — Specific Bug / Confusion

The biggest issue today was understanding how to store `string` objects inside `DynamicArray`.

My implementation worked correctly for primitive types like `int`, but failed for `string`.

The main confusion was:

* why direct assignment into allocated memory worked for integers
* but failed for objects like `string`

After debugging, I understood that raw allocated memory does not automatically create objects.

For `string`, I first needed to create the object at that memory location using its copy constructor.

Only after construction can it safely store the value.

This made me understand object lifecycle much deeper.

---

## Section 2 — Failed Attempt

My initial implementation treated object storage like primitive storage:

```cpp id="o4v1g5"
arr[size] = value;
```

This failed because the memory at `arr[size]` was only raw allocated memory.

No object existed there.

To fix this, I used placement new:

```cpp id="u4l6gk"
new(&arr[size]) T(value);
```

This explicitly constructs the object in-place.

After fixing append, I found another major issue:

my `regrow()` used:

```cpp id="z9f2hc"
realloc()
```

This worked for integers but failed for `string`.

Reason:

`realloc()` only moves raw bytes.

It does not:

* call constructors
* call destructors
* preserve object lifecycle

To solve this:

* allocated new memory with `malloc()`
* constructed objects one-by-one in new memory
* destroyed old objects
* released old memory

This fixed lifecycle handling.

---

## Section 3 — Memory Diagram

No new memory diagrams were created on this day.

The focus of this session was understanding object lifecycle behavior during implementation through code experimentation and debugging.

The existing diagrams from earlier sessions became insufficient after discovering that:

* object construction must happen before assignment
* object destruction must happen before deallocation
* `realloc()` does not preserve object lifecycle

These insights were noted during debugging and later reflected in updated design proposal diagrams in Version 2.


---

## Section 4 — Code Reference

**Commit Hash 1:**
a9d4cd3ce7dc1f49892ca21319d532b5852e46cc

**Purpose:**
Observed failure when storing `string`.

---

**Commit Hash 2:**
8224a574a11226244803e170b36c79460484ea58

**Purpose:**
Fixed object construction using placement new.

---

**Commit Hash 3:**
cb681621caf8bf64f1ed4fbbb3cda3b84a1a1ecd

**Purpose:**
Replaced `realloc()` with `malloc()` + manual object lifecycle handling.

---

## Section 5 — Learning Reflection

Today was the most important memory-management lesson so far.

I learned:

* raw memory and constructed objects are different
* primitive values can be directly copied
* objects must be explicitly constructed
* objects must be explicitly destroyed
* `realloc()` is unsafe for non-trivial types
* placement new creates objects in existing memory

Before today, I thought memory allocation was enough.

Now I understand that object lifetime is a separate responsibility.

This changed how I think about generic container implementation in C++.
