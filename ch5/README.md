# Chapter 5
## Solutions to Homework Problems

### 5.13
[5.13.c](./src/5.13.c)

A.

![5.13](./pic/5.13.jpg)

B.

Just as displayed in above picture, the key path is `add` cell. 
According to Figure 5.12, the lower bound on the CPE is 3.0.

C.

Same as above analysis, the lower bound on the CPE is 1.0.

D.

As we can see from above pic, there is only one `add` cell on key path.
Therefore, the cycle of `mul` can not impact CPE.

### 5.14
[5.14.c](./src/5.14.c)

A.

Using 6x1 loop unrolling, we cannot change the limiting factors.
There are 6 float/long `add` cells on key path.
Therefore, the lower bound on CPE is still 1.0.

B.

Same as above answer.

### 5.15
[5.15.c](./src/5.15.c)

The following factors may limit the performance to a CPE 1.0:
1. the number of registers is limited; the performance cannot improve when reaching maximum utilization of registers.(Register Spilling)

### 5.16
[5.16.c](./src/5.16.c)
