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
mov bl, var1
mov cl, var2
sub bl, cl
js l1
jmp l2

l1:
mov dl, '-'
mov ah, 02h
int 21h
neg bl
l2:
mov dl, bl
add dl, 30h
mov ah, 02h
int 21h
mov ah, 4ch
int 21h
main endp
end main