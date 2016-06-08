%define SYSCALL(nb) 0x2000000 | nb
%define STDOUT		1
%define WRITE		4

global _ft_putstr
extern _ft_strlen

section .data
null:
	.string		db "(null)", 10
	.len		equ $ - null.string

section .text

_ft_putstr:
	cmp		rdi, 0x0
	je		is_null
	mov		rsi, rdi
	call	_ft_strlen
	mov		rdi, STDOUT
	mov		rdx, rax
	mov		rax, SYSCALL(WRITE)
	syscall 
	mov		rax, 10
	ret

is_null:
	mov		rdi, STDOUT
	mov		rsi, [rel null.string]
	mov		rdx, null.len
	mov		rax, SYSCALL(WRITE)
	syscall
	mov		rax, 10
	ret
