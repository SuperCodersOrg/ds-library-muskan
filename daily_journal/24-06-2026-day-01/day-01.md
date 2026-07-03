# Day 1 Journal

**Date:** 24 June 2026

---

## Section 1 — Specific Bug / Confusion

The biggest confusion today was understanding why append operation becomes amortized `O(1)` even though regrow sometimes takes `O(n)`.

Initially, I thought every regrow would make insertion expensive.

After observing the copy pattern:

1 + 2 + 4 + 8 + ... + (n/2)

I recognized it as a geometric progression and understood that total copying across `n` insertions remains bounded by `O(n)`.

This made average insertion amortized `O(1)`.

I also compared growth factor `1.5` and found it causes more total copy operations compared to factor `2`.

---

## Section 2 — Failed Attempt / Wrong Assumption

My first assumption was that shrinking at `0.5 * capacity` would be efficient.

After simulating insert-remove behavior, I found this causes oscillation:

* array grows at full capacity
* one removal triggers shrink
* one insertion triggers grow again

This repeated grow-shrink cycle creates unnecessary reallocations.

To solve this, I changed shrink threshold to `0.25 * capacity`.

I also initially considered capacity `8`, but after practical reasoning, selected `10` to reduce early regrows.

---

## Section 3 — Memory Diagram

Created and stored the following diagrams:

**Constructor**

* `dynamic_array_constructor.png.png`

**Get**

* `dynamic_array_get.png`

**Insert**

* `dynamic_array_inser_best_case.png`
* `dynamic_array_insert_average_case.png`
* `dynamic_array_insert_worst_case.png`

**Remove**

* `dynamic_array_remove_best_case.png`
* `dynamic_array_remove_average_case.png`
* `dynamic_array_worst_case.png`

Stored at:

```text
docs/design_proposals/dynamic_array/v1/images/design_proposal_v1_images/
```

These diagrams represent the initial memory model where:

* `DynamicArray` object itself was stored on heap
* object stores:

  * `size`
  * `capacity`
  * `arr` pointer
* `arr` points to another heap block where elements are stored

These diagrams helped visualize:

* append growth behavior
* insert shifting behavior
* remove shifting behavior
* direct access in get()

This initial model was later revised during implementation after understanding stack-based object storage.

---

## Section 4 — Code Reference

**Commit Hash 1:**
f4e8adf5f172ae49d0932811a7d7d2465d7b177e

**Purpose:**
Initial design proposal creation.

**File:**
design_proposal.md

**Lines:**
1–891

---

**Commit Hash 2:**
c5d9a3d8e24e4119efaa24fafc729a55c4bcd0e9

**Purpose:**
Added memory diagrams to proposal.

**File:**
design_proposal.md + image assets

---

## Section 5 — Learning Reflection

Today changed how I think about dynamic arrays from a performance perspective.

Before this, I only knew arrays grow when full, but I did not understand the mathematical reason why append remains efficient.

I learned:

* amortized analysis through geometric progression
* why growth factor matters
* why shrink thresholds affect stability
* how poor shrink design creates oscillation
* how initial capacity impacts practical performance

This was the first time I connected mathematical analysis directly to container design decisions.
