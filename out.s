	.text
.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	$2, %r8
	movq	$3, %r9
	imulq	%r9, %r8
	movq	$5, %r9
	addq	%r8, %r9
	movq	%r9, %rdi
	call	printint
	movq	%r8, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
