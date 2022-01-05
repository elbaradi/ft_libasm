; char	*ft_strdup(const char *s1);
;
; rdi = first argument (const char *s1)
; rax = return address (char *dup or NULL on error)
;------------------------------------------------
; rbp = base pointer (static)
;
; rsp = stack pointer (moves with pop/push/sub/add)

global _ft_strdup
extern _ft_strcpy
extern _ft_strlen
extern _malloc

section .text
_ft_strdup:
	prologue:
		; Creating register for base pointer, pointing to top of stack
		push	rbp					; (Stack is now also aligned)
		mov		rbp, rsp
		push	rbx					; Working space.
		push	r15					; Extra register for lazy 16-byte stack alignment.

	body:
	    call	_ft_strlen			; Stores len of s1 in rax.
		inc		rax					; +1 for the null terminating character.
		mov		rbx, rdi			; Saving s1 in rbx to make room for malloc call.
		mov		rdi, rax			; Storing dup size in rdi for malloc call.
		call	_malloc				; Stores the void pointer for the dup string in rax.
		jz		epilogue			; Jumps to epilogue if malloc return is NULL.
		mov		rsi, rbx			; Moves s1 to src parameter for strcpy call.
		mov		rdi, rax			; Moves dup to dest parameter for strcpy call.
		call	_ft_strcpy			; Copies src into dest, rax holds dup.
	
	epilogue:
		pop		r15
		pop		rbx
		pop		rbp
		ret