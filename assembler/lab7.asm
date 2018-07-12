s_s segment stack			
dw 20 dup ($)			;определяем 20 знаков $ в сегменте стека
s_s ends

d_s segment
string db '(x*y)+7[3*z+12]-{dl}{','$'		;строка
result db ? ; ячейка для результата
d_s ends	

c_s segment
assume ss:s_s, ds:d_s, cs:c_s
begin:
mov ax, d_s
mov ds,ax
xor ax,ax

lea si, string			;загружаем в индексный регистр адрес начала строки
scan: lodsb			;метка scan: загружаем один символ из строки в AL
cmp si,20   			;сравниваем SI с 20(в десятичной системе счисления)
je exit1			;если равно, то переход на метку exit1
cmp al, '('			;сравниваем содержимое AL со открывающимис€  скобками
je push_b		;если равно, то переход на push_bracket
cmp al, '['
je push_b
cmp al, '{'
je push_b

cmp al, ')'			;сравниваем содержимое AL со закрывающимис€  скобками
je pop_b		;если равно, то переход на pop_bracket
cmp al, ']'
je pop_b
cmp al, '}'
je pop_b

jmp scan			

push_b:			;метка push_bracket
inc cx				;инкриминируем CX
push ax			;вталкиваем AX в стек
jmp scan

pop_b:			;метка pop_bracket
cmp cx,0			;сравниваем счетчик с нулем
jne f0			;если не равно, то переход на fff0
mov result,3			;заносим в ячейку результата 3
jmp exit1
f0: dec cx			;метка fff0: декреминируем CX
pop bx				;выталкиваем из стека в регистр BX значение
cmp bl,'('			;сравниваем содержимое BL со скобкой
jne f1			;если не равно, то переход на fff1
cmp al, ')'			;сравниваем AL со скобкой
je scan			;если равно, то переход на scan
f1: cmp bl,'['
jne f2
cmp al,']'
je scan
f2: cmp bl,'{'
jne f3
cmp al,'}'
je scan
f3: mov result,1		;метка fff3: заносим в ячейку результата 1
cmp cx,0			;сравниваем CX с нулем
je m2				;если равно, то переход на exit
jmp clean			;иначе переход на clean

exit1: cmp cx,0		;метка exit1: сравниваем CX с нулем
je exit				;если равно, то переход на exit
mov result,2			;заносим в ячейку результата 2

clean: pop ax			;метка clean: очищаем стек
loop clean
m2:
cmp result,1			;сравниваем результат с единицей
je b0			;если равно, то переход на bracket0
jmp exit			;иначе переход на exit
b0: cmp bl, '('		;метка bracket0: сравниваем содержимое BL со скобками	
je b1			;если равны, то переход на метки
cmp bl, '['
je b2
cmp bl, '{'
je b3
cmp al, ')'
je b4
cmp al, ']'
je b5
cmp al, '}'
je b6
jmp exit 

; если код ошибки = 1, т.е. не соответствие скобок
b1: mov dl, ')'		;заносим в DL код скобки
jmp exit 
b2: mov dl, ']'
jmp exit 
b3: mov dl, '}'
jmp exit 
b4: mov dl, '('
jmp exit 
b5: mov dl, '['
jmp exit 
b6: mov dl, '{'

exit: mov ah,4ch ; выход из программы
int 21h
c_s ends
end begin