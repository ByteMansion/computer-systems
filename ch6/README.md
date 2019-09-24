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

### 6.25
|Cache|m|C|B|E|S|t|s|b|
|-    |-|-|-|-|-|-|-|-|
|1.   |32|1024|4|4|64|24|6|2|
|2.   |32|1024|4|256|1|30|0|2|
|3.   |32|1024|8|1|128|22|7|3|
|4.   |32|1024|8|128|1|29|0|3|
|5.   |32|1024|32|1|32|22|5|5|
|6.   |32|1024|32|4|8|24|3|5|

### 6.26
|Cache|m|C|B|E|S|t|s|b|
|-    |-|-|-|-|-|-|-|-|
|1.   |32|2048|8|1|256|21|8|3|
|2.   |32|2048|4|4|128|23|7|2|
|3.   |32|1024|2|8|64|25|6|1|
|4.   |32|1024|32|2|16|23|4|5|

### 6.27 6.28
Omit.

### 6.29
A.

|CT|CT|CT|CT|CT|CT|CT|CT|CI|CI|CO|CO|
|-|-|-|-|-|-|-|-|-|-|-|-|

B.

|Operation|Address|Hit?|Read value(or Unknown)|
|-|-|-|-|
|Read|0x834|No|-|
|Write|0x836|Yes|Unknown|
|Read|0xFFD|Yes|0xC0|

### 6.30
A.
$$
C = E \times B \times S = 128
$$

B.
|CT|CT|CT|CT|CT|CT|CT|CT|CI|CI|CI|CO|CO|
|-|-|-|-|-|-|-|-|-|-|-|-|-|

### 6.31
A.

|0|0|1|1|1|0|0|0|1|1|0|1|0|
|-|-|-|-|-|-|-|-|-|-|-|-|-|

B.

|Parameter|Value|
|-|-|
|Block offset(CO)|0x02|
|Index(CI)|0x06|
|Cache tage(CT)|0x38|
|Cache hit?(Y/N)|Y|
|Cache byte returned|0xEB|

### 6.32
A.

|1|0|1|1|0|1|1|1|0|1|0|0|0|
|-|-|-|-|-|-|-|-|-|-|-|-|-|

B.

|Parameter|Value|
|-|-|
|Block offset(CO)|0x0|
|Index(CI)|0x02|
|Cache tage(CT)|0xB7|
|Cache hit?(Y/N)|N|
|Cache byte returned|-|