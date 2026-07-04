# **SuperCoders Project 01**

## **Design Proposal – LinkedList**

# **Project Overview**

In this project, I am going to build a **LinkedList from scratch in C++** without using STL so I can understand how pointers, heap memory, and node connections work internally.

In DynamicArray, elements are stored in contiguous memory. But in LinkedList, nodes are stored separately and connected using pointers.

This will help me understand:

* heap memory allocation
* pointers
* traversal
* node insertion/deletion
* deep copy
* Rule of Three
* memory safety

---

# **Why do we need LinkedList?**

As we know, arrays have some limitations.

Consider:

```cpp
int arr[5];
```

Memory:

```text
STACK MEMORY

arr:
+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |
+----+----+----+----+----+
```

---

# **1. Fixed Size Problem**

Suppose:

```cpp
arr = {10,20,30,40,50}
```

Now we want to insert `60`.

But array size is full.

So:

```text
Cannot grow
```

This is fixed-size limitation.

---

# **2. Insertion Cost**

Suppose:

```text
arr = {10,20,30,40,50}
```

Insert `15` at index `1`.

Before:

```text
{10,20,30,40,50}
```

After:

```text
{10,15,20,30,40,50}
```

Need shifting:

```text
20 -> right
30 -> right
40 -> right
50 -> right
```

Total shifts = 4

Time = O(n)

---

# **3. Deletion Cost**

Suppose:

```text
{10,20,30,40,50}
```

Delete `20`.

Need shifting:

```text
30 -> left
40 -> left
50 -> left
```

Again O(n)

---

# **Conclusion**

To solve:

* fixed size
* costly insertion
* costly deletion

we use LinkedList.

---

# **What is LinkedList?**

LinkedList stores elements in nodes.

Each node has:

1. data
2. pointer to next node

Unlike arrays:

Nodes are not contiguous.

Example:

```text
[10|*] -> [20|*] -> [30|null]
```

---

# **Node Structure**

```cpp
class Node{
public:
    int data;
    Node* next;
};
```

Memory:

```text
Node:
+--------+--------+
| data   | next   |
+--------+--------+
```

Example:

```text
+----+-------+
| 10 | 5008  |
+----+-------+
```

Means next node is at address 5008.

---

# **Where object stores? Stack or Heap?**

When user creates:

```cpp
LinkedList list;
```

Object is stored in stack.

Example:

```text
STACK MEMORY

+----------------+
| head = 5000    |
| tail = 5016    |
| size = 3       |
+----------------+
```

This object only stores:

* head pointer
* tail pointer
* size

Actual nodes are stored in heap.

---

# **Why nodes in heap?**

Because nodes are dynamic.

Suppose:

```cpp
list.insertBack(10);
list.insertBack(20);
list.insertBack(30);
```

Memory:

```text
STACK

list:
head = 5000
tail = 5032
size = 3


HEAP

5000 -> [10|5016]
5016 -> [20|5032]
5032 -> [30|null]
```

Why heap?

Because heap allows runtime allocation.

If nodes were stack allocated:

```cpp
Node n1;
```

they would die after scope ends.

LinkedList would break.

---

# **Class Structure**

```cpp
class LinkedList{
private:
    Node* head;
    Node* tail;
    int currentSize;

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    void insertFront(int value);
    void insertBack(int value);
    void insert(int index, int value);

    void deleteFront();
    void deleteBack();
    void removeAt(int index);
    bool removeValue(int value);

    int get(int index) const;
    void set(int index,int value);

    bool search(int value) const;
    int find(int value) const;

    int size() const;
    bool isEmpty() const;

    void clear();
    void print() const;
    void reverse();
};
```

---

# **Default Constructor**

```cpp
LinkedList();
```

Initial values:

```cpp
head=nullptr;
tail=nullptr;
currentSize=0;
```

Memory:

```text
STACK

head -> nullptr
tail -> nullptr
size = 0
```

No heap memory yet.

Why?

Because user may create object and never use it.

Same logic as DynamicArray capacity=0.

Avoid memory waste.

---

# **Rule of Three**

Since nodes use heap memory, we need:

```cpp
~LinkedList();
LinkedList(const LinkedList&);
LinkedList& operator=(const LinkedList&);
```

---

# **Why Rule of Three?**

Suppose:

```cpp
LinkedList l1;
l1.insertBack(10);
l1.insertBack(20);

LinkedList l2 = l1;
```

Shallow copy:

```text
l1.head ----+
            |
l2.head ----+
```

Both point same memory.

Danger:

If l1 destructor runs:

```text
delete nodes
```

l2 gets dangling pointer.

If l2 destructor runs:

