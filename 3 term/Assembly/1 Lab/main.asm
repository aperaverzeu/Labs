.model small
.stack 100h
.data
	a dw 1
	b dw 2
	c dw 3
	d dw 4
.code
main:
	mov ax, @data
	mov ds, ax

	mov ax, a
	and ax, d
	mov bx, b
	add bx, c
	jc else_main

	cmp ax, bx
	jnz else_main
		mov ax, a
		xor ax, b
		mov bx, b
		or  bx, d

		add ax, bx
        ; print((a^b)+(b|d))a
		jmp continue
	else_main:
		mov ax, b
		and ax, d
		mov bx, b
          add bx, c
		jc else_incidental

		cmp ax, bx
		jnz else_incidental
			mov ax, a
			or  ax, c
			mov bx, b
			xor bx, d
               or  ax, bx
			jmp continue
		else_incidental:
			mov ax, a
			add ax, c
			mov bx, b
			add bx, d
			and ax, bx
	continue:

	mov ax, 4c00h
	int 21h
end main
