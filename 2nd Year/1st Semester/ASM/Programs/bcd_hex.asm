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
mov al,[si]
mov bl,al
and al,0f0h
mov cl,04h
ror al,cl
mov dl,0ah
mul dl
mov dx,ax
mov al,bl
and al,0fh
mov ah,00h
add ax,dx
mov [di],ax
int 03h
mov ah, 4ch
int 21h
main endp
end main