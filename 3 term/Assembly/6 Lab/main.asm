.model small
.stack 100h
.data
n dw 0
i dw 0
j dw 0
max   dw 0
array dw 202 dup(?)
space dw 32
const10 dw 10d
.code
include lib.asm


get_index proc C near
arg ii, jj, nn : word
uses ax
    mov ax, ii
    mul byte ptr nn
    add ax, jj
    mov bx, 2d
    mul bx
    mov si, ax
    ret
endp

start:
mov ax, @data
mov ds, ax

call read_uint16 ; response in ax
call print_enter ; DELETE BEFORE SENDING
mov n, ax
mov i, 0
i_loop:
    mov j, 0
    j_loop:
        call read_uint16
        call get_index C, i, j, n ; index in si
        mov array[si], ax
        call print_char C, space ;DELETE BEFORE SENDING


        inc j
        mov ax, n
        cmp j, ax ; cmp j, n
        jne j_loop

    end_j_loop:
    call print_enter ; DELETE BEFORE SENDING

    inc i
    mov ax, n
    cmp i, ax
    jne i_loop
end_i_loop:

call get_index C, 0, 0, n
mov ax, array[si]
mov max, ax

mov i, 0
i_loop_alg:
  mov j, 0
  j_loop_alg:
    call get_index C, i, j, n
    mov ax, max

    cmp array[si], ax
    jb continue
    mov ax, array[si]
    mov max, ax
    continue:

    inc j
    mov ax, n
    cmp j, ax
    jne j_loop_alg

  end_j_loop_alg:

  inc i
  mov ax, n
  cmp i, ax
  jne i_loop_alg

end_i_loop_alg:

call print_enter

mov i, 0
i_loop2:
    mov j, 0
    j_loop2:
        call get_index C, i, j, n
        call print_uint16 C, array[si]
        call print_char C, space

        inc j
        mov ax, n
        cmp j, ax
        jne j_loop2

    end_j_loop2:
    call print_enter
    inc i
    mov ax, n
    cmp i, ax

    jne i_loop2
end_i_loop2:

call print_enter
call print_uint16 C, max

mov ah, 4ch
int 21h

end start
