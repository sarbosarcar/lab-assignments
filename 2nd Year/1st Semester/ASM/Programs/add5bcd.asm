dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov ds,ax
mov ax,0000h
mov bx,0000h
mov si,0030h
mov di,0040h
mov cx,0005h
l1:
	add al,[si]
	daa
	jnc l2
	inc bl
	l2:
		inc si
	loop l1
mov [di],al
inc di
mov [di],bl
int 03h
mov ah,4ch
int 21h
main endp
end main	