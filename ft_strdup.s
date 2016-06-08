global _ft_strdup
extern _ft_strlen, _malloc, _ft_memcpy

section .text

_ft_strdup:
	push	rdi
	call	_ft_strlen
	mov		rdi, rax
	inc		rdi
	call	_malloc
	pop		rsi
	cmp		rax, 0
	je		fail

	push	rax
	mov		rdi, rsi
	call	_ft_strlen

	mov		rdx, rax
	pop		rdi
	call	_ft_memcpy
fail:
	ret
