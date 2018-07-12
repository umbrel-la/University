patient struc                    ;объявляем структуру с именем patient
	card dw 0 ; номер карты
	pol db ?          ; пол
	born dw 0         ; год рождения
	date_in db '  /  /    '  ; дата поступления
	date_out db '  /  /    '  ; дата выписки
patient ends

d_s segment
	mas patient <25, 'M', 1980, '16/02/1999', '25/02/1999'>, <40, 'W', 1996, '16/02/1999', '15/03/1999'>, <322, 'M', 2000, '21/03/2005', '21/05/2005'> ; массив на 3 структуры
	i_3 db 0 ; три разных счетчика (3,4,6 задания соответственно)
	i_4 db 0
	i_6 db 0
	i_3_1 db 0
	i_4_1 db 0
	i_6_1 db 0
	date db '16/02/1999'  ; даты для сравнения
	date1 db '15/03/1999'  ;
	polM db 'M'
	polW db 'W'
	born_r dw 2000   ; год рождения (для сравнения)
	card_r dw 40 ; номер карты (для сравнения)
d_s ends 

assume ds:d_s, cs:c_s

c_s segment
begin:
mov ax,d_s
mov ds,ax
	
lea bx, mas       ; в bx занесли адрес начала масива

mov cx, 3                  ; цикл на 3 итерации по поиску количества больных поступивших на определенную дату
mov si, (type patient)*0
m1:
	mov ax, cx
	mov cx,10
	mov di, 0
	m1_1:
		cmp date[di], [bx][si].date_in[di]
		je m1_1_1
			mov cx,cx
		m1_1_1:
				inc i_3
				add di, 1
	loop m1_1
	cmp i_3, 10
	je ms
	jmp mv
		ms: 
			inc i_3_1
		mv:
			mov cx,ax
			add si, (type patient)
loop m1

mov cx, 3; Внемлите   
mov si, (type patient)*0
m2:
   mov al, [bx][si].pol
   cmp al, polW
   jne zcikl_2 ;//SUDA TIKAT CIKL если не равны то на завершение итерации, если равны (условие ложь), то идти дальше по порядкуx
	mov dx, cx
	mov cx,10
	mov di, 0
	m2_1:
		cmp date1[di], [bx][si].date_out[di]
		je m2_1_1
			mov cx,cx
		m2_1_1:
				inc i_4
				add di, 1
	loop m2_1
	cmp i_4, 10
	je mess
	jmp zcikl_2
		mess: 
			inc i_4_1
	    zcikl_2:
	        mov cx,dx
	        add si, (type patient)
loop m2

mov cx, 3; Намана все и тут
mov si, (type patient)*0
m3:
   mov ax, [bx][si].card
   cmp card_r, ax
   je result
   jmp zcikl_3
   result:
         mov ax, [bx][si].born
		 mov cx, cx                   ; делаем обнуление регистра сх при нахождении нужного нам года по номеру карты, т.к. нам больше не надо будет идти по циклу, следовательно обнулив сх мы выйдем из цикла
   zcikl_3:
           add si, (type patient)
loop m3

mov cx, 3 ; Намана тут все
mov si, (type patient)*0
m4:
   mov al, [bx][si].pol
   cmp al, polM
   jne zcikl_4 ; если не равны то на завершение итерации, если равны (условие ложь), то идти дальше по порядку
	 mov ax, [bx][si].born
	 cmp ax, born_r
	  je minc_3
	  jmp zcikl_4
	  minc_3:
		     inc i_6
	  zcikl_4:
		      add si, (type patient)
loop m4

    mov ah, 4ch
    int 21h       
c_s ends
end begin