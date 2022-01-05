; size_t	ft_strlen(const char *s);
;
; rdi = first argument (const char *s);
; rax = return address (len)
; rbp = base pointer (static)
; rbx = working memory for calculating return value (len)
;
; rsp = stack pointer (moves with pop/push/sub/add), needs to point to rax on programme exit

global _ft_strlen

section .text

; Stack visualization
; +----------+--------+--------+----------+------+----+--------+
; |  origin  | local  |  type  |   size   | from | to | offset |
; +----------+--------+--------+----------+------+----+--------+
; | rdi		 | s      | char * | 8 (ptr)  |    0 |  8 |     16 |
; | rax		 | len    | size_t | 8 (long) |    8 | 16 |      8 |
; | <rbp>	 | 		  |        |          |   16 | 24 |      0 |
; | <rbx>	 | 		  |        |          |   32 | 40 |     -8 |
; +----------+--------+--------+----------+------+----+--------+


_ft_strlen:
	prologue:
		; Creating register for base pointer, pointing to top of stack
		push	rbp
		mov		rbp, rsp

		; Saving live registers
		push	rbx

		; Storing argument in registers
		mov		rbx, 0

	loop:
		cmp		byte [rdi + rbx], 0	; Checking whether *(s + i) == 0
		je		epilogue			; Breaking from loop if *(s + i) == 0
		inc		rbx					; len++ (= i++)
		cmp		byte [rdi + rbx], 0	; Repeating eight times to limit jump calls
		je		epilogue
		inc		rbx
		cmp		byte [rdi + rbx], 0
		je		epilogue
		inc		rbx
		cmp		byte [rdi + rbx], 0
		je		epilogue
		inc		rbx
		cmp		byte [rdi + rbx], 0
		je		epilogue
		inc		rbx
		cmp		byte [rdi + rbx], 0
		je		epilogue
		inc		rbx
		cmp		byte [rdi + rbx], 0
		je		epilogue
		inc		rbx
		cmp		byte [rdi + rbx], 0
		je		epilogue
		inc		rbx
		jmp		loop

	epilogue:
		; Moving len from working memory to return address
		mov		rax, rbx

		; Cleaning up Stack
		pop		rbx
		pop		rbp

		; rsp points to the return address (rax)
		; Exiting function
		ret
