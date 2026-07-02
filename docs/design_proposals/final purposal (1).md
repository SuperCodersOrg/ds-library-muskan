# **SuperCoders Project 01**
## **Design Proposal – Collections Library and Redis Lite**
### **Project Overview**
In this project, I am going to build a complete **data structures library from scratch in C++** without using STL containers so I can understand how memory and data are managed internally in real systems. I will implement a **DynamicArray**, where I will manually handle heap memory allocation, resizing, copying, and deallocation; a **LinkedList**, where I will create and manage nodes using pointers for insertion, deletion, and traversal; and a **HashMap**, where I will design my own hash function, handle collisions, maintain load factor, and perform rehashing when needed. On top of these data structures, I will build **Redis Lite**, a command-line key-value storage system powered by my HashMap to support operations like SET, GET, DEL, and EXISTS. Throughout this project, I will focus on **manual memory management** using `new`, `delete`, `new[]`, and `delete[]`, implement the **Rule of Three** (destructor, copy constructor, and assignment operator) for safe deep copying, and use **Valgrind** to detect memory leaks, dangling pointers, and double frees to ensure the library is memory-safe, efficient, and reliable.

**Dynamic Array**
**Why do we need a Dynamic Array?**

As we know, in a static array, before using it we need to specify its size, and we cannot change its size afterward.

**For example:**

int arr[5];

Now, at compile time, memory to store 5 integers is allocated. We can store only 5 integers in it.

-----
## **1. Fixed Size Limitation**
Consider the above array:

arr = {10, 20, 30, 40, 50};

Now, if we want to store `60` in this array, we cannot do it because the stack memory is allocated only for 5 integer elements. Even if we try to store `60` at index 5, it will give an **array index out of bounds error**.

-----
## **2. Memory Wastage Problem**
Consider the same array:

arr = {1, 2};

Here, memory allocated in the stack for this array is for 5 integers, but we are storing only 2 integer elements. So the remaining memory for 3 integer elements gets wasted.

Now consider a case where the user declares an array with size 1000 but stores only 10 elements. Then the remaining memory for 990 elements is wasted.

-----
## **3. To Use Heap Memory Instead of Stack Memory**
As we know, static arrays are stored in stack memory, and stack memory is limited. So if the user allocates a very large array, it may cause a **stack overflow** issue.

For example, I tried to declare an array with size 261224; it works, but beyond that, it may fail depending on system limits.

-----
## **Conclusion**
To overcome all these limitations—fixed size, memory wastage, and stack overflow—we use **dynamic arrays**, which are allocated in heap memory and can be resized during runtime.
### **What is a Dynamic Array?**
A dynamic array is a data structure that stores elements in **contiguous memory** (allocated on the heap instead of the stack). Unlike a static array, its size can be increased or decreased at runtime according to requirements.

-----
### **What am I going to create?**
I am going to create a **DynamicArray class** that implements a resizable array. It will maintain a default **capacity** (the maximum number of elements that can be stored before resizing) and a **size** (the number of elements currently stored in the array).

When a user inserts an element and the capacity is exhausted (i.e., when `size == capacity`), the array will automatically increase its capacity using a **growth factor** (for example, doubling or tripling the current capacity). We will discuss growth strategies later.

Similarly, if after multiple deletions the number of elements becomes much smaller compared to the capacity, the array can reduce its capacity using a **shrink factor** (for example, 0.5 or 0.25) to avoid memory wastage. We will also discuss shrinking strategies later.

-----
### **Core terms related to Dynamic Array:**
**Size:**
The number of elements currently stored in the dynamic array.

**Capacity:**
The maximum number of elements the array can hold before resizing is required.

**Growth factor:**
A multiplier that defines how much the capacity increases when the array becomes full.

**Shrink factor:**
A multiplier that defines how much the capacity decreases when the array has significantly fewer elements than its capacity.

class DynamicArray {
private:
int\* arr;          // pointer to heap memory
int currentSize;   // number of elements stored
int currentCapacity; // total allocated capacity

    // helper methods  
    void resize(int newCapacity);  
    void shrink();  
    void grow();
public:
// Constructors
DynamicArray();                    // default constructor
DynamicArray(int initialCapacity); // user-defined capacity

    // Rule of Three  
    \~DynamicArray();                              // destructor  
    DynamicArray(const DynamicArray& other);     // copy constructor  
    DynamicArray& operator=(const DynamicArray& other); // copy assignment

