## Build Log 03

**Date:** 02 July 2026
**Duration:** 1.5 days

**Goal:**
Understand object lifetime management inside `DynamicArray` by creating detailed memory diagrams for destructor, copy constructor, and assignment operator for both primitive (`int`) and non-primitive (`string`) types.

**Problem Encountered:**
After implementing the core methods, I realized memory cleanup and copying behave very differently for primitive and non-primitive types.

For `int`, freeing the array memory is enough.

But for `string`, each stored object internally manages its own character buffer on the heap.

This created confusion about:

* how destructors work on stored objects
* whether deleting the array automatically destroys objects
* how deep copy works for strings
* how assignment replaces old memory safely

My earlier design did not fully capture this internal lifecycle.

**What I Tried:**

I created detailed memory diagrams for:

---

### Destructor Diagram

#### `DynamicArray<int>`

I traced:

* object destruction starts
* heap block containing integer values is freed directly

Since integers do not own internal memory, no per-element cleanup is needed.

---

#### `DynamicArray<string>`

I traced:

* destructor starts
* each string object inside the array is destroyed
* each string releases its internal character buffer
* after all string objects are destroyed, the array memory is released

This helped me understand nested destruction.

---

### Copy Constructor Diagram

#### `DynamicArray<int>`

Flow:

* new heap block allocated
* integer values copied directly

Simple value copy.

---

#### `DynamicArray<string>`

Flow:

* new heap block allocated
* new string objects created
* internal character buffers copied independently

I verified:

* copied array has independent ownership
* modifying one array does not affect the other

This confirmed deep copy.

---

### Assignment Operator Diagram

I drew:

#### Step 1:

Destroy current stored elements.

#### Step 2:

Release current heap memory.

#### Step 3:

Allocate new memory.

#### Step 4:

Copy incoming elements.

For `string`, I traced both:

* object-level copy
* internal buffer-level copy

---

### Self Assignment Case

Example:
`arr = arr`

I created a separate diagram for this case and added self-assignment protection to prevent:

* accidental self-destruction
* invalid memory access
* double free

---

I updated my design proposal to include:

* destruction flow for primitive vs non-primitive types
* nested string ownership model
* deep copy behavior
* assignment lifecycle
* self-assignment handling

**Outcome:**
I now clearly understand the Rule of Three at memory level.

Major learnings:

* primitive destruction is simple memory release
* object destruction involves nested cleanup
* strings own internal heap memory
* deep copy creates independent internal ownership
* assignment requires destroy-then-rebuild logic
* self-assignment protection is necessary for safe containers

This completed the ownership model of my `DynamicArray`.
