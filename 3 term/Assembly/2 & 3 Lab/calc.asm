model small
.stack 100h
.data
dzieliva db "Dzieliva:        $"
dzielnik db "Dzielnik:        $"
nul_dzln db "Dzialennie na nul! Inszaja liczba:",10,13,'$'
dadzieny db "Uviadzicie dadzienyja!",10,13,'$'
dziel    db "Dziel:           $"
astacza  db "Astacza:         $"
cr_lf             db 0Ah,0Dh,'$'
bs                db 08h,'$'
cr                db 20h,'$'
bs_cr_bs          db 08h,20h,08h,'$'	;bs=08h,cr=20h
bs_cr_bs_bs_cr_bs db 08h,20h,08h,08h,20h,08h,'$'
cr_bs             db 20h,08h,'$'
b    dw 10
temp dw 1 
ind  dw 0
ind_alpha  dw 0
ind_first  dw 0
input_zero dw 0
ndigits dw 0
minus   dw 0
minus1  dw 0
minus2  dw 0
max_negative dd 32769
max_positive dd 32767
i dw ?
j dw ?

.code

output proc
	mov ind, 0
	next:
		cmp ax, 0
		jz ax_value_is_0

		xor dx, dx
		div b
		mov bx, dx   ; dx = 5, ax = 6553
					 ; bx = dx = 5
		add bl, '0'
		push bx
		inc ind
		inc ndigits

	jmp next

	ax_value_is_0:
		output_screen: 
			cmp ind, 0
			jz is_zero

			dec ind
			pop cx
			mov dl, cl
			mov ah, 02h
			int 21h

		jmp output_screen

		deleteminus:
			lea dx, bs_cr_bs  	; TEMP
			mov ah, 09h		 	; TEMP
			int 21h		 		; TEMP
		jmp after_deleteminus	; TEMP

	is_zero:
		cmp ndigits, 1  ;  check number of digits , if ndigits == 1 then 
		jz  isone		;  check value of variable , if ndigits == 0 then 
						;  output 0 else ret
		isone:
			cmp ax, 0
			jz iszero3

		jmp final
			iszero3:
				cmp minus1, 1    	; TEMP
				je deleteminus		; TEMP			!!!SEEEE TO HERE!!!!

				after_deleteminus: 	; TEMP

				mov dl, 48
				mov ah, 02h
				int 21h
		final:
	ret
output endp

input proc
	xor bx, bx
	mov ind, 0 
	mov ind_alpha, 0 

	mov ind_first,  0 
	mov input_zero, 0
	mov ndigits,    0
	mov minus,      0

	jmp pass

	escisminus:
		lea dx, bs_cr_bs  ;!!
		mov ah, 09h
		int 21h

		mov minus, 0

	escmore0:
		isesc_next:
		xor dx,dx

		cmp ind,0
		jz escis0

		lea dx, bs_cr_bs  ;!!
		mov ah, 09h
		int 21h

		dec ind
			
		cmp ind, 0
		jg escmore0

		escis0:
		cmp minus, 1
		jz escisminus

		mov ind_first, 0
	jmp endesc

	isesc:
		lea dx, bs_cr_bs
		mov ah, 09h
		int 21h

	jmp isesc_next

	overflow:
		dec ind
		dec ind_first
	jmp stackzero

	overflow1:
		sub cx, bx  ;new!
		dec ind
		dec ind_first
		mov ax, cx
		div b
		mov cx, ax
	jmp backoverflow1

	checkBXiszero:
		cmp bx, 0
		jz checkright
		jg checkunright

	checkunright:
		lea dx, bs_cr_bs_bs_cr_bs   ;!!!
		mov ah, 09h
		int 21h

		add bl, '0'
		mov dl, bl
		mov ah, 02h
		int 21h
		mov input_zero, 0
		sub bl, '0'
	jmp aftercheckunright

	isesc_middle:
		jmp isesc

	minusoverflow:
		cmp ax, 32768
		ja overflow  
		jmp notoverflow

	minusoverflow1:
		cmp ax, 32768
		ja overflow1
		jmp tonotoverflow
	nextposition:
		pop bx

		mov ax,10
		mul cx

		jo overflow
		;JNO notoverflow		

		cmp minus, 1
		jz minusoverflow

		cmp ax, 32767
		jg overflow 

		notoverflow:

		mov cx, ax
		;mov temp,cx

		;add temp,bx
		;mov ax,temp
		add cx, bx
		mov ax, cx
		;jc overflow1	
		
		cmp minus, 1
		jz minusoverflow1
		
		cmp ax, 32767
		ja overflow1

		tonotoverflow:
		;add cx,bx
	jmp ifnotoverflow

	checkbxiszero_middle:
	jmp checkBXiszero

	checkright:
		lea dx, bs_cr_bs   ;!!!
		mov ah, 09h
		int 21h
	jmp aftersecondzero

	nextposition_middle:
		jmp nextposition

	pass:
	back3:
	endesc:
		mov input_zero, 0
	input_screen:
	fromisminus:
		after_other_alpha:     
					backonepos:
						ifnotoverflow:
							aftersecondzero:
		xor ax, ax
		mov ah, 01h
		int 21h

		mov bl, al

		cmp bl, 45
		je isminus

		cmp bl, 27
		je isesc_middle

		cmp bl, 8
		je isbackspace

		cmp bl, 13
		jz isenter_middle

		cmp bl, 48
		jc smallerzero

		cmp bl, 57
		jg morenine

		sub bl, '0' 

		cmp input_zero, 1
		jz checkbxiszero_middle
		
		inc ind
		inc ind_first	
		aftercheckunright:
			push bx			

		cmp ind_first, 1
			jz oneposition
			jg nextposition_middle 

		back2:
	jmp input_screen

	smallerzero:
		morenine:
			stackzero:
				backoverflow1:
			lea dx, bs_cr_bs 
			mov ah, 09h
			int 21h

	jmp after_other_alpha

	isminus:
	cmp ind, 0
	jnz manyminus
	jmp isminus_middle

	isind0:
		cmp minus, 1
		jz firstminus

		mov ind_first, 0
		xor dx, dx
		mov dl, cr_bs
		mov ah, 02h
		int 21h
	jmp back3
	
	isenter_middle:
		jmp isenter				

	isbackspace:
		cmp ind, 0
		jz isind0

		lea dx, cr_bs
		mov ah, 09h
		int 21h

		xor dx, dx
		mov ax, cx
		div b
		mov cx, ax

		dec ind
		dec ind_first

		mov input_zero, 0
		inputzeroisone:
		waitdata:
		fromfirstminus:
	jmp back2

	oneposition:
	jmp oneposition_middle

	isminus_middle:
		cmp minus, 0
		jz fromonminus

		manyminus:

		lea dx, bs_cr_bs
		mov ah, 09h
		int 21h

		jmp fromisminus

		fromonminus:
		mov minus, 1
		jmp fromisminus

	firstminus:
		mov minus, 0

		lea dx, cr_bs
		mov ah, 09h
		int 21h

		jmp fromfirstminus

	isenter:
		cmp ind, 0 
		jz isenterindzero

		jmp labenter

		oneposition_middle:
			xor cx, cx
			pop bx
			cmp bx, 0
			jz BXis0			
			add cx, bx
		jmp backonepos

		isenterindzero:
			lea dx, dadzieny
			mov ah, 09h
			int 21h
		jmp waitdata

		input_deleteminus:				; TEMP
			lea dx, bs_cr_bs_bs_cr_bs	; TEMP
			mov ah, 09h					; TEMP
			int 21h						; TEMP

			mov minus, 0				; TEMP

			mov dl, 48					; TEMP
			mov ah, 02h					; TEMP
			int 21h						; TEMP
		jmp after_input_deleteminus		; TEMP

		BXis0:
			mov input_zero, 1
			cmp minus, 1				; TEMP
			je input_deleteminus		; TEMP

			after_input_deleteminus:	; TEMP
		jmp inputzeroisone			

		labenter:
			mov ax, cx
			xor cx, cx
	ret
