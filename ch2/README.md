# Chapter 2
## Solutions to Homework Problems

### 2.55 2.56 2.57
[show-bytes.c](./show-bytes.c)

### 2.58
[is-little-endian.c](./is-little-endian.c)

### 2.59
```c
(x & (0xFF)) | ((y >> 8) << 8)
```
### 2.60
[repalce-byte.c](./repalce-byte.c)

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
[int-shifts-are-arithmetic.c](./int-shifts-are-arithmetic.c)

## 2.63
[srl-and-sra.c](./srl-and-sra.c)

## 2.64
[any-odd-one.c](./any-odd-one.c)

## 2.65
[odd-ones.c](./odd-ones.c)
This solution is very tricky.
If we only have 4 bits number, it is easy to get a number with odd number of 1s.
They are as follows: 
0001(0x1), 0010(0x2), 0100(0x4), 1000(0x8), 0111(0x7), 1011(0xB), 1101(0xD), 1110(0xE).
So we can create an table to save those cases.
`0x6996(0110 1001 1001 0110)` means if the ith bit value is 1, i has odd number of 1s.(i = 0,1,2,...)

If 32 bits can decrease to 4 bits, the problem can be solved.
One key point is we don't care about any even number of 1s, but only care about the minimum odd number of 1s.

Just think about below fomula, 
```c
x ^= x>>16
```
x is unsigned integer.

The low 16 bits is `a`, high 16 bits is `b`. `x = a ^ b` will set the same bit position as 0 if they are all 1.
Now, we get a integer in which bit value 1 denotes `a` and `b` have an defferent bit value in that position.
If the number of 1s is odd, all 1s in original `x` is odd.

The same algorithm is to right shift 8 bits, 4bits.


## 2.66

