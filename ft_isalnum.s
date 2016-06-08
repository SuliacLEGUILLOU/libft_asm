global _ft_isalnum

section .text

_ft_isalnum:
	cmp		rdi, 48
	jl		not
	cmp		rdi, 122
	jg		not
	cmp		rdi, 58
	jl		is
	cmp		rdi, 96
	jg		is
	cmp		rdi, 65
	jl		not
	cmp		rdi, 91
	jl		is
	jmp		not

is:
	mov		rax, 1
	ret

not:
	mov		rax, 0
	ret
