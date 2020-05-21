# Data-Structures

Generic type implementation of data structure.

**Hash Table:**\
Implemented as a dynamic array, hash table base dimension starting of a prime number.\
Double hashing function: h(k) = h(k) + i  ; i>=0\
when:  
  - h(k) = floor(m * frac(a * k))
  - a = (sqrt(5)-1) / 2 = 0.61803...  // Good dispersion
  - m = base dimension
  - frac(x) = x - floor(x)
  
Functions complexity:
- rehash: O(n)
- insert: O(1) average on the input
- remove: O(1) average on the input
- member: O(1) average on the input


**Min Heap:**\
Implemented as an array, starting of index 1.

Functions complexity:
- Make heap(c'tor): O(n)
- siftDown: O(log(n))
- siftUp: O(log(n))
- siftHeap: O(n)
- insert: O(log(n))
- deleteMin: O(log(n))
- decElement: O(log(n))


**AVL tree:**\
Each AVL tree node has a generic data and generic key,\
if your key is other than of type int, you need to implement a compare function.

Functions complexity:
- rotateLeft: O(1)
- rotateRight: O(1)
- rotateLeftRight: O(1)
- rotateRightLeft: O(1)
- insert: O(log(n))
- remove: O(log(n))
- reBalance: O(1)
- isKeyExists: O(log(n))


**Stack:**\
Implemented as an array with max size.

Functions complexity:
- push: O(1)
- pop: O(1)
- getTop: O(1)


**LinkedList:**\
Its a single linked list.

Functions complexity:
- addNode: O(1)
- removeNodeByIndex: O(n)
- getNodeByIndex: O(n)


**Queue:**\
Implemented as a single linked list.

Functions complexity:
- enqueue: O(1)
- dequeue: O(1)
