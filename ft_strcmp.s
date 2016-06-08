global _ft_strcmp
extern _ft_strlen

section .text

_ft_strcmp:
	push	rdi
	call	_ft_strlen
	pop		rdi
	mov		rcx, rax
	inc		rcx
	cld
	repne	cmpsb
	mov		rax, [rdi]
	sub		rax, [rsi]
	ret
