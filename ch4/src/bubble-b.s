	.file	"bubble-b.c"
	.text
	.globl	bubble_b
	.type	bubble_b, @function
bubble_b:
.LFB23:
	.cfi_startproc
	leaq	-8(%rdi,%rsi,8), %rsi
	jmp	.L2
.L3:
	addq	$8, %rax
.L5:
	cmpq	%rsi, %rax
	jnb	.L7
	movq	8(%rax), %rdx
	movq	(%rax), %rcx
	cmpq	%rcx, %rdx
	jge	.L3
	movq	%rcx, 8(%rax)
	movq	%rdx, (%rax)
	jmp	.L3
.L7:
	subq	$8, %rsi
.L2:
	cmpq	%rdi, %rsi
	jbe	.L8
	movq	%rdi, %rax
	jmp	.L5
.L8:
	rep ret
	.cfi_endproc
.LFE23:
	.size	bubble_b, .-bubble_b
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Unsorted array:\t"
.LC1:
	.string	"Sorted array:\t"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$96, %rsp
	.cfi_def_cfa_offset 112
	movq	%fs:40, %rax
	movq	%rax, 88(%rsp)
	xorl	%eax, %eax
	movq	$0, (%rsp)
	movq	$1, 8(%rsp)
	movq	$4, 16(%rsp)
	movq	$2, 24(%rsp)
	movq	$5, 32(%rsp)
	movq	$9, 40(%rsp)
	movq	$8, 48(%rsp)
	movq	$3, 56(%rsp)
	movq	$7, 64(%rsp)
	movq	$6, 72(%rsp)
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	call	__printf_chk@PLT
	movq	%rsp, %rbx
	movl	$10, %esi
	movq	%rbx, %rdi
	call	print_array@PLT
	movl	$10, %esi
	movq	%rbx, %rdi
	call	bubble_b
	leaq	.LC1(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$10, %esi
	movq	%rbx, %rdi
	call	print_array@PLT
	movq	88(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L12
	movl	$0, %eax
	addq	$96, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L12:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
