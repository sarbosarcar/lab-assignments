.model small
.stack 100h
.data
.code
main proc
mov ax, @data
mov ds, ax
mov si, 0030h
mov al, [si]
neg al  ; or use (not al) followed by (add al, 01)
mov si, 0040h
add al, [si]
jc l1
not al
inc al
mov si, 0050h
mov [si], al
jmp l2
l1:
mov si, 0050h
mov [si], al
cmc

l2:
mov ah, 00
adc ah, ah
inc si
mov [si], ah
int 3
mov ah, 4ch
int 21h
main endp
end main





