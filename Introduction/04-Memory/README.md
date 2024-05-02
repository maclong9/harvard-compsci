# Memory

## Colors

- pixels are used to display images.
- because they are squares sometimes images can appear blocky.
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

```math
\overbrace{0}^{16} \overbrace{0}^{1} = 0\newline
```

```math
\overbrace{0}^{16} \overbrace{1}^{1} = 1\newline
```

```math
\overbrace{0}^{16} \overbrace{A}^{1} = 10\newline
```

```math
\overbrace{0}^{16} \overbrace{F}^{1} = 15\newline
```

```math
\overbrace{1}^{16} \overbrace{0}^{1} = 16\newline
```

```math
\overbrace{1}^{16} \overbrace{1}^{1} = 17\newline
```

```math
\overbrace{2}^{16} \overbrace{3}^{1} = 36\newline
```

```math
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
> `&` is the address of a variable, whereas `*` is for dereferencing a pointer.

## Explaining Strings

- The [string](https://manual.cs50.io/3/get_string) type is actually just an array of `chars`.
- if the first letter of the word is at `0x123` then each letter of the word would be stored in just one address along.
- the type of string is actually just a pointer that points to the characters in memory.
  - this is what the null terminate code is for, the pointer leads you to the beginning of the string and the null character ends the string.

```
diagram of s stored in 8 bytes pointing to start of string hi!\0
```

> [!NOTE]
> Modern computers use 64-bit allowing you to count to crazy high numbers. $64–bit = 2^{63} - 1$.

- The datatype of string is a `char *`.
  - the `*` means `char *s` is not a `char` but the address of the first `char` in a string.
- You can use `typedef` to create any number of data types.
- a common abstraction `typedef uint8_t BYTE;`.
- `string` in CS50 is set as `typedef char *string;`
- Pointer Arithmetic is how you would manually print a string in C you can see the example in [addresses.c](./addresses.c).
- if you compare a `char *` with another `char *` doing `s = t` will be different everytime because the `s` and `t` are a pointer to the first character of a string.
  - you should use `strcmp` to compare two `char*` values.
- if you assign `t = s` it will copy the address rather than the value.
  - this means if you are trying to create a copy of something to manipulate both will be manipulated because the pointer is the same for both.
- `malloc` allows you to allocate a section of memory to a variable.
  - `char *t = malloc(8);` would allocate 8 bytes of memory.
  - `malloc` returns the first byte address of the chunk of memory.
  - you should check if `malloc` returns `NULL` and terminate if so, because this means there isn't enough memory.
- `free` frees up a specified memory section that's been previously allocated.
  - this is good practice to ensure that the system consistently has enough memory.
- the following code can be replaced with `strcpy`:

```c
	for(int i = 0, n = strlen(s); i <= n; i++) {
		t[i] = s[i];
	}
```

> [!CAUTION]
> Ensure when iterating to copy strings to other variables using the manual method that you do it to `<= n` to encompass the null character.

## Diagnosing Memory Issues

- use the `sizeof` function to specify variables that are the size of types.
  - int \*x = malloc(sizeof(int)); // creates x with bytes of memory equal to int.
  - int _arr = malloc(3 _ sizeof(int)); // creates array with 3 int's worth of memory.
- You can use `valgrind` or `leaks` to check if you have any memory leaks in your code. You can fix these with the `free` function.
- **garbage values** are values of variables that you did not proactively set yourself.
- the [garbage.c](./garbage.c) shows that if you do not set a variable in your code there is a chance that some of the addresses used may contain garbage values.

[here](https://www.youtube.com/watch?v=5VnDaHBi8dM) is a fun video explaining pointers and memory allocation.

```example.c

int main(void) {
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    *y = 13;

    y = x;

    *y = 13;
}
```

- the above code sets variables in a low-level way by allocating the variable x.
- as you can see `x` has been allocated but `y` has not been.
  - this is an example of a garbage value.
  - that's how computers crash.
- `pointer` point to `pointees`.
  - a `pointee` is setup seperately to it's `pointer`.
- a dereference will follow the pointer to the value at the address it is pointed to.
- you cannot dereference a `pointer` that has never been pointed to a `pointee`.
- setting `y = x` gives `y` a `pointee`.
- [swap.c](./swap.c) shows an example of swapping variables values between spaces.
  - this is called **passing by value** or by **copy**.
  - the compiled result goes towards the top of the computers memory.
  - below the compiled result is where global variables go.
  - next comes the _heap_.
    - when you use `malloc` memory comes from here.
  - at the very bottom of the memory is the _stack_.
    - when you use functions with variables and args the memory comes from here.
    - main goes at the very bottom and calls swap.
    - swap goes above main in it's own stack frame.
      - swap is discarded when it's returned.
  - this is why you can't use variables outside of their scope.
    - the variables `x` and `y` passed into the `swap` function from `main` are actually just copies of `x` and `y`.
  - to fix the issue detailed above you need to instead **pass by reference**.
    - you just replace `int a, int b` in the arguments for `swap` to `int *a, int *b`
    - this means that `*a` and `*b` are pointers to `x` and `y`.
    - you also need to pass `&x` and `&y` where you pass them as arguments because you need to be passing the address of `x` and `y`.

> [!NOTE]
> To do the above with a string you would have to use a temporary `char` and loop through the two strings replacing each value within the strings.
