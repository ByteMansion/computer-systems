# Chapter 3
## Solutions to Homework Problems

### 3.58

[decode2.c](./src/decode2.c)

### 3.59
The following code computes the 128-bit product of two 64bit signed values x and y and stores the result in memory:
```c
typedef __int128 int128_t;
void store_prod(int128_t *dest, int64_t x, int64_t y) {
    *dest = x * (int128_t) y;
}
```
Gcc generates the following assembly code implementating the computation:
```s
# dest in %rdi, x in %rsi, y in %rdx
store_prod:
 1    movq    %rdx, %rax    # y -> %rax
 2    cqto                  # convert y to 128-bit
                            # low 64-bit y_l in %rax, high 64-bit y_h in %rdx
 3    movq    %rsi, %rcx    # x -> %rcx
 4    sarq    $63, %rcx     # extend signed bit of x
                            # if x_63 == 1, value is -1; if x_63 == 0, value is 0
 5    imulq   %rax, %rcx    # x_h * y_l = prod1 -> %rcx
 6    imulq   %rsi, %rdx    # x_l * y_h = prod2 -> %rdx
 7    addq    %rdx, %rcx    # prod1 + prod2 = prod -> %rcx
 8    mulq    %rsi          # x * y -> %rdx: %rax
 9    addq    %rcx, %rdx    # prod + (x * y)_h -> %rdx
10    movq    %rax, (%rdi)  # set low 64 bits
11    movq    %rdx, 8(%rdi) # set high 64 bits
12    ret
```
Extend 64-bit to 128-bit, the value of high 64 bit depends on the signed value.
If signed bit is 1, the high 64-bit is -1 (11...11); if signed bit is 0, the high 64-bit is 0 (00...00).
Therefore, the two operations of `cqto` and `sarq $63, %rcx` are for the same goal.

Assume extended $ x $ and $ y $ can be represented as
$$
x_{ext} = x_h * 2^{64} + x_l \\
y_{ext} = y_h * 2^{64} + y_l
$$
In fact, $ x_l $ is equal to $ x $, and $ y_l $ is equal to $ y $.

$$
x_{ext} * y_{ext} = (x_h * 2^{64} + x_l) * (y_h * 2^{64} + y_l) = x_h * y_h * 2^{128} + (x_h * y_l + x_l * y_h) * 2^{64} + x_l * y_l
$$
$ 2^{128} $ exceeds 128-bit limit, so we can omit it.
Above formula gives a solution to the problem.
$$
x_{ext} * y_{ext} = (x_h * y_l + x_l * y_h) * 2^{64} + x * y 
$$

### 3.60