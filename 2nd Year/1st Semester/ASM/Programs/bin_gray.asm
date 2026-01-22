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
mov dl,[si]
clc
rcr al,01
xor al,dl
mov [di],al
int 03h
mov ah, 4ch
int 21h
main endp
end main