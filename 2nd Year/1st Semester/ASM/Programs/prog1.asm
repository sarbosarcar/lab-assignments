.model small
.stack 100h
.data
var db "Hello World$"
.code
main proc

mov ax, @data
mov dx, ax
lea dx, var
mov ah, 09h
int 21h
mov ah, 4ch
int 21h

main endp
end main