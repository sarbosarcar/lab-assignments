dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov ds,ax
mov si,0040h
mov cx,0008h
mov bx,0000h
l3:	mov al,[si]
	rol al,01h
	jc l1
	inc bl
	jmp l2
	l1:	inc bh
	l2:	inc si
		loop l3
mov si,0040h
mov [si],bl
inc si
mov [si],bh
int 03h

mov ah,4ch
int 21h
main endp
end main	

