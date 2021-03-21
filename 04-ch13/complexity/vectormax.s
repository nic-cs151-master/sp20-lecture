vectorMax:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movl	$1, -4(%rbp)
.L4:  # START OF THE LOOP
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	.L2  # FOR LOOP CONDITION FAILS, JUMP TO L2
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jge	.L3  # REPEAT LOOP
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
.L3:
	addl	$1, -4(%rbp)
	jmp	.L4
.L2:
	movl	-8(%rbp), %eax
	popq	%rbp
	ret