    // Core methods  
    void append(int value);  
    void insert(int index, int value);  
    void remove(int index);  
    int get(int index) const;

    // Utility methods  
    int size() const;  
    int capacity() const;  
    bool isEmpty() const;  
};
**How my dynamic array got created with default constructor and paramettarized constructor**
![image1]
### **Default values:**
**Size:** 0
The size is initialized to 0 because it keeps track of the number of elements currently stored in the array. It increases when elements are inserted into the dynamic array.

**Capacity:** (assuming growth factor = 2)

-----
### **User-defined capacity:**
If the user provides the size of the dynamic array at the time of declaration, I will use it as the initial capacity. In that case, since the user explicitly specifies the required memory, it reduces the number of resizes and avoids unnecessary memory allocation to some extent.

-----
### **Design choices:**
**Capacity = 8:**
Initially, I considered using 8 as the default capacity. With this choice, the number of resizes is reduced because the first resize would only happen when inserting the 9th element, increasing the capacity from 8 to 16.

-----
**Capacity = 10:**
Then I considered using 10 as the initial capacity. The advantage I noticed is that many use cases often require storing around 10 elements. In such cases, there is no need for resizing. However, if we use 8 as the initial capacity, resizing would be required, increasing it to 16 and potentially wasting memory for the extra 6 elements (for example, in case of integers).

-----
**Capacity = 0:**
Then I studied how Java handles dynamic arrays and learned that it often starts with a capacity of 0. This approach helps avoid memory waste when a user declares a dynamic array but does not use it. In such cases, allocating space for 8 or 10 elements would waste memory unnecessarily. Therefore, I decided to start with an initial capacity of 0 and allocate memory only when the first element is inserted. At that point, the capacity can be increased (for example, to 10). This reduces the risk of memory wastage due to unused dynamic arrays.

-----
### **Final decision:**
Finally, I will use **0 as the initial capacity** if the user does not provide any value. When the first element is inserted, I will allocate memory for 10 elements. After that, resizing will follow the growth factor strategy. If the user provides an initial capacity, I will use that value as the starting capacity.

**Growth Factor (Corrected Version)**
### **Growth factor:**
At first, I thought of **2 as the growth factor** because in that case, the time complexity for inserting **n elements** comes out to be **2n**, which is considered **O(n)**. So, insertion of one element becomes **amortized O(1)**.

Now, let’s understand why it becomes **2n**.

-----
### **Example:**
Consider:

* Capacity = 1
* Size = 0
-----
Insert 10 → size becomes 1
Time complexity for insert(10) = 1

-----
Insert 20 → now size(1) == capacity(1)
We need to **regrow**, so we copy 1 element and insert 1

Time complexity for insert(20) = 1 (copy) + 1 (insert)

-----
Insert 30 → size = 2, capacity = 2
We need to regrow capacity to 4, so we copy 2 elements and insert 1

Time complexity for insert(30) = 2 + 1

-----
Insert 40 → size (3) < capacity (4), no regrow
Time complexity for insert(40) = 1

-----
Insert 50 → size (4) = capacity (4), regrow to 8
We copy 4 elements and insert 1

Time complexity for insert(50) = 4 + 1

-----
...
Insert 90

Time complexity for insert(50) = 8 + 1

→ similarly con

-----
### **Observation:**
Here, for inserting elements, the copy operations form a **GP series**:

1 + 2 + 4 + 8 + … + 2^(k−1)

Why k−1? Because if we insert 16 elements, we only copy up to 8 elements when inserting the 9th element, after which it regrows to 16.

-----
### **GP Sum:**
Using GP formula:

a(r^n − 1) / (r − 1)

Here:

* a = 1
* r = 2

So,

Sum = (2^k − 1) / (2 − 1) = 2^k − 1

-----
Now, as we know:

2^k ≈ n (number of elements inserted)

So total time:

Time for n inserts = copy + insert
= (n − 1) + n
= 2n − 1
= **O(2n)** = **O(n)**

-----
### **Conclusion:**
That is why when the growth factor is **2**, the amortized time complexity for insertion is **O(1)**.

-----
## **🔁 Growth factor = 1.5**
Then I considered **1.5 as the growth factor**.

From observation:

* Time complexity becomes around **3n**
* Copy cost becomes around **2n**
-----
### **GP Series:**
1 + 1.5 + 1.5² + ... + 1.5^(n−1)

Sum of GP:

= (1.5^n − 1) / (1.5 − 1)
= (1.5^n − 1) / 0.5
= 2(1.5^n − 1)

