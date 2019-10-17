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

### 6.33
|0x1788|0x1789|0x178A|0x178B|0x1C88|0x1C89|0x1C8A|0x1C8B|
|-|-|-|-|-|-|-|-|

### 6.34
Notice: elements with same row index will load into same cache set.

**dst array**
||Col.0|Col.1|Col.2|Col.3|
|-|-|-|-|-|
|Row0|m|m|h|m|
|Row1|m|h|m|h|
|Row2|m|m|h|m|
|Row3|m|h|m|h|

**src array**
||Col.0|Col.1|Col.2|Col.3|
|-|-|-|-|-|
|Row0|m|m|m|m|
|Row1|m|m|m|m|
|Row2|m|m|m|m|
|Row3|m|m|m|m|

### 6.35
The cache with total size of 128 bytes.
The block with size of 16 bytes.
Therefore, we have 8 sets of bytes, and each row of source and destination arrays can be located in an unique block.

**dst array**
||Col.0|Col.1|Col.2|Col.3|
|-|-|-|-|-|
|Row0|m|h|h|h|
|Row1|m|h|h|h|
|Row2|m|h|h|h|
|Row3|m|h|h|h|

**src array**
||Col.0|Col.1|Col.2|Col.3|
|-|-|-|-|-|
|Row0|m|h|h|h|
|Row1|m|h|h|h|
|Row2|m|h|h|h|
|Row3|m|h|h|h|

Extension: If the cache size is 64 bytes, what the arrays will be?

### 6.36
```c
int x[2][128];
int i;
for (i = 0; i < 128; i++) {
    sum += x[0][i] * x[1][i];
}
```
A. Case 1

Cache size is 512 B. The miss rate is 100%.

B. Case 2

Cache size is 1024 B. The miss rate is 25%.

C. Case 3

Cache size is 512 B, but use LRU replacement policy. The miss rate is 25%.

D.

No.
Larger cache can not reduce the miss rate because no matter how large the cache is, the first element of each block will miss.

E.

Yes.
Larger block can reduce the miss rate because we only miss the element of first block when loading data from lower memory each time.

### 6.37
Miss rate table:

|Function|N = 64|N = 60|
|-|-|-|
|sumA|25%|25%|
|sumB|25%|25%|
|sumC|25%|25%|

### 6.38
A. 

16 * 16 * 4 = 1024

B.

128

C.

12.5%

### 6.39
A.

16 * 16 * 4 = 1024

B.

256

C.

25%

### 6.40
A.

16 * 16 * 4 = 1024

B.

16 * 16 / 2 + 16 * 16 * 3 /2 /3 = 256

C.

25%

### 6.41
25%

### 6.42
25%

### 6.43
100%

### 6.44
[Here](./src/mountain/) is the `mountain` program.

Run this program on my machine and the results are as follows:
```
➜  mountain ./mountain 
Clock frequency is approx. 2112.0 MHz
Memory mountain (MB/sec)
	s1	s2	s3	s4	s5	s6	s7	s8	s9	s10	s11	s12	s13	s14	s15	
128m	15567	9510	6256	4543	3676	2973	2575	1914	1759	1618	1517	1436	1369	1306	1293	
64m	13683	8615	6543	4758	3673	3066	2624	2352	2113	1968	1844	1698	1589	1571	1546	
32m	16456	10204	6770	4943	3825	3085	2696	2345	2203	2007	1881	1727	1688	1654	1583	
16m	15474	11056	7618	5715	4130	3481	2979	2562	2479	2411	2328	2231	2065	1982	2056	
8m	14412	13171	9871	7733	5140	4727	4167	3664	4170	3477	3694	3717	4309	4592	4539	
4m	32301	24224	20284	16192	13322	11457	9976	8856	8563	8254	8097	7690	7621	7444	7336	
2m	32743	25080	20752	16555	13815	11873	10403	9188	8813	8484	8179	7899	7703	7492	7388	
1024k	32841	24788	20619	16662	13864	11917	10419	9233	8874	8501	8171	7889	7663	7488	7385	
512k	32832	25207	21046	16867	14009	12042	10550	9370	8941	8644	8403	8161	8084	7992	8003	
256k	33966	27397	24340	21074	18290	15827	13954	12292	12249	12353	12264	12002	13426	13875	13520	
128k	35166	29740	28497	26334	23165	20182	18090	16261	15676	16094	15419	16019	16058	15843	16332	
64k	35148	30327	29499	28224	25537	23347	20217	17800	18091	17300	17523	17318	17396	18240	29017	
32k	42667	40999	39364	38109	37608	35819	37734	34603	34320	35301	40318	36960	35015	33850	36608	
16k	42096	39682	38703	36969	37198	38958	33392	34328	33137	36803	32089	31336	30240	29417	30346
```
L1 cache region: 0-32K

L2 cache region: 32K-256K

L3 cache region: 512K-8M

Main memory region: 8M - 128M

### 6.45


### 6.46


