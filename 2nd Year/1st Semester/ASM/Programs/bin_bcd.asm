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
mov dx,0000h
mov bl,[si]
mov cx,bl
l2:	cmp bl,00h
	jz l1
	dec bl
	mov al,dl
	add al,01h
	daa
	mov dl,al
	mov al,dh
	adc al,00h
	daa
	mov dh,al
	loop l2
l1:	mov [di],dx
int 03h
mov ah, 4ch
int 21h
main endp
end main