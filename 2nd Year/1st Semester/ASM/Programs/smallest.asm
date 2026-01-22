dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,@data
mov ds,ax
mov si,0030h
mov cx,0006h
mov di,0040h
mov al,[si]
l1:    inc si
       cmp al,[si]
       jc l2
       mov al,[si]
l2:    loop l1
mov [di],al
int 03h
mov ah,4ch
int 21h
main endp
end main