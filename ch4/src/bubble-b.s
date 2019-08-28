	.file	"bubble-b.c"
	.text
	.globl	bubble_b
	.type	bubble_b, @function
bubble_b:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rax
	salq	$3, %rax
	leaq	-8(%rax), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -16(%rbp)
	jmp	.L2
.L6:
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.L3
.L5:
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jge	.L4
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
.L4:
	addq	$8, -24(%rbp)
.L3:
	movq	-24(%rbp), %rax
	cmpq	-16(%rbp), %rax
	jb	.L5
	subq	$8, -16(%rbp)
.L2:
	movq	-16(%rbp), %rax
	cmpq	-40(%rbp), %rax
	ja	.L6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	bubble_b, .-bubble_b
	.section	.rodata
.LC0:
	.string	"Unsorted array:\t"
.LC1:
	.string	"Sorted array:\t"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movl	%edi, -100(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -96(%rbp)
	movq	$1, -88(%rbp)
	movq	$4, -80(%rbp)
	movq	$2, -72(%rbp)
	movq	$5, -64(%rbp)
	movq	$9, -56(%rbp)
	movq	$8, -48(%rbp)
	movq	$3, -40(%rbp)
	movq	$7, -32(%rbp)
	movq	$6, -24(%rbp)
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-96(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	print_array@PLT
	leaq	-96(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	bubble_b
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-96(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	print_array@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