≈ **2n**

So:

Time complexity for n insertions = copy + insert
= 2n + n
= **3n**

-----
### **Memory comparison:**
Suppose we need to store 100 elements.

-----
### **Growth by 2:**
10 → 20 → 40 → 80 → 160

* Resizes: 4
* Copies: 10 + 20 + 40 + 80 = **150 copies**
-----
### **Growth by 1.5:**
10 → 15 → 22 → 33 → 49 → 73 → 109

* Resizes: 6
* Copies: 10 + 15 + 22 + 33 + 49 + 73 = **202 copies**
-----
### **Observation:**
* Growth factor **1.5 → more copies (more CPU work)**
* Growth factor **2 → less copies but more wasted memory**

But in 1.5 growth:

* less memory waste (~9 unused slots)

In 2 growth:

* more memory waste (~60 unused slots)
-----
### **Final decision:**
As per my design, I am going to use **2x growth factor**, because:

* Memory is cheaper nowadays
* CPU operations (copying elements) are more expensive
* 1.5 increases number of copies, which increases CPU work
## **Shrink Factor**
### **Shrink factor = 1/2**
At first, I thought of reducing the capacity of the array by **1/2**, but I observed that it creates an **oscillation pattern** between grow and shrink.

Consider:

* **Capacity = 16**
* **Size = 9**
  {10,20,30,40,50,60,70,80,90,\_,\_,\_,\_,\_,\_,\_}

Here, if the shrink condition is:

if(size <= capacity/2)

then whenever the size becomes **n/2** or less, I reduce the capacity by half.

Suppose:

`remove(8)` → element **90** is deleted

Now:

* Size = 8
* Capacity = 16

Since size = n/2, we shrink.

New array:

{10,20,30,40,50,60,70,80}

* Size = 8
* Capacity = 8

Now if the user inserts **90** again (or any new element), we immediately need to regrow.

After inserting 90:

{10,20,30,40,50,60,70,80,90,\_,\_,\_,\_,\_,\_,\_}

Capacity becomes 16 again.

Suppose we insert one more element:

{10,20,30,40,50,60,70,80,90,100,\_,\_,\_,\_,\_,\_}

Now if we remove two elements again:

* `remove(9)`
* `remove(8)`

Size becomes 8 again.

Since size = n/2, we shrink again:

{10,20,30,40,50,60,70,80}

Capacity becomes 8.
### **Problem:**
If we use **n/2** as the shrink threshold, we leave **no extra room** after shrinking.

That means even one new insertion may force a regrow again.

So the array keeps oscillating:

**shrink → grow → shrink → grow**

This is inefficient.

**Note:** Shrinking does not happen automatically by itself; it is triggered manually based on our condition.

-----
## **Shrink factor = 1/4**
Then I thought of using **1/4** as the shrink threshold.

I found it much better because if we shrink when the size becomes **n/4**, we still have enough free space left after shrinking.

Consider again:

* Capacity = 16
* Size = 9
  {10,20,30,40,50,60,70,80,90,\_,\_,\_,\_,\_,\_,\_}

Now shrinking will happen only when:

if(size <= capacity/4)

That means when size becomes **4**.

Suppose we remove:

* `remove(8)`
* `remove(7)`
* `remove(6)`
* `remove(5)`
* `remove(4)`

Now the array becomes:

{10,20,30,40,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_}

* Size = 4
* Capacity = 16

Since size = n/4, we shrink the capacity by half.

New array:

{10,20,30,40,\_,\_,\_,\_}

* Size = 4
* Capacity = 8

Now we still have **4 empty spaces** available.

That means we can insert **50% more elements** before regrowing again.

-----
## **Final Decision**
I decided to use **1/4 as the shrink threshold** because:

* it avoids oscillation between grow and shrink
* it reduces unnecessary resize operations
* after shrinking, there is still enough space available for future insertions

In the case of **1/2**, after shrinking there is no free space left, so regrowing may happen immediately after the next insertion. That makes it inefficient.

Methods of dynamic array
## **append(T value):**
The `append()` method inserts an element at the **end** of the dynamic array.
### **Procedure:**
We first check if:

size < capacity

Then we store the element directly using `size` as the index.

Else, if:

size == capacity

then:

* we first allocate a new array with size `2 * capacity`
* then we copy the previous array values into the new array
* then we make the dynamic array object pointer, which was pointing to the previous dynamic array in heap memory, point to the new dynamic array in heap memory,then we store the value at index equal to size.
-----
## **Time Complexity**
### **Best case: O(1)**
When:

