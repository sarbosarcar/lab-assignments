dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov es,ax
mov di,0030h
mov ds,ax
mov si,0040h
mov cx,0008h
mov ah,00h
mov al,55h
cld
l2:	scasb
	jnz l1
	dec di
	inc ah
	inc di
	l1:	loop l2
mov [si], ah
int 03h
mov ah,4ch
int 21h
main endp
end main