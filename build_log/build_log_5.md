## Build Log Entry 2

**Date:** June 30, 2026
**Duration:** 4 hours

**Goal:**
Fix `DynamicArray` so it works for non-primitive types like `string` and user-defined class objects.

**Problem Encountered:**
My dynamic array worked for primitive types but failed for `string` and class objects. The issue was that I was treating object memory like raw bytes, which caused incorrect behavior. After debugging with AI assistance, I found that object constructors and destructors were not being respected.

While solving this, I also realized my resize/regrow implementation using `realloc()` was unsafe for non-primitive objects because `realloc()` only moves memory and does not preserve object lifecycle.

**What I Tried:**
I spent about 1 hour understanding why object types behave differently from primitive types. I learned:

* Primitive values can be copied directly.
* Objects require constructor calls and proper destruction.
* `realloc()` is unsafe for objects because it bypasses constructors/destructors.

To solve this:

* I changed the array to properly construct objects of type `T`.
* I added explicit destruction before deallocation.
* I replaced `realloc()`-based regrow/shrink logic with `malloc()` + placement new.

**Outcome:**
The dynamic array now supports both primitive and non-primitive types. I now understand object lifecycle management much better and why manual construction/destruction is important in generic container implementation.