size < capacity

We just access `size` as the index and store the value there.

For example:

arr->{10,20,30,40,50,60,70,80,90,\_} size=9 capacity=10

append(100)

Since:

size(9) < capacity(10)

we directly do:

p.arr[size] = 100

arr->{10,20,30,40,50,60,70,80,90,100}

Only one insertion operation is performed, so time complexity is **O(1)**.

![image2]

-----
### **Average case: O(1) amortized**
As we know, to insert `n` elements the total time complexity becomes `2n`.

So, on average:

2n / n = 2

Some insertions are expensive (when resizing happens) and some are cheap (normal insertions), so on average the cost of one append remains constant.

That is why the average time complexity is **O(1) amortized**.

**Correction:**
You wrote `o(2)`. It should be **O(1)**, not `o(2)`.

-----
### **Worst case: O(n)**
When:

size == capacity

we need to:

* copy `n` elements
* insert one new element

So the total time complexity is **O(n)**.

Example:

append(110)

New memory is allocated with capacity `20`, and the previous array's `10` elements are copied.

Allocate a new array with capacity 20

newarr->{\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_}

Copy previous array arr values in new array newarr

newarr->{10,20,30,40,50,60,70,80,90,100,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_}

Deallocate previous array arr and make array arr point to newarr

newarr->{10,20,30,40,50,60,70,80,90,100,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_}

Now insert the value using size as index

newarr->{10,20,30,40,50,60,70,80,90,100,110,\_,\_,\_,\_,\_,\_,\_,\_,\_}

Time taken:

O(n) for copying + O(1) for insertion = O(n)

![image3]

![image4]
## **`get(int index):`**
This method returns the value stored at the given index.

For Example:

arr->{10,20,30,40,50,60,70,80,90,100,110,\_,\_,\_,\_,\_,\_,\_,\_,\_}

arr.get(2)

It returns **30** because it is stored at index `2`.

![image5]

-----
### **How is it able to access the element using an index?**
It uses **pointer arithmetic**.

As you already know, the variable `arr` stores the **base address** of the dynamic array.

When you do:

arr.get(i)

internally it calculates:

base address + (i \* sizeof(T))

Here:

* `T` is the template type (the type of data stored in the dynamic array)

This calculation gives the address of the element at that index.

-----
Example:

dmobject.arr->{10	,20	,30	,40	,50	,60	,70	,80	,......}

    	   3000   3004 3008 3012 3016 3020 3024 3028
Suppose:

arr.get(2)

Here:

* Base address = `3000`
* `sizeof(int) = 4`

So the address calculation becomes:

3000 + (2 × 4) = 3008

At address `3008`, the value stored is:

30

So it returns `30`.

-----
## **Time Complexity**
### **Best Case: O(1)**
If we access the first element:

arr.get(0)

It directly calculates the address and returns the value.

Only one operation is needed.

-----
### **Average Case: O(1)**
If we access any middle element:

arr.get(2)

It still directly calculates the address.

No traversal is needed.

-----
### **Worst Case: O(1)**
If we access the last element:

arr.get(size-1)

It also directly calculates the address.

Even for the last element, no extra work is needed.

-----
### **Conclusion:**
In every case (first, middle, or last), the time complexity remains **O(1)** because the element is accessed in constant time using direct address calculation.

This is one of the biggest advantages of dynamic arrays.
## **`insert(int index, T value):`**
This method inserts an element at a specific index in the dynamic array.

-----
## **How we do it:**
1. First, check if:

index<=size

     2\.	First, check if:
size == capacity

If yes, then we need to regrow first; otherwise, move to the next step.

    3\. Then check if an element is already present at that index.
* If yes, then we need to shift the elements from **size-1** to that index one step to the right so that space is created for the new value.
* Otherwise, if the index is equal to `size`, we can directly store the value there.
-----
# **Time Complexity**
Consider:

arr—>{10,20,30,40,50,60,70,80,\_,\_}

-----
## **Best case: O(1)**
When the element is inserted at the end and:

size < capacity

Example:

arr.insert(8,90)

Here:

* size = 8
* capacity = 10
* index = size

So no shifting is needed.

arr->{10,20,30,40,50,60,70,80,90,\_}

Only one insertion.

Time complexity = **O(1)**

![image6]

-----
## **Average case: O(n)**
When the element is inserted in middle of the array.

