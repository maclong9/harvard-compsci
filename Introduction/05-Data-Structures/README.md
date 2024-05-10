# Using The Computers Memory in Interesting Ways

An abstract data type is a implemented by a programmer, for example __queues__. As simple as a queue in the normal world, they offer a __FIFO__ or first in first out approach. You can enqueue and dequeue which is akin to entering and exiting a queue. 

You can use an array to define a queue. The two operations for enqueue and dequeue are called `push` and `pop` so you `push` a user into the array and `pop` them out of the array. 

```c
const int CAPACITY = 50;

typedef struct {
    person people[CAPACITY];
    int size;
} queue;
```

A __stack__ is another form of abstract data type, they support the opposite of queues which is __LIFO__ last in, first out. There are contexts where this makes sense, for example within an email program you usually start with the ones that came in most recently because they are ordered in that way.

A stack and a queue can be defined almost identically in terms of data structure, even if the logic is different the data is the same.

## Allocating More Space

Adding to an array that hasn't had enough space allocated to it means you have to move the data to a new memory location that can fit the array. This can be slow due to iterating over the array when copying it over into the new location. You can see this example in [list.c](./list.c). This example shows allocating extra memory and then moving a smaller array into the largest space and appending one item.

You could just assign the array `300 sizeof(int)` however this could be using far too much memory and also you may still run into the same issue, finally it becomes incredibly slow to copy over so many values when moving from the `tmp` array.

## A Linked List

This allows you to connect values that aren't in contiguous memory together, for example you have an array of 3 values and you push a 4th value into the array the computer needs to link the memory from the original array to the 4th value.

You can link memory addresses using pointers. Pointers can be considered metadata or an implementation detail that is useful for organisation of data. 

> [!NOTE]
> `NULL` is equal to `0x0` when represented with hexadecimal.`

A linked list uses one node per value and one pointer that points to the first item of the list.  Below is an example of using a structure that points to the next value within it's linked list.

``` c 
typedef struct node {
    int number;
    struct node *pointer;
} node
```

You can then use `malloc` and `sizeof` to allocate memory equal to the size of a node for a pointer that points to the first item of the linked list, with each item of the linked list pointing to the next item in the list.

You can then set `list = n` as `n` was a temporary value to be used to find the list and `list` is the permanent global variable. You would do this each time you add a new item to the liked list ensuring that the list variable is always pointing to the first item of an array.

You can see an example of the above in [linked-list.c](./linked-list.c).

> [!WARNING]
> Always ensure to link the new value to the previous first value of the linked list.

## Trees

Trees are a variant of arrays and linked lists that are more complelling 1 and up dimensional solutions.

> [!NOTE]
> For simple explanations an array of 7 is usefu because it has a perfect middle value.

The problem with a linked list is you lose $\log(n)$ running time because you must start from the beginning every time you need to reach a value further into the array.

You can view a 7 value array as the middle, the middle of the middle and the middle of the middle of the middle.

![Middle's Highlighed in Arrray](https://github.com/maclong9/harvard-compsci/assets/115668288/683f9f23-5609-426f-be1c-5590b60a5f11)

[Previous: 04-Memory](../04-Memory/README.md) <br />
[Next: 06-](../06-) 
