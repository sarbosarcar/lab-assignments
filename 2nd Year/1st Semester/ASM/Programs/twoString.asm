.model small
.stack 100h
.code
.data
main proc 
	mov ax, @data
	mov ds, ax
	mov es, ax
	mov si, 0030h
	mov di, 0040h
	mov cl, [si]
	mov ch, 00h
	cld
l2:	cpmsb
	jnz l1
	loop l2
	mov ax, 0fffh
	jmp l3
l1:     mov ax, 111h
l3:	mov bx, 0050h
	mov [bx], ax
	int 03h
	mov ah, 4ch
	int 21h
main endp
end main