Example:

insert(5,55)

Current:

arr->{10,20,30,40,50,60,70,80,90,\_}

Since index `5` is occupied, we need to shift elements from left to the right.

Shift from `size(9)` to `index+1(6) with arr[i]=arr[i-1]`.

After shifting:

arr—>{10,20,30,40,50,60,60,70,80,90}

Now store `55` at index `5`:

arr—>{10,20,30,40,50,55,60,70,80,90}

Here we shift nearly `n/2` elements on average plus one insertion.

So:

O(n/2 + 1) ≈ O(n)

![image7]

-----
## **Worst case: O(n) (not O(n²))**
This is important.

You wrote **O(n²)** — this is incorrect.

Why?

Because:

* copying during regrow = O(n)
* shifting = O(n)

Total:

O(n) + O(n) = O(2n) = O(n)

Not O(n²).

-----
Example:

insert(0,1)

Here:

* size = 10
* capacity = 10

So first regrow.

Current:

arr—>{10,20,30,40,50,55,60,70,80,90}

Create new array with `2 * capacity`

newarr->{\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_}

Copy old array:

newarr->{10,20,30,40,50,55,60,70,80,90,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_}

Deallocate previous array and make `arr` point to new array:

arr—>{10,20,30,40,50,55,60,70,80,90,\_,\_,\_,\_,\_,\_,\_,\_,\_,\_}

Now shift from `size-1` to `0`:

arr—>{10,10,20,30,40,50,55,60,70,80,90,\_,\_,\_,\_,\_,\_,\_,\_,\_}

Now insert 1 at index 0:

arr—>{1,10,20,30,40,50,55,60,70,80,90,\_,\_,\_,\_,\_,\_,\_,\_,\_}

Time:

* copy `n`
* shift `n`
* insert `1`

Total: o(n+n) o(2n)

O(n)

![image8]

![image9]
## **`void remove(int index):`**
This method removes the element at the specified index.
### **How it works:**
First, go to that index using **pointer arithmetic**.

If an element exists at that location, then shift all elements from **right to left** (not left to right) starting from that index up to `size - 2`.

The shifting happens like:

arr[i] = arr[i+1]

After shifting, reduce the size by one:

size--

-----
Consider:

arr—>{5,10,20,30,40,\_,\_,\_}

remove(2)

Element `20` will be removed.

Shift:

arr[i] = arr[i+1]

After shifting:

arr—>{5,10,30,40,40,\_,\_,\_}

Now reduce size:

size--

Now size becomes `4`.

The extra `40` at the end is ignored because it is outside the valid size.

So logically the array becomes:

arr—>{5,10,30,40,\_,\_,\_,\_}

-----
If:

index >= size

then the element does not exist.

Give error:

Invalid index

-----
# **Time Complexity:**
-----
## **Best case O(1)**
When the element is removed from the end.

For example:

remove(9)

arr->{10,20,30,40,50,60,70,80,90,100}

No shifting required.

Just reduce size by one.

Now:

size = 9

Time complexity = **O(1)**

![image10]

-----
## **Average case O(n)**
When the element is removed from the middle.

Example:

arr->{10,20,30,40,50,60,70,80,90,\_}

remove(4)

Shift:

arr[i] = arr[i+1]

from `i` to `size-2`

After shifting:

arr->{10,20,30,40,60,70,80,90,\_,\_}

Reduce size:

Now size becomes `8`

Logical array:

arr->{10,20,30,40,60,70,80,90,\_,\_}

Here nearly `n/2` elements shift.

So:

O(n/2) ≈ O(n)

Z

![image11]

-----
## **Worst case O(n)**
When we remove the first element.

All elements need to shift from index `0` to `size-2`.

Example:

remove(0)

Initial:

arr->{10,20,30,40,60,70,80,90,\_,\_}

After shifting:

arr->{20,30,40,60,70,80,90,\_,\_,\_}

Reduce size:

Now size becomes `7`

Logical array:

arr->{20,30,40,60,70,80,90,\_,\_,\_}

Time complexity = **O(n)**

![image12]

[image1]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.001.png
[image2]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.002.png
[image3]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.003.png
[image4]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.004.png
[image5]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.005.png
[image6]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.006.png
[image7]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.007.png
[image8]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.008.png
[image9]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.009.png
[image10]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.010.png
[image11]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.011.png
[image12]: Aspose.Words.b5008f1f-0876-473e-b507-7c725cbbbc33.012.png
