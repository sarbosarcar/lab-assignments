dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov ds,ax
mov si,0030h
mov al,[si]
mov bl,01h
mov cl,00h
l2:	sub al,bl
	js l1
	inc cl
	add bl,02h
	jmp l2
l1:	add al,bl
	mov si,0040h
	mov [si],cl
int 03h
mov ah,4ch
int 21h
main endp
end main	

