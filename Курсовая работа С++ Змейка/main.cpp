

#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include "game.h"

#define ROWS 40.0
#define COLUMNS 40.0

std::ofstream ofile;
std::ifstream ifile;
bool game_over=false;
int direction;
int score=0;

void init();
void display_callback();
void input_callback(int,int,int);
void reshape_callback(int,int);
void timer_callback(int);

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    // Режим отображения (ДВОЙНАЯ БУФЕРИЗАЦИЯ ОКНА)(RGBA)
    // ДЛЯ устранения мерцания при быстрой перерисовке окна
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    // положение появления окна 10 px сверзу 10 px слева
    glutInitWindowPosition(10,10);
    // размер окна
    glutInitWindowSize(600,600);
    // заголовок окна
    glutCreateWindow("SNAKE v1.0 - Kubarev");
    
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutSpecialFunc(input_callback);
    glutTimerFunc(100,timer_callback,0);
    init();
    // главный цикл openGl
    glutMainLoop();
    return 0;
}

void init()
{
	// цвет очистки окна - каким цветом будет наше окно
    glClearColor(0.0,0.0,0.0,0.0);
    // инициализируем сетку 40 x 40 (размер)
    initGrid(COLUMNS,ROWS);
}

//Callbacks
void display_callback()
{
    if(game_over)
    {
        ofile.open("score.dat",std::ios::trunc);
        ofile<<score<<std::endl;
        ofile.close();
        ifile.open("score.dat",std::ios::in);
        char a[4];
        ifile>>a;
        std::cout<<a;
        char text[50]= "Your score : ";
        strcat(text,a);
        MessageBox(NULL,text,"Game Over",0);
        exit(0);
    }
    // Очистка окна - в качестве параметра значение какой буфер нужно очистить
    // GL_COLOR_BUFFER_BIT - очистка буфера цвета
    glClear(GL_COLOR_BUFFER_BIT);
    // очищаем матрицу - функция заменяет текущую матрицу на единичную
    glLoadIdentity();
	// рисуем сетку
    draw_grid();
    // рисуем еду
    draw_food();
    // рисуем змейку
    draw_snake();
    // переключаем буфер в режим двойной буферизации
    /*функция выполняет очистку конвеера OpenGl и переключение буферов(помещяет скрытое визуализированное изображение на экран)*/
    glutSwapBuffers();
}
void reshape_callback(int w, int h)
{
	/* ОПРЕДЕЛЯЕМ ЗНАЧЕНИЕ ПОРТА ВЫВОДА */
	
	// определяем куда будет визуализироваться модель
    glViewport(0,0,(GLfloat)w,GLfloat(h));
    
    /*НАСТРОЙКА ПРОЕКЦИИ*/
    // Задаем матричный режим
    /*Будет определена матрица над которой будут производиться операции*/
    // GL_PROJECTION - Матрица проекций
    glMatrixMode(GL_PROJECTION); 
    
    /*ОЧИЩАЕМ МАТРИЦУ*/
    // Функция заменяет заменяет текущую матрицу на единичную
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    /*УСТАНАВЛИВАЕМ ОБЪЕКТНО ВИДОВУЮ МАТРИЦУ*/
    glMatrixMode(GL_MODELVIEW);
    // очищаем матрицу - функция заменяет текущую матрицу на единичную
    glLoadIdentity();
}
void timer_callback(int)
{
	// перерисовывае окна 
    glutPostRedisplay();
    glutTimerFunc(100,timer_callback,0);
}
void input_callback(int key,int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if(direction!=DOWN)
            direction=UP;
        break;
    case GLUT_KEY_DOWN:
        if(direction!=UP)
            direction=DOWN;
        break;
    case GLUT_KEY_RIGHT:
        if(direction!=LEFT)
            direction=RIGHT;
        break;
    case GLUT_KEY_LEFT:
        if(direction!=RIGHT)
            direction=LEFT;
        break;
    }
}
