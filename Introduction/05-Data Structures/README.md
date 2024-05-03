# Using The Computers Memory in Interesting Ways

An abstract data type is a implemented by a programmer, for example __queues__. As simple as a queue in the normal well, they offer a __FIFO__ or first in first out approach. You can usually enqueu and deque which is akin to entering and exiting a queue. You can use an array to define a queue.

```c
const int CAPACITY = 50;

typedef struct {
    person people[CAPACITY];
    int size;
} queue;
```
