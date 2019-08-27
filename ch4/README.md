# Chapter 4
## Materials
Y86-64 is a simulator used to compile AS program in this book. Source distribution and guide manual are all provided on its [official site](csapp.cs.cmu.edu/3e/students.html). 

I also provide the simulator source distribution and guide manual in sub-folder `sim`.

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

[bubble-b.c](./src/bubble-b.c)

B.
