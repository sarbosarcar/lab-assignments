dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov ds,ax
mov si,0030h
mov di,0040h
mov bx,0000h
mov ax,0000h
mov al,[si]
mov cx,[si]
mov bl,al
l1:	
	dec bl
	cmp bl,00h
	jz l2
	mul bx
	mov dx,ax
	loop l1
l2:	mov [di],dx
int 03h
mov ah, 4ch
int 21h
main endp
end main