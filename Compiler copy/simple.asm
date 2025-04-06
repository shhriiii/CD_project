section .data
global result_holder, tempA
result_holder: dd 0
tempA: dd 0
tempB: dd 0
tempC: dd 0
tempD: dd 0
tempE: dd 0
tempF: dd 0
tempG: dd 0

section .text
global _start

_start:

square_and_add:
    ; Parameters: eax = number, ecx = value to add
    ; Result: eax = (eax * eax) + ecx
    push ebx
    mov ebx, eax      ; Store original number
    imul eax, eax     ; Square the number
    add eax, ecx      ; Add second argument
    pop ebx
    ret

    ; tempA = 4 * 1
    mov eax, 4
    imul eax, 1
    mov [tempA], eax

    ; tempB = 3 + tempA
    mov eax, 3
    add eax, [tempA]
    mov [tempB], eax

    ; tempC = tempB + 2
    mov eax, [tempB]
    add eax, 2
    mov [tempC], eax

    ; tempD = tempC + 5
    mov eax, [tempC]
    add eax, 5
    mov [tempD], eax

    ; tempE = 2 * 10
    mov eax, 2
    imul eax, 10
    mov [tempE], eax

    ; tempF = tempD - tempE
    mov eax, [tempD]
    sub eax, [tempE]
    mov [tempF], eax

    ; Now use the new function:
    ; tempG = (tempF * tempF) + 11
    mov eax, [tempF]
    mov ecx, 11
    call square_and_add
    mov [tempG], eax

    ; Exit using syscall
    mov eax, 1
    xor ebx, ebx
    int 0x80

