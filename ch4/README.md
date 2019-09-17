# Chapter 4
## Materials
Y86-64 is a simulator used to compile AS program in this book. Source distribution and guide manual are all provided on its [official site](csapp.cs.cmu.edu/3e/students.html). 

I also provide the simulator source distribution and guide manual in sub-folder `sim`.

**Notice**: Decompress tar package and then execute `make` command, "matherr" error may occur though you have already installed graphical tools. Just comment those 2 lines containing the function in files `seq/ssim.c` and `pipe/psim.c`.

## Solutions to Homework Problems

### 4.45
(page 370)
The `pushq` instruction both decrements the stack pointer by 8 and writes a register value to memory. It is therefore not totally clear what the processor should do when executing the instruction `pushq %rsp`, since the register being pushed is being changed by the same instruction. Two different conventions are possible:
1. push the original value of `%rsp`; or
2. push the decremented value oof `%rsp`.

The experiment(Practice Prolem 4.7) proves that x86-64 adopts the $ 1^{st} $ option.

A similar ambiguity occurs for the instruction `popq %rsp`. It could either set `%rsp` to the value read from memory or to the incremented stack pointer.

Problem 4.8 solution suggests that `popq %rsp` sets the stack pointer to the value read from memory. It is therefore equivalent to the instruction `mrmovq (%rsp), %rsp`.

A.

No. If REG is `%rsp`, the instruction `pushq %rsp` is equivalent to below 2 instructions:
```as
subq $8, %rsp
movq %rsp, (%rsp)
```
This is different from the result of Practice Problem 4.7 and conflicts with previous analysis.

B.

The code sequence can be changed into following 2 instructions:
```as
mov REG, -8(%rsp)
subq $8, %rsp
```

### 4.46
A.

No. If REG is `%rsp`, the instruction is equivalent to below 2 instructions:
```as
movq (%rsp), %rsp
addq $8, %rsp
```
First instruction pops the value located in `(%rsp)` into the register `%rsp`, but second instruction modifies it. This is different from previous analysis.

B.

The code sequence can be changed into following 2 instructions:
```as
add $8, %rsp
movq -8(%rsp), REG
```

### 4.47
A.

Bubblesort using array referencing: [bubble-a.c](./src/bubble-a.c)

Bubblesort using pointer referencing: [bubble-b.c](./src/bubble-b.c)

B.

Use commands `gcc -Og -S bubble-b.c` and `gcc -Og -S bubble-a.c` to get an optimized assembly code files [bubble-b.s](./src/bubble-b.s) and [bubble-a.s](./src/bubble-a.s).

Y86-64 program: 

[bubble-b.ys](./src/bubble-b.ys)

[bubble-b.yo](./src/bubble-b.yo)

### 4.48
Using no jumps at most three conditional moves: 

[bubble-b-cond3.ys](./src/bubble-b-cond3.ys)

[bubble-b-cond3.yo](./src/bubble-b-cond3.yo)

### 4.49
Using no jumps at most one conditional mov:

[bubble-b-cond1.ys](./src/bubble-b-cond1.ys)

[bubble-b-cond1.yo](./src/bubble-b-cond1.yo)

### 4.50
Example use of switch statement:

[switchv.c](./src/switchv.c)

[switchv.s](./src/switchv.s)

Y86-64 code: 

Below file doesn't use jump table:

[switchv.ys](./src/switchv.ys)

[switchv.yo](./src/switchv.yo)

Below file uses jump table:

[switchv-table.ys](./src/switchv-table.ys)

[switchv-table.yo](./src/switchv-table.yo)

### 4.51
|*Stage*|*iaddq*|
|-|-|
|**Fetch**|$icode:ifun \leftarrow M_{1}[PC], rA:rB \leftarrow M_{1}[PC+1], valC=M_{8}[PC+2], valP=PC+10$|
|**Decode**|$valB \leftarrow R[rB]$|
|**Execute**|$valE \leftarrow valB + valC, Set \space CC$|
|**Memory**||
|**Write back**|$R[rB] \leftarrow valE$|
|**PC update**|$PC \leftarrow valP$|

### 4.52
If we get right solution to previous problem, it is easy to get the answer.
BTW, compared with x86-84, Y86-64 is extremely simple to read and learn.

[seq-full.hcl](./sim/seq/seq-full.hcl)

To verify the correctness of `iaddq`, you have to change the `VERSION` from `std` to `full` in `seq/Makefile`.
Re-compile and build source files, and then execute the file `asumi.yo` located in folder `y86-code`.

### 4.53
solution is coming...

### 4.54
[pipe-full.hcl](./sim/pipe/pipe-full.hcl)

To verify the correctness of `iaddq`, you have to change the `VERSION` from `std` to `full` in `pipe/Makefile`.
Re-compile and build source files, and then execute the file `asumi.yo` located in folder `y86-code`.

### 4.55
