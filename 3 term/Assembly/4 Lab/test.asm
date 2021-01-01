.model small
.stack 100h
.data
    s       db  102     dup(?)
    pi      db  102     dup(0)
    yes     db  "yes$"
    no      db  "no$"
    sublen  dw  0
    len     dw  0
    symbol  db  ?

.code

read_char proc C near
arg outo:word
uses ax, bx
    mov bx, outo
    mov ah, 08h
    int 21h
    mov byte ptr [bx], al
    ret
endp

print_char proc C near
arg symbal:word
uses ax, dx
    mov ah, 02h
    mov dl, offset symbal
    int 21h
    ret
endp

print_string proc C near
arg string:word
uses ax, dx
    mov ah, 09h
    mov dx, string
    int 21h
    ret
endp

read_string proc C near
arg string:word, leng:word
uses ax, bx
    mov bx, string
    mov si, 0

    read_st:
        call read_char C, offset symbol
        cmp symbol, 13
        je cancel_reading

        cmp symbol, 10
        je cancel_reading

        mov al, symbol
        mov byte ptr [bx + si], al
        
        inc si
        call print_char C, word ptr symbol
        jmp read_st

    cancel_reading:
    mov byte ptr [bx + si], '$'
    
    mov bx, leng
    mov [bx], si
    ret
endp

print_enter proc C near
uses ax, dx
    mov ah, 02h
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h
    ret
endp

start:
    mov ax, @data
    mov ds, ax

    call read_string C, offset s, offset len
    mov cx, 0
    find_space:
        mov si, cx
        cmp s[si], ' '
        je found_space
        inc cx
        jmp find_space
    found_space:
    mov sublen, cx

    mov cx, len
    dec cx

    mov ax, 1
    mov bx, 0
    cycle:                      ; for (int i = 1; i < s.size(); i++) -- ax = i, bx = j
        mov si, word ptr ax
        dec si
        mov bl, pi[si]
        while_main:             ; while(j > 0 && s[j] != s[i])
            cmp bx, 0
            je while_main_break
        
            mov si, bx
            mov dl, s[si]
            mov si, ax
            cmp s[si], dl
            je while_main_break

            mov si, bx
            dec si
            mov bl, pi[si] 
            jmp while_main

        while_main_break:
        mov si, bx
        mov dl, s[si]
        mov si, ax
        cmp s[si], dl           ; if (s[j] == s[i])
        jne if_main_break
        inc bx
        if_main_break:
        mov si, ax
        mov pi[si], bl

        mov dl, byte ptr sublen
        cmp pi[si], dl
        je to_yes

        inc ax
        loop cycle

    call print_enter
    call print_string C, offset no
    mov ah, 4ch
    int 21h

    to_yes:
        call print_enter
        call print_string C, offset yes
        mov ah, 4ch
        int 21h

end start