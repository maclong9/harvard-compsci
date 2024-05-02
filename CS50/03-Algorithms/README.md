# Dividing Tasks to Conquer Faster

``` mermaid
---
title: Taking Attendance Algorithm
---

flowchart TD
    1["Everyone Stands and Thinks of Number 1"] -->
    2["Everyone Pairs Off and Adds Their Numbers"] -->
    3["One of Pair Sits"] -->
    4{"If One Person Remains Standing"}
    4 -->|True| 5["Say Number"]
    4 -->|False| 2
```

``` mermaid
---
title: Values Behind Lockers Brute Force Algorithm
---

flowchart TD
    1(["for i from 0 to n"]) -->
    2{"if 50 is behind doors[i]"}
    2 --> |true| 3["Return True"] --> 6
    2 --> |false| 4["Return False"] --> 5{"if i < n"}
    5 --> |true| 2
    5 --> |false| 6["Exit"]
```

``` mermaid
---
title: Value Behind Lockers Divide & Conquer Algorithm
---

flowchart TD
    vars("Variables\nvalue = 50\ntotal = 8")
    1(["for count from 0 to total"]) -->
    2{"if count equals total"}
    2 --> |true| 3["value doesn't exist"] --> 16
    2 --> |false| 4["if value is behind doors item count"]
    4 --> |true| 5["return value"] --> 15
    4 --> |false| 6["return false"] -->
    7{"if v is below n / 2"} 
    7 --> |true| 8["search left half"] --> 4
    7 --> |false| 9["search right half"] --> 4

    15("exit 0")
    16("exit 1")
```

> [!NOTE]
> Computer Scientists tend to talk about the efficiency being on the order of a number of steps. They also throw away constant factors such as the number, instead they generalise with $O(\log n)$.

## Big $O$ Notation 

- various algorithms will be described as being on the order of one of the following runtimes:
    - $O(n^{2})$ - n people doing n things, example shaking everyones hand in the room it would be $n \times n$ or $n^{2}$ handshakes. **Quadratic**.
    - $O(n \log n)$ - **Logarithmic**.
    - $O(n)$ - takes linear time, an example of this is going through the phonebook one at a time. It represents an upper bound on the number of steps you might be counting.
    - $O(\log n)$ - dividing in half. *binary search*.
    - $O(1)$ - this means it is a constant number of steps, no matter how many people the algorithm is working through.
- $\Omega$ represents lower bound.
    - $\Omega(n^{2})$ 
    - $\Omega(n \log n)$
    - $\Omega(n)$ 
    - $\Omega(\log n)$
    - $\Omega(1)$  - _linear search_, _binary search_
- $\Theta$ represents that $O$ and $\Omega$ are equal.
    - $\Theta(n^{2})$ 
    - $\Theta(n \log n)$
    - $\Theta(n)$ 
    - $\Theta(\log n)$
    - $\Theta(1)$  - _linear search_, _binary search_

> [!NOTE]
> When you `return 0` it will exit the program and will not run any subsequent code.

- `strcmp` is used to compare two strings, `0` means the strings are the same.
    - `if(strcmp("test", "test") == 0)`
    - it compares strings in _ASCIIbetical_ order.

> [!NOTE]
> A code smell is something where you can kind of tell it's going to cause an error or problem later, e.g.

## Structs for Storing Data

- for this example we wil luse the example of `Person`.
    - a person has a `string name` and a `string number`.
- we can use `typedef struct` to create a `struct`.
    - `typedef` just means create a data type.
- there is an example [here in phonebook.c](./examples/phonebook.c).

## Sorting Algorithms

### Find Smallest Algorithm 

``` mermaid
---
title: Find Smallest Algorithm
---

flowchart TD
    vars>"Variables\n\ntotal = 8\nprevious = NULL\ncompleted = 0"]
    1(["for count in total"]) -->
    2{"if count + completed less than total"}
    2 --> |true| 3
    2 --> |false| 4["move previous to start of array and add 1 to completed"]
    3["check bit at count"] 
    3 --> |"smaller"| 5["store as previous"] --> 2
    3 --> |"larger"| 6["keep current bit"] --> 2
```

### Swapping Algorithm

``` mermaid
---
title: Pair Swap Algorithm
---

flowchart TD
    vars>"Variables\ncompleted = 0\nitems = [0, 2, 4, 6, 8, 1, 3, 5, 7]"]
    1(["for count in length of items"]) -->
    2{"if count equals length of items - completed"} 
    2 --> |true| 8["print sorted array"]
    2 --> |false| 3
    3{"if items[count] more than items[count] + 1"}
    3 --> |true| 5("switch items[count] and items[count + 1]")
    3 --> |false| 6("leave items[count] and items[count + 1]")
    5 & 6 --> 7("increment count by 2 and completed by 1") --> 2
``` 

