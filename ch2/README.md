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
[int-shifts-are-arithmetic.c](int-shifts-are-arithmetic.c)
