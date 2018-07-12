#include <GL/glut.h>
#include <iostream>
#include <ctime>
#include "game.h"

void unit(int,int);
int random(int,int);

bool length_inc=false;
bool seedflag = false;
int score;
bool game_over;
bool food=false;
int rows=0,columns=0;
int direction = RIGHT;
int foodx,foody;
int posx[MAX+1]={4,3,2,1,0,-1,-1};
int posy[MAX+1]={10,10,10,10,10,10,10};
int length=7;

void initGrid(int x,int y)
{
    columns=x;
    rows=y;
}

void draw_grid()
{// РИСУЕМ СЕТКУ по координатам 
    for(int i =0;i<columns;i++)
    {
        for(int j=0;j<rows;j++)
            {unit(i,j);}
    }
}

void draw_snake()
{
    for(int i =length-1;i>0;i--)
    {
        posx[i]=posx[i-1];
        posy[i]=posy[i-1];
    }
    for(int i=0;i<length;i++)
    {
        glColor3f(0.0,1.0,0.0);
        if(i==0)
        {
        	// задаем цвет нашего четырех угольника нашего примитива
            glColor3f(0.0,0.0,1.0); // зеленый цвет
            switch(direction)
            {
            case UP:
                posy[i]++;
                break;
            case DOWN:
                posy[i]--;
                break;
            case RIGHT:
                posx[i]++;
                break;
            case LEFT:
                posx[i]--;
                break;
            }
            // есди координаты головы равны координатам хвоста значит игра окончена
            if(posx[i]==0||posx[i]==columns-1||posy[i]==0||posy[i]==rows-1)
                game_over=true; 
            else if(posx[i]==foodx && posy[i]==foody)
            {// если координаты хвост пересекли координаты головы змейки значит м съели фрукт
                food=false;
                score++; // увеличиваем счетчик фруктов
                if(length<=MAX)
                    length_inc=true;
                if(length==MAX)
                    MessageBox(NULL,"You Win\nYou can still keep playing but the snake will not grow.","Awsome",0);
            }
            for(int j=1;j<length;j++)// если вышли за приделы поля игра окончена
            {
                if(posx[j]==posx[0] && posy[j]==posy[0])
                    game_over=true;
            }
        }
        //  ЗАДАЕМ ПРИМИТИВ 
        glBegin(GL_QUADS); // ПАРАМЕТР  GL_QUADS КАЖДЫЕ ЧЕТЫРЕ ВЕРШИНЫ ОБРАЗУЮТ ЧЕТЕРЕХ УГОЛЬНИК
        // ЗАДАЕМ ВЕРШИНЫ ТО ЕСТЬ КООРДИНАТЫ НАШЕГО ПРИМИТИВА ТО ЕСТЬ ЧЕТЫРЕХ УГОЛЬНИКА
            glVertex2d(posx[i],posy[i]); glVertex2d(posx[i]+1,posy[i]); glVertex2d(posx[i]+1,posy[i]+1); glVertex2d(posx[i],posy[i]+1);
        glEnd();
    }
    if(length_inc)
    {
        length++;
        length_inc=false;
    }
}

void draw_food()
{
    if(!food)
    {// рандомим фрукты
        foodx=random(2,columns-2);
        foody=random(2,rows-2);
        std::cout<<foodx<<foody<<std::endl;
        food=true;
    }
    // ТАК ЖЕ ОТРИОВЫВАЕМ ФРУКТЫ ПО КООРДИНАТАМ КАК И ЗМЕЙКУ
    glBegin(GL_QUADS);
        glVertex2d(foodx,foody); glVertex2d(foodx+1,foody); glVertex2d(foodx+1,foody+1); glVertex2d(foodx,foody+1);
    glEnd();
}

void unit(int x,int y)
{
	// ОТРИСОВКА СЕТКИ БЕЛОЙ И КРАСНОЙ ПО БОКАМ
    glLoadIdentity();
    if(x==0||x==columns-1||y==0||y==rows-1)
    {
        glLineWidth(4.0);
        glColor3f(1.0,0.0,0.0);
    }
    else
    {
        glColor3f(1.0,1.0,1.0);
        glLineWidth(1.0);
    }
    glBegin(GL_LINES);
        glVertex2d(x,y); glVertex2d(x+1,y);
        glVertex2d(x+1,y); glVertex2d(x+1,y+1);
        glVertex2d(x+1,y+1); glVertex2d(x,y+1);
        glVertex2d(x,y+1); glVertex2d(x,y);
    glEnd();
}
int random(int _min,int _max)
{
    if(!seedflag)
    {
        srand(time(NULL));
        seedflag=true;
    }
    else
        seedflag=false;
    return _min+rand()%(_max-_min);
}
