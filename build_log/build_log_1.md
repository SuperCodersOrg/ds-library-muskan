## Build Log 01

**Date:** 24 June 2026
**Duration:** 2 hours

**Goal:**
Create memory diagrams for `DynamicArray` operations to visualize internal storage and element movement.

**Problem Encountered:**
After finalizing the proposal, I needed to visualize how memory behaves internally during operations.

Without diagrams, understanding shifting and storage flow was difficult.

**What I Tried:**

I created memory diagrams for:

* constructor
* append
* insert
* remove
* get

In the initial design:

* `DynamicArray` object itself stored on heap
* object stores:

  * `size`
  * `capacity`
  * `arr` pointer

The `arr` pointer points to a separate heap block where array elements are stored.

I visualized:

### Append

* direct insertion
* regrow case

### Insert

* shifting elements right

### Remove

* shifting elements left

### Get

* direct index access

These diagrams helped map element movement and memory layout.

**Outcome:**
Completed the first operation-level memory diagrams.

Major learnings:

* internal storage is separated from object metadata
* append may trigger reallocation
* insert/remove require shifting
* get uses direct indexing

These diagrams supported the original design proposal before implementation revisions.
