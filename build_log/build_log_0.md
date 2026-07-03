## Build Log 00\

**Date:** 24 June 2026
**Duration:** 3 hours

**Goal:**
Create the first design proposal for `DynamicArray` and finalize growth, shrink, and initial capacity strategy.

**Problem Encountered:**
Before implementation, I needed to decide how the array should grow and shrink while keeping insertion efficient and avoiding unnecessary reallocations.

The challenge was balancing time complexity and memory efficiency.

**What I Tried:**

I analyzed append operation complexity when using growth factor 2.

For `n` insertions, copy operations form:

1 + 2 + 4 + 8 + ... + (n/2)

This geometric progression sums close to `n`.

So total work:

* `O(n)` copying
* `O(n)` assignments

This gives amortized:

`O(1)` append.

I compared multiple growth factors and selected **2x growth** because it reduces regrow frequency and keeps analysis simple.

For shrinking, I considered:

**0.5 * capacity**

but this creates oscillation between grow and shrink.

To prevent this, I selected:

**0.25 * capacity**

to create a stable buffer.

For initial capacity:

I chose:

**0**

so no memory is allocated unless the array is used.

On first insertion:

capacity becomes **10**

I selected 10 over 8 to reduce early regrows and improve small dataset performance.

**Outcome:**
Completed the first `DynamicArray` design proposal.

Finalized:

* growth factor = 2
* shrink threshold = 0.25
* initial capacity = 0
* first growth = 10

This proposal became the implementation foundation.
