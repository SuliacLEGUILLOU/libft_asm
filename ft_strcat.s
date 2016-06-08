global _ft_strcat

section .text

_ft_strcat:
	push	rdi

loop:
	cmp		byte[rdi], 0x0
	je		copy
	inc		rdi
	jmp		loop

copy:
	cmp		byte[rsi], 0x0
	je		end
	movsb
	jmp		copy

end:
	mov		[rdi], byte 0x0
	pop		rax
	ret
