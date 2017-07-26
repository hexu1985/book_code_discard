	.file	"function.c"
	.intel_syntax noprefix
	.text
	.globl	sum_of_integer_squares_between
	.type	sum_of_integer_squares_between, @function
sum_of_integer_squares_between:
.LFB0:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 20
	mov	eax, DWORD PTR [ebp+12]
	add	eax, 1
	imul	eax, DWORD PTR [ebp+12]
	mov	edx, DWORD PTR [ebp+12]
	add	edx, edx
	add	edx, 1
	mov	ecx, eax
	imul	ecx, edx
	mov	DWORD PTR [ebp-20], ecx
	mov	edx, -1431655765
	mov	eax, DWORD PTR [ebp-20]
	mul	edx
	mov	eax, edx
	shr	eax, 2
	mov	DWORD PTR [ebp-8], eax
	mov	eax, DWORD PTR [ebp+8]
	add	eax, 1
	imul	eax, DWORD PTR [ebp+8]
	mov	edx, DWORD PTR [ebp+8]
	add	edx, edx
	add	edx, 1
	mov	ecx, eax
	imul	ecx, edx
	mov	DWORD PTR [ebp-20], ecx
	mov	edx, -1431655765
	mov	eax, DWORD PTR [ebp-20]
	mul	edx
	mov	eax, edx
	shr	eax, 2
	mov	DWORD PTR [ebp-4], eax
	mov	eax, DWORD PTR [ebp-4]
	mov	edx, DWORD PTR [ebp-8]
	mov	ecx, edx
	sub	ecx, eax
	mov	eax, ecx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	sum_of_integer_squares_between, .-sum_of_integer_squares_between
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
