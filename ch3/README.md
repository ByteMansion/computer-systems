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
A.

x in %rdx, n in %r8, result in %rax, mask in %rdx.

B.

result is initialized as 0, mask is initialized as 1.

C.

if mask is zero.

D.

arithmatic left shit.

E.

Bit operation `xor`.

F.

[loop.c](./src/loop.c)

### 3.61
(p. 218)
```c
long cread(long *xp) {
    return (xp ? *xp : 0);
}
```
At first, this seems like a good candidate to compile using a conditional move to set the result to zero when the pointer is null, as shown in the following assembly code:
```s
# long cread(long *xp)
# Invalid implementation of function cread
# xp in register %rdi
cread:
    moveq   (%rdi), %rax    # v = *xp
    testq   %rdi, %rdi      # test x
    movl    $0, %eax        # set ve = 0
    cmove   %rdx, %rax      # if x == 0, v = ve
    ret                     # return v
```
This implementation is invalid, however, since the dereferencing of xp by the `movq` instruction (line 2) occurs even when the test fails, causing a null pointer dereferencing error. Instead, this code must be compiled using branching code.

But, I compile this function and then use command `objdump` to generate its assembly code.
```s
  400846:	55                   	push   %rbp
  400847:	48 89 e5             	mov    %rsp,%rbp
  40084a:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  40084e:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
  400853:	74 09                	je     40085e <cread+0x18>
  400855:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400859:	48 8b 00             	mov    (%rax),%rax
  40085c:	eb 05                	jmp    400863 <cread+0x1d>
  40085e:	b8 00 00 00 00       	mov    $0x0,%eax
  400863:	5d                   	pop    %rbp
  400864:	c3                   	retq 
```
First of all, above code does not use conditional move transfer instruction.
Secondly, before dereferencing address, `compq` instruction test its validity. I think it has avoided the problem of chapter 3.6.6.

[cread-alt.c](./src/cread-alt.c)

### 3.62
[switch3.c](./src/switch3.c)

### 3.63
[switch-prob.c](./src/switch-prob.c)

### 3.64
A.

If the array is 2D vector, $ D[R][C] $, then
$$
sizeof(D) = R * C * L, \And D[i][j] = D + L * (C * i + j).
$$
L is the size of type, such sizeof(int).

If the array is 3D vector, $ A[R][S][T] $, then
$$
sizeof(A) = R * S * T * L, \And A[i][j][k] = A + L * (S*T*i + T*j + k).
$$

B.
Based on those code, we can get:
$$
S * T = 65, T = 13, R * S * T = 3640 / 8.
$$
R = 7, S = 5, T = 13.

### 3.65
A.

&A[i][j] in %rdx.

B.

&A[j][i] in %rax.

C.

M = 15.

### 3.66
NR(n) = 3 * n, NC(n) = 4 * n + 1.
```s
...
    leaq    1(, %rdi, 4), %r8       # (4 * n + 1) in %r8
    leaq    (%rdi, %rdi, 2), %rax
    movq    %rax, %rdi              # (3 * n) in %rdi
...
    addq    (%rcx), %rax            # result += A[i][j]
    addq    $1, %rdx
    leaq    (%rsi, %rdx, 8), %rcx   # &A[i][j] + 8*(4*n+1)
    add     %r8, %rcx
    comq    %rdi, %rdx              # compare row num with (3*n)
...
```