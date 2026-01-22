dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov ds,ax
mov si,0030h
mov di,0030h
mov ax,0000h
add al,[si]
dec al
add di,al
mov bl,02h
div bl
mov cl,al
mov ch,00h
inc si
cld
l2:	mov al,[di]
	cmp al,[si]
	jnz l1
	inc si
	dec di
	loop l2
	mov ax,0ffffh
	jmp l3
l1:	mov ax,1111h
l3:	mov bx,0040h
	mov [bx],ax
	int 03h
mov ah,4ch
int 21h
main endp
end main