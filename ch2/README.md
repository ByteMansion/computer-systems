# Chapter 2
## Solutions to Homework Problems

### 2.55 2.56 2.57
[show-bytes.c](./src/show-bytes.c)

### 2.58
[is-little-endian.c](./src/is-little-endian.c)

### 2.59
```c
(x & (0xFF)) | ((y >> 8) << 8)
```
### 2.60
[replace-byte.c](./src/replace-byte.c)

### 2.61
A. 
```c
x |= ~x
```
B. 
```c
x ^= x
```
C. 
```c
x |= 0xFF
```
D. 
```c
b_cnt = ((sizeof(int) - 1) << 3);
x ^= ((x >> b_cnt) << b_cnt)
```

## 2.62
[int-shifts-are-arithmetic.c](./src/int-shifts-are-arithmetic.c)

## 2.63
[srl-and-sra.c](./src/srl-and-sra.c)

## 2.64
[any-odd-one.c](./src/any-odd-one.c)

## 2.65
[odd-ones.c](./src/odd-ones.c)

This solution is very tricky.

**On one side:**
If we only have 4 bits, it is easy to get a odd number of 1s.
They are as follows: 

0001(0x1), 0010(0x2), 0100(0x4), 1000(0x8), 0111(0x7), 1011(0xB), 1101(0xD), 1110(0xE).

Therefore, we can create an table to save those cases.

`0x6996(0110 1001 1001 0110)` means if the `i`th bit value is 1, `i` has odd number of 1s.(i = 0,1,2,...)

If 32 bits can decrease to 4 bits, the problem can be solved.

**On the other side:**

One key point is we don't care about any even number of 1s, but only care about the minimum odd number of 1s.

Just think about below fomula, 
```c
x ^= x >> 16  // x is unsigned integer with 32 bits

```
The low 16 bits is `a`, high 16 bits is `b`. `x = a ^ b` will set the bit position as 0 if they are all 1.
Now, we get a integer in which bit value 1 denotes `a` and `b` have an defferent bit value in that position.
If the number of 1s is odd, all 1s in original `x` is odd.

The algorithm is same to 16 bits, 8 bits, and 4 bits integers.

## 2.66
Generate mask indicating leftmost 1 in x. x is an unsigned integer.

**Hint** First tansform x into a bit vector of the form [0 ... 01 ... 1].

[leftmost-one.c](./src/leftmost-one.c)

This is also a tricky solution.

First of all, you have to know the meaning of `Hint`. If so, solution maybe rise.

Compared with previous solution, right shift here is to set right position of leftmost 1 as 1 no matter what value it was.

## 2.67
A.

In section 6.5.7 Bitwise shift operators of c11 stardard, it said
- If the value of the right operand is negative or is greater than or equal to the width of the promoted left operand, the behavior is undefined.

B. & C.

[int-size-is-32.c](./src/int-size-is-32.c)

## 2.68
[lower-one-mask.c](./src/lower-one-mask.c)

## 2.69
[rotate-left.c](./src/rotate-left.c)

## 2.70
[fits-bits.c](./src/fits-bits.c)

## 2.71
A.

The code cannot signed extend to 32-bits integer.

B.

[xbyte.c](./src/xbyte.c)

## 2.72
A.

The result of (maxbytes-sizeof(val)) is always unsigned integer cuz the return value of sizeof(val) is unsigned long.

B.

[copy-int.c](./src/copy-int.c)