DOUBLE FREE.

Crash.

So we need deep copy.

---

# **Destructor**

Deletes all nodes.

Before:

```text
head -> [10] -> [20] -> [30]
```

Delete:

Step 1:

```text
temp=10
head=20
delete temp
```

Step 2:

```text
temp=20
head=30
delete temp
```

Step 3:

```text
temp=30
head=null
delete temp
```

Final:

```text
head=null
tail=null
size=0
```

---

Time Complexity:

Best = O(n)
Average = O(n)
Worst = O(n)

Why?

Because all nodes must be deleted.

---

# **insertFront(int value)**

Creates new node at front.

Before:

```text
head -> [20] -> [30]
```

Insert 10.

Step:

```cpp
newNode->next=head;
head=newNode;
```

After:

```text
head -> [10] -> [20] -> [30]
```

---

Best = O(1)

Why?

Direct head access.

No traversal.

Average = O(1)

Worst = O(1)

Always constant.

---

# **insertBack(int value)**

Before:

```text
head -> [10] -> [20]
tail ------------^
```

Insert 30.

Step:

```cpp
tail->next=newNode;
tail=newNode;
```

After:

```text
head -> [10] -> [20] -> [30]
tail --------------------^
```

Best = O(1)

Why?

Tail gives direct last node.

Without tail:

Need traversal.

Would be O(n)

---

# **insert(index,value)**

Suppose:

```text
[10] -> [30] -> [40]
```

Insert(1,20)

Need reach index-1.

Traversal:

```text
10
```

Then:

```cpp
newNode->next=temp->next;
temp->next=newNode;
```

After:

```text
[10] -> [20] -> [30] -> [40]
```

---

Best case:

Insert at front:

```text
insert(0,5)
```

O(1)

---

Average case:

Middle.

Suppose n=10.

Need travel n/2.

O(n/2)

But asymptotically:

O(n)

---

Worst case:

Insert at end without tail usage.

Need full traversal.

O(n)

---

# **deleteFront()**

Before:

```text
[10] -> [20] -> [30]
```

Step:

```cpp
temp=head;
head=head->next;
delete temp;
```

After:

```text
[20] -> [30]
```

Best O(1)

Average O(1)

Worst O(1)

No traversal.

---

# **deleteBack()**

Before:

```text
[10] -> [20] -> [30]
```

Need second last node.

Traversal:

```text
10 -> 20
```

Delete:

```text
[10] -> [20]
```

Best:

If one node:

O(1)

Average:

O(n)

Worst:

O(n)

Because traversal.

---

# **search(value)**

Suppose:

```text
[10] -> [20] -> [30] -> [40]
```

search(10)

Best:

Found first.

O(1)

---

search(30)

Average:

Travel 2 nodes.

O(n/2)

Asymptotically O(n)

---

search(40)

Worst:

Travel all.

O(n)

---

# **get(index)**

Need traversal.

Example:

```text
[10] -> [20] -> [30]
```

get(2)

Traverse:

10 -> 20 -> 30

Return 30.

Best:

get(0)

O(1)

Average:

middle

O(n)

Worst:

end

O(n)

---

# **reverse()**

Before:

```text
10 -> 20 -> 30 -> 40
```

Use:

```cpp
prev
curr
next
```

Step 1:

```text
prev=null
curr=10
next=20
```

Step 2:

Reverse link.

```text
10 -> null
```

Step 3:

Move forward.

Continue.

Final:

```text
40 -> 30 -> 20 -> 10
```

Time:

Best O(n)

Average O(n)

Worst O(n)

Need visit all.

Space:

O(1)

---

# **Time Complexity Table**

| Method      | Complexity |
| ----------- | ---------- |
| insertFront | O(1)       |
| insertBack  | O(1)       |
| insert      | O(n)       |
| deleteFront | O(1)       |
| deleteBack  | O(n)       |
| removeAt    | O(n)       |
| removeValue | O(n)       |
| get         | O(n)       |
| set         | O(n)       |
| search      | O(n)       |
| find        | O(n)       |
| size        | O(1)       |
| isEmpty     | O(1)       |
| clear       | O(n)       |
| print       | O(n)       |
| reverse     | O(n)       |

---

# **Final Design Decisions**

Why head?

Without head traversal impossible.

Why tail?

Makes insertBack O(1)

Why size?

Makes size() O(1)

Without size variable:

Need traversal.

O(n)

---

# **Conclusion**

LinkedList helps understand:

* pointer manipulation
* dynamic memory
* heap allocation
* traversal
* deep copy
* Rule of Three
* memory safety

This is important because HashMap collision handling will use LinkedList.
