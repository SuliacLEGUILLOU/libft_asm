global _ft_tolower

section .text

_ft_tolower:
	mov		rax, rdi
	cmp		rdi, 65
	jl		end
	cmp		rdi, 90
	jg		end
	add		rax, 32

end:
	ret
