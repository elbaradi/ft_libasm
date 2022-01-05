; char	*ft_strcpy(char *dst, const char *src);
;
; rsi = second argument (const char *src)
; rdi = first argument (char *dst)
; rax = return address (char *dst)
;------------------------------------------------
; rbp = base pointer (static)
; rbx = index
; r13 = tmp
;
; rsp = stack pointer (moves with pop/push/sub/add)

global _ft_strcpy

section .text

_ft_strcpy:
	prologue:
		; Creating register for base pointer, pointing to top of stack
		push	rbp
		mov		rbp, rsp

		; Reserving space for index and tmp
		push	rbx
		push	r13

		; Setting destination address as return, and index to zero
		mov		rax, rdi
		mov		rbx, 0

		; Checking for null pointer
		cmp		rsi, 0
		je		epilogue

	loop:
		mov		r13b, byte [rsi + rbx]	; Copying src char into 'tmp' register
		mov		byte [rdi + rbx], r13b	; Copying char from 'tmp' register into dst
		cmp		r13b, 0					; Checking whether *(src + i) == 0
		je		epilogue				; Breaking from loop if *(src + i) == 0
		inc		rbx						; i++
		; + - + - + - + - + - + - + - + ;
		mov		r13b, byte [rsi + rbx]	; Repeating eight times to limit jump calls
		mov		byte [rdi + rbx], r13b
		cmp		r13b, 0	
		je		epilogue
		inc		rbx
		mov		r13b, byte [rsi + rbx]
		mov		byte [rdi + rbx], r13b
		cmp		r13b, 0
		je		epilogue
		inc		rbx
		mov		r13b, byte [rsi + rbx]
		mov		byte [rdi + rbx], r13b
		cmp		r13b, 0
		je		epilogue
		inc		rbx
		mov		r13b, byte [rsi + rbx]
		mov		byte [rdi + rbx], r13b
		cmp		r13b, 0
		je		epilogue
		inc		rbx
		mov		r13b, byte [rsi + rbx]
		mov		byte [rdi + rbx], r13b
		cmp		r13b, 0
		je		epilogue
		inc		rbx
		mov		r13b, byte [rsi + rbx]
		mov		byte [rdi + rbx], r13b
		cmp		r13b, 0
		je		epilogue
		inc		rbx
		mov		r13b, byte [rsi + rbx]
		mov		byte [rdi + rbx], r13b
		cmp		r13b, 0
		je		epilogue
		inc		rbx
		jmp		loop

	epilogue:
		; Cleaning up Stack
		pop		r13
		pop		rbx
		pop		rbp

		; rsp points to the return address (rax)
		; Exiting function
		ret
