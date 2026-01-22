dosseg
.model small
.stack 100h
.data
var1 db 02h
var2 db 04h
.code
main proc
mov ax, @data
mov ds, ax
mov al, var1
mov ah, var2
add al, ah
mov dl, al
add dl, 30h
mov ah, 02h
int 21h
int 3
mov ah, 4ch
int 21h
main endp
end main