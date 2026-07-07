## Build Log – Session 4

**Date:** July 5, 2026

**Duration:** 2 Hours 30 Minutes

### Goal

Prepare the design for the LinkedList implementation by understanding its memory layout, deciding on the internal node representation, finalizing the public API, and planning how the LinkedList will be integrated into the HashMap for collision handling.

### Problem Encountered

Before starting the implementation, I wanted to understand several design decisions rather than writing code immediately. My main questions were:

- How does a LinkedList store multiple values in memory?
- Why is a `Node` represented using a `struct` instead of a `class`?
- How will a LinkedList be used inside the HashMap?
- How will multiple key-value pairs be stored when two keys produce the same hash value?

### What I Tried

I studied the memory organization of a singly linked list and compared it with the DynamicArray implementation I had already completed.

I finalized the following design decisions:

- Each element will be stored in a separate dynamically allocated `Node`.
- Every `Node` will contain the stored data and a pointer to the next node.
- The LinkedList will maintain `head`, `tail`, and `size` to efficiently manage the list.
- I chose to implement `Node` as a `struct` because it is an internal helper type with simple data members (`data` and `next`). Since the `Node` is private inside the `LinkList` class, encapsulation is still maintained while keeping the implementation straightforward.
- I designed the complete public interface before starting implementation, including insertion, deletion, searching, access, update, copy constructor, assignment operator, and utility methods.

I also explored how the LinkedList would be used for **HashMap collision handling** through **separate chaining**.

The design consists of:

- A HashMap containing an array of buckets.
- Each bucket pointing to the head of a LinkedList.
- Every LinkedList node storing one key-value pair.
- If multiple keys generate the same hash index, new entries are added to the LinkedList instead of replacing existing data.
- Lookup and deletion will traverse only the LinkedList belonging to the corresponding bucket.

### Outcome

I completed the overall LinkedList design, finalized its public API, and gained a clear understanding of how it will integrate with the HashMap. This planning established the memory layout, node structure, and collision-handling strategy before implementation began, making the subsequent coding phase more organized and easier to follow.