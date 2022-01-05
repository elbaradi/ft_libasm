; ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
;
; rdx = third argument (size_t nbyte)
; rsi = second argument (const void *buf)
; rdi = first argument (int fildes)
; rax = return address (ssize_t nbyte_written or -1 on error)
;------------------------------------------------
; rbp = base pointer (static)
;
; rsp = stack pointer (moves with pop/push/sub/add)

global _ft_write
extern ___error

section .text
_ft_write:
	prologue:
		; Creating register for base pointer, pointing to top of stack
		push	rbp
		mov		rbp, rsp

		push	rbx					; Reserving working space.
		push	r15					; Lazy push for necessary 16-byte stack alignment.

	body:
	    mov		rax, 0x2000004		; Write = 4. Syscall uses a 0x2000000 offset for Unix/BSD system calls (http://dustin.schultz.io/mac-os-x-64-bit-assembly-system-calls.html)
        syscall						; rdx, rsi and rdi already contain the correct variables for the syscall.
        jc		error				; Okay so for Linux rax = 0 - errno (and we would simply check whether rax is negative (js)),
									; but apparently for MacOS rax = errno. So how then can we tell whether the write syscall returned an error?
									; I haven't found any official documentation, but Aristotelis mentions here that a syscall error sets the carry flag:
									; https://github.com/cacharle/libasm_test/issues/2. This seems to be the common solution among 42 students so I'll just roll with it. 
	
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
		pop		r15
		pop		rbx
		pop		rbp
		ret
