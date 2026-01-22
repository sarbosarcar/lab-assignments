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
mov ah,al
mov cl,04h
and al,0fh
cmp al,0ah
jc l1
add al,07h
l1:	add al,30h
mov bx,0050h
mov [bx],al
mov al,ah
and al,0f0h
rol al,cl
cmp al,0ah
jc l2
add al,07h
l2:	add al,30h
	inc bx
	mov [bx],al
int 03h
mov ah,4ch
int 21h
main endp
end main	

