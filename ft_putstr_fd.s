%define SYSCALL(nb) 0x2000000 | nb
%define STDOUT		1
%define WRITE		4

global _ft_putstr_fd
extern _ft_strlen

section .data
null:
	.string		db "(null)", 10
	.len		equ $ - null.string

section .text

_ft_putstr_fd:
	cmp		rdi, 0x0
	je		is_null
	push	rdi
	call	_ft_strlen
	mov		rdi, rsi
	pop		rsi
	mov		rdx, rax
	mov		rax, SYSCALL(WRITE)
	syscall 
	ret

is_null:
	mov		rdi, rsi
	mov		rsi, [rel null.string]
	mov		rdx, null.len
	mov		rax, SYSCALL(WRITE)
	syscall
	ret
