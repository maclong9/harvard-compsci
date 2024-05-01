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
    1["for i from 0 to n"] -->
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
    1["for count from 0 to total"] -->
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
> Computer Scientists tend to talk about the efficiency being on the order of a number of steps. They also throw away constant factors such as the number, instead they generalise with $O(log n)$.

## Big $O$ Notation 

- various algorithms will be described as being on the order of one of the following runtimes:
    - $O(n^{2})$ - 
    - $O(n log n)$ - 
    - $O(n)$ - 
    - $O(log n) - 
    - $O(1)$ - 

