# Using The Computers Memory in Interesting Ways

An abstract data type is a implemented by a programmer, for example __queues__. As simple as a queue in the normal well, they offer a __FIFO__ or first in first out approach. You can usually enqueu and deque which is akin to entering and exiting a queue. You can use an array to define a queue.

```c
const int CAPACITY = 50;

typedef struct {
    person people[CAPACITY];
    int size;
} queue;
```

A __stack__ is another form of abstract data type, they support the opposite of queues which is __LIFO__ last in, first out. There are contexts where this makes sense, for example within an email program you usually start with the ones that came in most recently because they are ordered in that way.

The two operations for enque and dequeue are called `push` and `pop` so you `push` a user into the array and `pop` them out of the array. 

A stack and a queue can be defined almost identically interms of data structure, even if the logic is different the data is the same.


