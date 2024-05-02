# Memory 

## Colors

- pixels are used to display images.
- because they are blocky sometimes images can appear also blocky.
- the more pixels a screen has the more _smooth_ and image can appear.
- you can relate pixels to binary digits, 0 being black and 1 white.
- an image files is kind of just a pattern of 0's and 1's. 
- RGB is a common way to display colors.
    - Stands for Red, Green and Blue. 
    - Can be a value of 0 to 255.
- HEX is also common.  
    - Similar with each 2 of the 6 digits being Red, Green and Blue.
    - Goes in base-16 from 0 to `FF` with `FF` being 255.

## Hexadecimal

- Hexadecimal is used when you require more than 10 digits for some reason.
- The maths below shows the value of each column and how to figure out basic hex values.

``` math
\overbrace{0}^{16} \overbrace{0}^{1} = 0\newline
```
``` math
\overbrace{0}^{16} \overbrace{1}^{1} = 1\newline
```
``` math
\overbrace{0}^{16} \overbrace{A}^{1} = 10\newline
```
``` math
\overbrace{0}^{16} \overbrace{F}^{1} = 15\newline
```
``` math
\overbrace{1}^{16} \overbrace{0}^{1} = 16\newline
```
``` math
\overbrace{1}^{16} \overbrace{1}^{1} = 17\newline
```
``` math
\overbrace{2}^{16} \overbrace{3}^{1} = 36\newline
```
``` math
\overbrace{F}^{16} \overbrace{F}^{1} = 255\newline
```

> [!NOTE]
> You will not need to do these kind of conversions very frequently.

- It's mostly just more convenient than binary for larger values.
- most programs from photo editors to web programming use hex based values for colors.
- computers typically use numbers in hexadecimal notation to number the bytes in memory. 

```
grid of memory
8 byte 0x123 for p
store 50 in 4 of the blocks. 
stored in 0x123 = 291 
``` 

- you can print the memory address like so `printf("%p", &var);`
- this is because C supports pointers which point at the memory address.
- `int *p = &n;` this asks the compiler for a variable called `p` which I can place a pointer inside.
- declaring a pointer is `int *p;`
- `*p` without specifying a type means go to that address.
- `p` is another variable. Pointers take up 8 bytes.
    - in this case `p` is just storing a number, that is equivalent to the address of the value.

> [!NOTE]
> `&` is the address of a variable, whereas `*` is a pointer to an address.

## Taking Off Training Wheels

- The [string](https://manual.cs50.io/3/get_string) type that has been detailed during the CS50 lectures
- They are actually just arrays of `chars`.
- if the first letter of the word is at `0x123` then each letter of the word would be stored in just one address along.
- the type of string is actually just a pointer that points to the characters in memory.
    - this is what the null terminate code is for, the pointer leads you to the beginning of the string and the null character ends the string.

```
diagram of s stored in 8 bytes pointing to start of string hi!\0
```

> [!NOTE]
> Modern computers use 64-bit allowing you to count to crazy high numbers. $64–bit = 2^{63} - 1$.

- The datatype of string is a `char*`. 
    - the `*` means `char* s` is not a `char` but the address of the first `char` in a string.
- `&` says the address of a variable.
- `*` is the pointer to an address.
- You can use `typedef` to create any number of data types.
- a common abstraction `typedef uint8_t BYTE;`.
- `string` in CS50 is set as `typedef char *string;`
- Pointer Arithmetic is how you would manually print a string in C you can see the example in [addresses.c](./addresses.c). 
- if you compare a `char*` with another `char*` doing `s = t` will be different everytime because the `s` and `t` are a pointer to the first character of a string.
    - comparing the value of `s` and `t` with `&s` and `&t` it might be different due to it comparing the first character only.
    - you should use `strcmp` to compare two `char*` values.
- if you assign `t = s` it will copy the address rather than the value.
    - this means if you are trying to create a copy of something to manipulate both will be manipulated because the pointer is the same for both.
- `malloc` allows you to allocate a section of memory to a variable.
    - ` char *t = malloc(strlen(s + 1));`
- `free` frees up a specified memory section that's been previously allocated.
    -

> [!CAUTION]
> Ensure when iterating to copy strings to other variables that you do it to `<= n` to encompass the null character.
