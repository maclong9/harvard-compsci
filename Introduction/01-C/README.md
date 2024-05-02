# A More Traditional Language

## Focuses

- Learning C
- Learning to Solve Problems
- Learn how to not solve problems

## Hello, World!

```hello.c
#include <stdio.h>

int main(void) {
    printf("Hello, World!");
}
```

> [!WARNING]
> In C you must end statements with a semicolon `;`

## Source Code

Source code is what the human writes, and then it is compiled down to machine
code. This is because if we were writing an entire program in `0`s and `1`s
like in the past with punchcards, programming would be very painful.

> [!NOTE]
> Compiling is done via a program called a compiler which translates one language to another, in this case, C to Machine Code.

- `printf` is used to print to the console, the `f` stands for format.
- Running `make hello` will look for a C file with the same string as input in
  this case `hello` and convert it to machine code.
- With `make` if nothing prints that means it worked, otherwise, it will print
  an error.
- You need to end print statements with a `\n` to print a blank line. Pressing
  <kbd>Return</kbd> will not work.
  - This is known as an **escape sequence**.
  - If you want to print `\n` you escape it with an extra backslash `\\n`.
- The `#include <stdio.h>` imports the C standard library, a set of functions
  for performing common operations.
  - This is because C tucks away a lot of functionality in other files.
  - This allows you to keep the binary smaller by only including what is
    required.
  - It is known as a header file and is representative of a library you can
    import.
  - They are useful for sharing common code that most people will need to use at
    some point.
  - You or other people can also create libraries and include them in C files.
  - You can read the **Manual Pages** for a language or library to see what it
    does and how to use it.
- In C you can pass parameters as pointers using `*`, this means they point to a different variable.
  - This is done by passing the memory address of the variable to the function.

> [!CAUTION]
> The `\n` character can cause issues with the `scanf` function if printed before.

