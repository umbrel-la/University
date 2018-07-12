d_s segment
a db 10
b db 27
sum db 0
d_s ends
c_s segment
assume ds:d_s, cs:c_s
begin:
 mov ax, d_s
 mov ds, ax
 mov ah,a
 mov al,b
 neg al
 sub ah,al
 mov sum,ah
 mov ah, 4ch
 int 21h
c_s ends
end begin