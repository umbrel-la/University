#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;
const int width = 10;
const int height = 10;

// ���������� �� x � �� y
int x, y;

// ���������� ��� �������
int fruitX, fruitY;

// ������� ����
int score;

// ���������� ������ �� X
int tailX[100];

// ����������  ������ �� Y
int tailY[100];

// ���-�� ��������� � ����� ������ 
int nTail; // �������� 10 ������� ����� ��� ����� ��������� � ���� ����������

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = x + 1;  // �������� �������� ��� ������� �� X
	fruitY = y + 1;
	score = 0;
}

// ������ ����� 
void Draw()
{
	system("cls");
	// ������� ������� #############
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;

	// ������� ������� ###
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (j == 0 || j == width - 1)
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else{
				// ���� �� ������ ����� ������ ��� ������� ������ �� ��� �� ����� �������� ������
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						// ����� �� ������ ������� ������ �� ������ �������� true
						print = true;
						cout << "o";
					}
				}
				if (!print)
				cout << " ";

			}
		}
		cout << endl;
	}

	// ������ ������� #############
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
	cout << "score = " << score << endl;
}


void Input()
{
	// ������� kbhit() ���������� ������, ���� ������ �����-���� ������� �� ����������
	if (_kbhit()) 
	{	
		// _getch(); // ����� ����� ���� ������������ �� ����� ����� �������
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x': 
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	// ���������� ������� �� X
	int prevX = tailX[0]; 
	// ���������� ������� �� Y
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;

		prevX = prev2X;
		prevY = prev2Y;
	}
	/*������*/
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	
	if (x > width || x < 0 || y > height || y < 0)
	{
		gameOver = true;
	}
	if (x == fruitX  && y == fruitY)
	{
		score += 10;
		fruitX = x + 1;  // �������� �������� ��� ������� �� X
		fruitY = y + 1; // �������� �������� ��� ������� �� Y
		nTail++; // ����������� ��� ����� (������ ����� ������)
	}

}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
	

	return 0;
}