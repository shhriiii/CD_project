section .data
global x, t1
x: dd 0
t1: dd 0
t2: dd 0
t3: dd 0
t4: dd 0
t5: dd 0
t6: dd 0
t7: dd 0

section .text
global _start

_start:

_pow:
    ; Input: eax = base, ecx = exponent
    ; Output: eax = result
    push ebx
    mov ebx, eax
    mov eax, 1
    cmp ecx, 0
    je .pow_end
.pow_loop:
    imul eax, ebx
    dec ecx
    jnz .pow_loop
.pow_end:
    pop ebx
    ret

    ; t1 = 3 + 4
    mov eax, 3
    add eax, 4
    mov [t1], eax

    ; t2 = 1 + 2
    mov eax, 1
    add eax, 2
    mov [t2], eax

    ; t3 = t1 * t2
    mov eax, [t1]
    imul eax, [t2]
    mov [t3], eax

    ; t4 = 5 - 2
    mov eax, 5
    sub eax, 2
    mov [t4], eax

    ; t5 = 10 + 11
    mov eax, 10
    add eax, 11
    mov [t5], eax

    ; t6 = t4 * t5
    mov eax, [t4]
    imul eax, [t5]
    mov [t6], eax

    ; t7 = t3 + t6
    mov eax, [t3]
    add eax, [t6]
    mov [t7], eax

    ; Exit program
    mov eax, 1
    xor ebx, ebx
    int 0x80
