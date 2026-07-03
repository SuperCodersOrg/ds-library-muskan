## Build Log 02

**Date:** 1 july 2026(Evening)
**Duration:** 3 hours

**Goal:**
Complete the remaining memory diagrams for primitive `DynamicArray<int>` operations.

**Problem Encountered:**
After creating constructor and append diagrams, I still needed to visualize the remaining operations to fully understand element shifting and complexity behavior.

Since append already helped me understand object lifecycle and reallocation, I focused only on primitive type diagrams for the remaining methods.

**What I Tried:**

I created memory diagrams for:

### Insert

Analyzed:

* Best case → insert at end
* Average case → insert in middle
* Worst case → insert at front

Tracked right shifting of elements.

---

### Remove

Analyzed:

* Best case → remove from end
* Average case → remove from middle
* Worst case → remove from front

Tracked left shifting of elements.

---

### Get

Analyzed direct index access.

Verified constant-time access.

I used these diagrams to study:

* data movement
* shifting cost
* index behavior
* operation complexity

**Outcome:**
Completed the remaining primitive operation diagrams.

Major learnings:

* insert/remove complexity depends on shift distance
* front operations are most expensive
* end operations are cheapest
* direct indexing gives O(1) access

This completed the primitive operation-level design before moving to copy/destructor logic.