input endp

dzialennie proc
	mov minus1, 0
	mov minus2, 0 

	jmp pass_idiv

	changesign:
		neg ax	
		mov minus1, 1
	jmp afterchange

	changesign2:
		neg ax
		mov minus2, 1
	jmp afterchange2

	pass_idiv:
	lea dx, dzieliva
	mov ah, 09h
	int 21h

	call input

	cmp minus, 1
	jz changesign

	afterchange:

	mov i, ax

	lea dx, dzielnik
	mov ah, 09h
	int 21h

	xor dx, dx

	jmp pass_bs_cr_bs_idiv

	inv_first_nums:
		neg i
	jmp after_first_minus

	inv_second_nums:
	cmp minus2, 1
	je after_out_minus
	inverse_second_num:
		neg j
	jmp after_out_minus

	outputminus:
		mov dl, '-'
		mov ah, 02h
		int 21h

	;cmp minus1,1
	;je inv_first_nums
	jmp inv_first_nums

	after_first_minus:

	cmp minus1, 1
	je inv_second_nums

	jmp after_out_minus

	out_neg_remainder:
		mov dl, '-'
		mov ah, 02h
		int 21h
	jmp to_out_remainder

	checkminus2:
	cmp minus2, 0
	jgE out_neg_remainder

	once_again_idiv:
		lea dx, nul_dzln
		mov ah, 09h
		int 21h
	
	pass_bs_cr_bs_idiv:
		call input
		cmp ax, 0
	jz once_again_idiv

	cmp minus, 1
	jz changesign2

	afterchange2:
	mov j, ax

	mov ax, i
	cwd
	idiv j
	mov j, dx
	mov i, ax
	
	lea dx, dziel
	mov ah, 09h
	int 21h

	xor ax, ax
	xor dx, dx
	mov ax, minus1
	mov dx, minus2
	cmp ax, dx
	jne outputminus

	cmp minus1, 1
	je inverse_second_num 

	after_out_minus:
	;//////////////////////////
	xor dx, dx
	mov ax, i

	call output
	
	mov dl, cr_lf
	mov ah, 02h
	int 21h
	
	lea dx, astacza
	mov ah, 09h
	int 21h
	;;;;;;;;;;;;;;;;;;;;;;;;;

	cmp minus1, 1 ;!!!
	jz checkminus2

	to_out_remainder:

	xor dx, dx
	mov ax, j
	call output

	ret
dzialennie endp


start:
	mov ax,@data
	mov DS,ax

	call dzialennie ; division signed/unsigned numbers

	mov ah, 4Ch
	int 21h
end start