; ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
;
; rdx = third argument (size_t nbyte)
; rsi = second argument (void *buf)
; rdi = first argument (int fildes)
; rax = return address (ssize_t nbyte_read or -1 on error)
;------------------------------------------------
; rbp = base pointer (static)
;
; rsp = stack pointer (moves with pop/push/sub/add)

global _ft_read
extern ___error

section .text
_ft_read:
	prologue:
		; Creating register for base pointer, pointing to top of stack
		push	rbp
		mov		rbp, rsp

		push	rbx					; Reserving working space.
		push	r15					; Lazy push for necessary 16-byte stack alignment.

	body:
	    mov		rax, 0x2000003		; Read = 3. Syscall uses a 0x2000000 offset for Unix/BSD system calls (http://dustin.schultz.io/mac-os-x-64-bit-assembly-system-calls.html)
        syscall						; rdx, rsi and rdi already contain the correct variables for the syscall.
        jc		error				; Jump if carry flag is set.
	
	epilogue:
		pop		r15
		pop		rbx
		pop		rbp
		ret
	
	error:
		mov		rbx, rax			; Stores the encountered errno value in rbx.
		call	___error			; Returns the address of the actual errno variable in rax.
		mov		[rax], rbx			; Stores the errno value in the address contained by rax.
		mov		rax, -1				; Overwrites the current value of rax (errno address) with -1, the return value.
		pop		r15					; Repeating the epilogue to not make an unnecessary jump.
		pop		rbx
		pop		rbp
		ret
