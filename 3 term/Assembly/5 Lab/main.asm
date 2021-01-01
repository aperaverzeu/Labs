.model small
.stack 100h
.data
n dw 0
i dw 0
j dw 0
k dw 0
temp dw 0
arrayOne dw 202 dup(?)
arrayTwo dw 202 dup(?)
result   dw 202 dup(?)
space    dw 32
const10  dw 10d

.code
include lib.asm


get_index proc C near
arg ii, jj, nn : word
uses ax
    mov ax, ii

    call print_uint16 C, ax
    call print_char C, space

    mul byte ptr nn

    call print_uint16 C, ax
    call print_char C, space

    add ax, jj

    call print_uint16 C, ax
    call print_char C, space

    mov bx, 2d
    mul bx

    call print_uint16 C, ax
    call print_enter

    mov si, ax
    ret
endp

start:
mov ax, @data
mov ds, ax

call read_uint16
call print_enter
mov n, ax
mov i, 0
i_loop_one:
    mov j, 0
    j_loop_one:
        call read_uint16
        call get_index C, i, j, n
        mov arrayOne[si], ax
        call print_char C, space

        inc j
        mov ax, n
        cmp j, ax
        jne j_loop_one
    end_j_loop_one:
    call print_enter

    inc i
    mov ax, n
    cmp i, ax
    jne i_loop_one
end_i_loop_one:

call print_enter

; input cycle 2
mov i, 0
i_loop_two:
    mov j, 0
    j_loop_two:
        call read_uint16
        call get_index C, i, j, n ; index in si
        mov arrayTwo[si], ax
        call print_char C, space ;DELETE BEFORE SENDING


        inc j
        mov ax, n
        cmp j, ax ; cmp j, n
        jne j_loop_two
    end_j_loop_two:
    call print_enter ; DELETE BEFORE SENDING

    inc i
    mov ax, n
    cmp i, ax
    jne i_loop_two
end_i_loop_two:

; mul[][] is 0
mov i, 0
i_loop_mul_nul:
    mov j, 0
    j_loop_mul_nul:
        call get_index C, i, j, n ; index in si
        mov ax, 0
        mov result[si], 0

        inc j
        mov ax, n
        cmp j, ax ; cmp j, n
        jne j_loop_mul_nul
    end_j_loop_mul_nul:
    call print_enter ; DELETE BEFORE SENDING

    inc i
    mov ax, n
    cmp i, ax
    jne i_loop_mul_nul
end_i_loop_mul_nul:


mov i, 0
i_loop_alg:
  mov j, 0
  j_loop_alg:
    mov k, 0
    k_loop_alg:

      call get_index C, i, k, n
      mov ax, arrayOne[si]

      ; call print_uint16 C, ax
      ; call print_char C, space

      call get_index C, k, j, n
      mov bx, arrayTwo[si]

      ; call print_uint16 C, bx
      ; call print_char C, space

      mul bx

      ; call print_uint16 C, ax
      ; call print_char C, space

      mov temp, ax            ; temp = a*b
      call get_index C, i, j, n
      mov ax, temp

      ; call print_uint16 C, result[si]
      ; call print_char C, space

      add ax, result[si]

      ; call print_uint16 C, ax
      ; call print_char C, space

      mov result[si], ax

      ; call print_enter

      jmp continue

i_loop_alg_trans:
jmp i_loop_alg
j_loop_alg_trans:
jmp j_loop_alg
k_loop_alg_trans:
jmp k_loop_alg

      continue:

      inc k
      mov ax, n
      cmp k, ax
      jne k_loop_alg_trans
      end_k_loop_alg:

    inc j
    mov ax, n
    cmp j, ax
    jne j_loop_alg_trans
  end_j_loop_alg:

  inc i
  mov ax, n
  cmp i, ax
  jne i_loop_alg_trans
end_i_loop_alg:

call print_enter

mov i, 0
i_loop2:
    mov j, 0
    j_loop2:
        call get_index C, i, j, n
        call print_uint16 C, result[si]
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

mov ah, 4ch
int 21h

end start
