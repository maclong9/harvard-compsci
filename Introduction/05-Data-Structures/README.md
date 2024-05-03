# Using The Computers Memory in Interesting Ways

An abstract data type is a implemented by a programmer, for example __queues__. As simple as a queue in the normal well, they offer a __FIFO__ or first in first out approach. You can usually enqueu and deque which is akin to entering and exiting a queue. You can use an array to define a queue.  The two operations for enque and dequeue are called `push` and `pop` so you `push` a user into the array and `pop` them out of the array. 

```c
const int CAPACITY = 50;

typedef struct {
    person people[CAPACITY];
    int size;
} queue;
```

A __stack__ is another form of abstract data type, they support the opposite of queues which is __LIFO__ last in, first out. There are contexts where this makes sense, for example within an email program you usually start with the ones that came in most recently because they are ordered in that way.  A stack and a queue can be defined almost identically interms of data structure, even if the logic is different the data is the same.

## Allocating More Space

Adding to an array that hasn't had enough space allocated to it means you have to move the data to a new memory location that can fit the array. This can be slow due to iterating over the array when copying it over into the new location. You can see this example in [list.c](./list.c). In this example the lines of code that look like `list[0..2] = 1..3` will put the values as `0-3`, `4-7` and `8-11`. The full example shows allocating extra memory and then moving a smaller array into the largest space and appending one item.

You could just assign the array `300 sizeof(int)` however this could be using far too much memory and also you may still run into the same issue, and it becomes incredibly slow to copy over so many values when moving from the `tmp` array.

LECTURE TIME: 30:34


[Previous: 04-Me](../04-Memory/README.md) <br />
[Next: 06-](../06-) 
