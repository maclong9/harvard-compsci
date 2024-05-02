# Memory 

## Colors

- pixels are used to display images.
- because they are blocky sometimes images can appear also blocky.
- the more pixels a screen has the more _smooth_ and image can appear.
- you can relate pixels to binary digits, $0 = black and 1 = white$.
- an image files is kind of just a pattern of 0's and 1's. 
- RGB is a common way to dispaly colors.
    - Stands for Red, Green and Blue. 
    - Can be a value of 0 to 255.
- HEX is also common.  
    - Similar with each 2 of the 6 digits being Red, Green and Blue.
    - Goes in base-16 from 0 to `FF` with `FF` being 255.

## Hexadecimal

- Hexadecimal is used when you require more than 10 digits for some reason.

``` math
\overbrace{0}^{16} \overbrace{0}^{1} = 0
\newline\overbrace{0}^{16} \overbrace{1}^{1} = 1
\newline\overbrace{0}^{16} \overbrace{A}^{1} = 10
\newline\overbrace{0}^{16} \overbrace{F}^{1} = 15
\newline\overbrace{1}^{16} \overbrace{0}^{1} = 16
\newline\overbrace{1}^{16} \overbrace{1}^{1} = 17
\newline\overbrace{2}^{16} \overbrace{3}^{1} = 36
\newline\overbrace{F}^{16} \overbrace{F}^{1} = 255
```

- The maths below shows the value of each space in hex.

> [!NOTE]
> You will not need to do these kind of conversions very frequently.

- It's mostly just more convenient than binary for larger values.