[The Mental Model](../README.md#mental-model), can be boiled down to an input
is an argument. A function is the processing section in the middle and the
output is a side effect, for example in the hello world program above the
string printed to the console is the side effect. The side effect can also be
known as a return value.

> [!NOTE]
> Learning programming is not about memorising the whole language, it's more about learning how to solve problems and being able to look up what you need to solve the problem.

## Input

- For receiving input from the user you can use `scanf`.
  - `scanf` is more versatile and can read more than just strings.
- To store input as a variable `char name[50];`.
  - You can then store a value in the variable `name`.
  - You are required to specify the type, such as `char` or `int`.
  - You can define the default value for a variable `char name = "Mac";`.
- When printing with `printf` you utilise `%s` to specify a section of the
  string to be replaced with a variable.
  - You then place the variable after the double quotes and a comma but inside
    the parentheses.
  - `printf("Hello, %s\n", answer);`
  - You can supply multiple variables with each having its place held by `%s`
    and defined in the function.
- `stdin` means standard input, the program can use it to read directly from
  the terminal.
- Format codes
  - `%c`: Character
  - `%f`: Floating Point
  - `%f`: Double, similar to float but `64b`, also defined with `%f`.
  - `%u`: Unsigned Integer
  - `%i`: Integer
  - `%p`: Pointer
  - `%s`: String
  - `%b`: Boolean
  - `%x`: Hexadecimal
  - `%li`: Long Integer
- Operators
  - `<` less than.
  - `>` greater than.
  - `=` sets a variable.
  - `==` is equal to.
  - `!=` is not equal to.

## Variables

I briefly mentioned storing input to variables above. You can use them for all
types and various uses including storing information or a counter value which
is then incremented.

You can reassign a variable, `counter = counter + 1`. Which is so common in C
we created a more succinct syntax `counter += 1`, or even further as
`counter++`.

> [!TIP]
> You can use `const` to define unchangeable variables, `const int n = 5;` as an example.

## The OR and AND Operators

- Using `||` you can run a conditional check on multiple parameters.
  - it will return `true` if either of the options is true.
  - `if(response == 'y' || response == 'Y')`
- Using `&&` will check and make sure that both options are true.
  - `if(isLoggedIn == true && hasAdminAccess == true)`
- You can see an example in [agree.c](./agree.c).

## Loops

- You can utilise a `while` loop to repeat as long as a condition is true.

  - `while(counter < 5)`
  - You can run a counter by setting the variable to the count and subtracting each loop.
  - You can also run it by setting the variable to 0 and incrementing up to the count defined in the loop.
  - You must define the counter before running the `while` loop.
  - It's canonical to use `i` for `integer` to define a counter.
    - For larger programs, it is good to define what the variable is.

- You can also write a loop as a `for` loop.
  - `for (int i = 0; i < 3; i++)`
  - This is the most common option because it is quite concise.
- A **do while** loop will do the expression while the condition is true.

  ```c
  	do {
  		n = get_int("Size: ");
  	}
  	while(n < 1);
  ```

## Functions

- Functions are used to abstract code that might need to be reused.
- They help keep loops and the `main` function tidier.
- `void printHello() {...}`
- A `void` function is a non-returning function.
- You can _hoist_ functions to the top by defining them at the bottom and then copy and paste the function definition e.g. `void printHello()` at the top of the file.
- If you define parameters inside the parentheses you can pass them while calling the function.
  - `void printHello(int n) {...}`
  - `printHello(5);`

> [!TIP]
> While `i` is used for incrementing loops for simple programs you can use `n` as a count or quantity.

### Return Values

- A return value is a value that is handed back from a function to where it was called.
- This is done using the `return` keyword.
- You can then use the function to create a variable.
  - `int x = get_number("x");`
- There is an example in [01-C/calculator.c](./examples/calculator.c)

> [!TIP]
> Strings, or an array of characters, should be wrapped in `"`, whereas single characters should be wrapped in `'`.

## Scope

- Scope refers to what variables are available where.
  - if you have a function called `int getNumber()`, all the variables defined within that function are `local` to that function and cannot be used elsewhere unless you return the value.

> [!NOTE]
> The `main` function is defined as `int` because it returns `0` if the program is successful and a different number known as an **error code** if something goes wrong.

## Comments

- In C you define comments with `//` the compiler will ignore this code.
- Comments are a way to document code at its definition.
- `/* ... */` will define a multiline comment with the content between the two asterisks.

> [!NOTE]
> Good code should be self-documenting. Use comments for complex and non-standard code to explain what it is for.

## Memory Management

- Your computer stores [bits](../README#The Binary System) inside of memory, or Random Access Memory.
- Because memory is finite you can only store a limited number of bits.
- Integer Overflow is an issue where the number will wrap around to `0` or a negative number if the number you attempt to store is too large.
- `32` bits is more common than `8`. It allows us to store more numbers.

> [!NOTE]
> A lot of modern computers are now 64-bit. with the max numbers being unsigned: $2^{64} - 1 = 18,446,744,073,709,551,615$, signed integers: $2^{63} - 1 = 9,223,372,036,854,775,807$ which is pretty large for a number.

## Type Casting

- You can treat one type as another with type casting.
- `float z = (float) x / (float) y;`
- the `(float)` tells the compiler to treat the subsequent variable as a float.

## The Command Line

- The Command Line exists on UNIX and UNIX-Like environments, such as macOS and Linux.
- Linux is a popular OS, commonly used for servers and some desktops/laptops.
- It is typically a command line interface, though a graphical interface can be installed and used.
- Linux is excellent for learning the terminal.
- Development containers are a way of preconfiguring environments for particular types of projects.
  - An example would be installing dependencies like [Deno](https://deno.com) for web development.

> [!NOTE]
> A terminal or terminal emulator is a program you use to interact with the command line interface.

Writing in the command line is terser, so most of the commands below are written as abbreviations instead of full command names.

**Common Commands**

- `cd`: Change Directory.
- `mv`: Move File/Directory.
- `ls`: Lists Files in the Current Folder.
- `cp`: Copies a File to a New Location.
- `rm`: Removes a File.
- `pwd`: Print Working Directory, or the current directory.
- `mkdir`: Makes a New Directory.
- `rmdir`: Removes a Directory.

> [!CAUTION] > `rm` does not move files to the Trash or Recycling Bin like in a GUI Explorer, so be careful when running it on files.

## Integer Bugs

- In 2038 there might be another y2K-like event because the UNIX epoch time is stored in a `32` bit.
- We will likely switch it out for a `64b`.
- This could happen again billions of years in the future.
- The same thing happens with Pacman if you get to the `256b` with your score.
  - When you reach that score the game breaks.
- The original Donkey Kong game had the formula $10 \times (level +4)$, which is how many seconds you have to complete the level.
  - At level `22` an 8-byte value can no longer store the result, leaving players with 4 seconds to solve the level.
