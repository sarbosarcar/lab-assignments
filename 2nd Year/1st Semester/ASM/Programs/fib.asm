dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov ds,ax
mov si,0030h
mov al,01h
mov bl,01h
mov cl,10h
mov dl,00h
l1:	mov [si],al
	mov dl,al
	mov al,bl
	add bl,dl
	inc si
	loop l1
int 03h
mov ah,4ch
int 21h
main endp
end main	

