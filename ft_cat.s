%define SYSCALL(nb)	0x2000000 | nb
%define STDOUT		1

%define WRITE		4
%define READ		3

global _ft_cat

section	.bss
buff:	resb 42

section .text

_ft_cat:
	push	rdi

loop:
	mov		rdi, [rsp]
	mov		rax, SYSCALL(READ)
	lea		rsi, [rel buff]
	mov		rdx, 42
	syscall
	jc		end
	cmp		rax, 0
	je		end

	mov		rdx, rax
	lea		rsi, [rel buff]
	mov		rdi, STDOUT
	mov		rax, SYSCALL(WRITE)
	syscall
	jmp	loop

end:
	add		rsp, 8
	ret
