# Chapter 6
## Solutions to Homework Problems

### 6.22
$ r $ denotes the radius of the platter, $ x \cdot r $ the radius of the hole.

Assume:
|Symbol|Description|
|-|-|
|B|parameter for bits per track, bits per tack =$ 2 \cdot B \cdot x \cdot r$|
|N|parameter for number of tracks, number of tracks = $ N \cdot (r - x \cdot r) $|

The capacity of the disk is a function of $x$:
$$
f(x) = 2 \cdot x \cdot r \cdot B \cdot N \cdot (r - x \cdot r) \\
\Rightarrow f(x) = - C \cdot [(x - 1/2)^{2} - 1/4], C = 2 \cdot N \cdot B \cdot r^{2}
$$
Therefore, we can get the maximum capacity when `x` is `1/2`.

### 6.23
For this disk,
$$
T_{avg\_rotation} = 1/2 \times 1/15000 \times 60s/min \times 1000ms/s = 2ms \\
T_{avg\_seek} = 4ms \\
T_{avg\_tansfer} = 1/15000 \times 1/800 \times 60s/min \times 1000ms/s = 0.005ms
$$
Therefore, the access time is:
$$
T_{access} = T_{avg\_rotation} + T_{avg\_seek} + T_{avg\_transfer} = 6.005s
$$

### 6.24
A. Best Case
$$
T_{avg\_seek} = 4ms \\
T_{avg\_rotation} = 2ms \\
T_{avg\_transfer} = 1/15000 \times 1/1000 \times 60s/min \times 1000ms/s = 0.004ms \\
C_{sector} = 2MB/512B = 4096
$$
Therefore,
$$
T_{best\_case} = T_{avg\_seek} + T_{avg_rotation} + C_{sector} \times T_{avg_transfer} = 4 + 2 + 4000 \times 0.004 = 22ms
$$

B.Random Case
$$
T_{random\_case} = C_{sector} \times [T_{avg\_seek} + T_{avg\_rotation} + T_{avg\_transfer}] = 24s
$$


