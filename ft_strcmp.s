; int	ft_strcmp(const char *s1, const char *s2);
;
; rsi = second argument (const char *s2)
; rdi = first argument (const char *s1)
; rax = return address (int diff)
;------------------------------------------------
; rbp = base pointer (static)
; rbx = index
; r13 = return (working memory)
;
; rsp = stack pointer (moves with pop/push/sub/add)

global _ft_strcmp

section .text

_ft_strcmp:
	prologue:
	; Creating register for base pointer, pointing to top of stack
	push	rbp
	mov		rbp, rsp

	; Reserving space for index and tmp
	push	rbx
	push	r13

	; Setting index and tmp to zero
	mov		rbx, 0
	mov		r13, 0

	loop:
		movzx	r13, byte [rsi + rbx]	; Moving *(s2 + i) to tmp
		cmp		byte [rdi + rbx], r13b	; Checking whether *(s1 + i) == *(s2 + i)
		jne		epilogue				; Breaking from loop if *(s1 + i) != *(s2 + i)
		cmp		byte [rdi + rbx], 0		; Checking whether *(s1 + i) == 0
		je		epilogue				; Breaking from loop if *(s1 + i) == 0
		cmp		byte [rsi + rbx], 0		; Checking whether *(s2 + i) == 0
		je		epilogue				; Breaking from loop if *(s2 + i) == 0
		inc		rbx						; i++
		; + - + - + - + - + - + - + - + ; Repeating eight times to limit jump calls
		movzx	r13, byte [rsi + rbx]
		cmp		byte [rdi + rbx], r13b
		jne		epilogue
		cmp		byte [rdi + rbx], 0
		je		epilogue
		cmp		byte [rsi + rbx], 0	
		je		epilogue
		inc		rbx
		movzx	r13, byte [rsi + rbx]
		cmp		byte [rdi + rbx], r13b
		jne		epilogue
		cmp		byte [rdi + rbx], 0
		je		epilogue
		cmp		byte [rsi + rbx], 0	
		je		epilogue
		inc		rbx
		movzx	r13, byte [rsi + rbx]
		cmp		byte [rdi + rbx], r13b
		jne		epilogue
		cmp		byte [rdi + rbx], 0
		je		epilogue
		cmp		byte [rsi + rbx], 0	
		je		epilogue
		inc		rbx
		movzx	r13, byte [rsi + rbx]
		cmp		byte [rdi + rbx], r13b
		jne		epilogue
		cmp		byte [rdi + rbx], 0
		je		epilogue
		cmp		byte [rsi + rbx], 0	
		je		epilogue
		inc		rbx
		movzx	r13, byte [rsi + rbx]
		cmp		byte [rdi + rbx], r13b
		jne		epilogue
		cmp		byte [rdi + rbx], 0
		je		epilogue
		cmp		byte [rsi + rbx], 0	
		je		epilogue
		inc		rbx
		movzx	r13, byte [rsi + rbx]
		cmp		byte [rdi + rbx], r13b
		jne		epilogue
		cmp		byte [rdi + rbx], 0
		je		epilogue
		cmp		byte [rsi + rbx], 0	
		je		epilogue
		inc		rbx
		movzx	r13, byte [rsi + rbx]
		cmp		byte [rdi + rbx], r13b
		jne		epilogue
		cmp		byte [rdi + rbx], 0
		je		epilogue
		cmp		byte [rsi + rbx], 0	
		je		epilogue
		inc		rbx
		movzx	r13, byte [rsi + rbx]
		cmp		byte [rdi + rbx], r13b
		jne		epilogue
		cmp		byte [rdi + rbx], 0
		je		epilogue
		cmp		byte [rsi + rbx], 0	
		je		epilogue
		inc		rbx
		jmp		loop

	epilogue:
		; Calculating return based on current index
		movzx	rax, byte [rdi + rbx]
		sub		rax, r13

		; Cleaning up Stack
		pop		r13
		pop		rbx
		pop		rbp

		; All registers have been popped, rsp points to the return address (rax)
		; Exiting function
		ret
	
