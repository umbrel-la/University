s_s segment stack			
dw 20 dup ($)			;���������� 20 ������ $ � �������� �����
s_s ends

d_s segment
string db '(x*y)+7[3*z+12]-{dl}{','$'		;������
result db ? ; ������ ��� ����������
d_s ends	

c_s segment
assume ss:s_s, ds:d_s, cs:c_s
begin:
mov ax, d_s
mov ds,ax
xor ax,ax

lea si, string			;��������� � ��������� ������� ����� ������ ������
scan: lodsb			;����� scan: ��������� ���� ������ �� ������ � AL
cmp si,20   			;���������� SI � 20(� ���������� ������� ���������)
je exit1			;���� �����, �� ������� �� ����� exit1
cmp al, '('			;���������� ���������� AL �� ��������������  ��������
je push_b		;���� �����, �� ������� �� push_bracket
cmp al, '['
je push_b
cmp al, '{'
je push_b

cmp al, ')'			;���������� ���������� AL �� ��������������  ��������
je pop_b		;���� �����, �� ������� �� pop_bracket
cmp al, ']'
je pop_b
cmp al, '}'
je pop_b

jmp scan			

push_b:			;����� push_bracket
inc cx				;������������� CX
push ax			;���������� AX � ����
jmp scan

pop_b:			;����� pop_bracket
cmp cx,0			;���������� ������� � �����
jne f0			;���� �� �����, �� ������� �� fff0
mov result,3			;������� � ������ ���������� 3
jmp exit1
f0: dec cx			;����� fff0: ������������� CX
pop bx				;����������� �� ����� � ������� BX ��������
cmp bl,'('			;���������� ���������� BL �� �������
jne f1			;���� �� �����, �� ������� �� fff1
cmp al, ')'			;���������� AL �� �������
je scan			;���� �����, �� ������� �� scan
f1: cmp bl,'['
jne f2
cmp al,']'
je scan
f2: cmp bl,'{'
jne f3
cmp al,'}'
je scan
f3: mov result,1		;����� fff3: ������� � ������ ���������� 1
cmp cx,0			;���������� CX � �����
je m2				;���� �����, �� ������� �� exit
jmp clean			;����� ������� �� clean

exit1: cmp cx,0		;����� exit1: ���������� CX � �����
je exit				;���� �����, �� ������� �� exit
mov result,2			;������� � ������ ���������� 2

clean: pop ax			;����� clean: ������� ����
loop clean
m2:
cmp result,1			;���������� ��������� � ��������
je b0			;���� �����, �� ������� �� bracket0
jmp exit			;����� ������� �� exit
b0: cmp bl, '('		;����� bracket0: ���������� ���������� BL �� ��������	
je b1			;���� �����, �� ������� �� �����
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

; ���� ��� ������ = 1, �.�. �� ������������ ������
b1: mov dl, ')'		;������� � DL ��� ������
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

exit: mov ah,4ch ; ����� �� ���������
int 21h
c_s ends
end begin