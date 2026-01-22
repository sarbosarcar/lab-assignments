dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov es,ax
mov ds,ax
mov si,0030h
mov di,0040h
mov cl,[si]
mov ch,00h
cld
l2:	cmpsb
	jnz l1
	loop l2
	mov ax,0ffffh
	jmp l3
l1:	mov ax,1111h
l3:	mov bx,0050h
	mov [bx],ax
	int 03h
mov ah,4ch
int 21h
main endp
end main