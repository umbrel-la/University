#include <iostream>

using namespace std;

/*=======================================================================*/
struct tnode {
	int field; // значение которое находится в каждом узле дерева //Поле данных
	tnode *left; //УКАЗАТЕЛИ на соседние веточки
	tnode *right;
};
/*=======================================================================*/
/*Прототипы функций*/
tnode *addtree(tnode *r, int value);
void treePrint(tnode *r);
void freeMem(tnode *r);
tnode *findValue(tnode *r, int search);
/*======================================*/
int main()
{
	setlocale(0, "rus");
	int value; // переменная для ввода, заполняем узлы дерева
	int searchElem; // переменная для поиска элемента в дереве
	tnode *root = NULL; // корню дерева присваиваем NULL
	do {
		cin >> value; // вводим значение
		root = addtree(root, value); // вызываем функцию addtree передаем туда указатель на наш корень и то значение которое ввели
	} while (value != 0); // если пользователь введет 0 выходим из цикла

	treePrint(root); // выводим на экран наше дерево
	
	cout << "Введи значение которое хочешь найти";
	cin >> searchElem; // вводим элемент для поиска
	if (findValue(root, searchElem)) { // если вернется true из функции заходим в 1 if
		cout << "Значение найдено" << endl;
	}
	else { // если вернется NULL из функции
		cout << "Значение не найдено" << endl;
	}
	freeMem(root); // освобождаем память
	system("pause");
}

/* Функция добавления узла к дереву*/
tnode *addtree(tnode *r, int value)
{
	//Если ветки не существует
	if (r == NULL) {  //создадим ее и зададим в нее данные
		r = new tnode; // выделяем память под узел дерева
		r->field = value; // присваиваем в поле field передаваемое значение
		r->left = NULL; // говорим, что пока нет левого поддерава 
		r->right = NULL; // говорим, что пока нет правого поддерева
	}
	//Если оно меньше того, что в этой ветке - добавим влево
	else if (r->field > value) { // 
		r->left = addtree(r->left, value);
		
	}
	else {//Иначе в ветку справа
		r->right = addtree(r->right, value);
	}
	return r; // возвращаем указатель на корень
}

/* Функция вывода дерева*/ 
void treePrint(tnode *r)
{
	if (r != NULL) { // если дерево существует то выводим его
		treePrint(r->left); // сначала спускаемся рекурсивно до самого левого узла дерева
		cout << r->field << " "; // выводим 
		treePrint(r->right); // затем идем в правую ветку и выводим содержимое если оно есть
	}
}

/* Функция удаления поддерева*/
void freeMem(tnode *r)
{
	if (r != NULL) { // если дерево есть то удалим его
		freeMem(r->left); // спускаемся рекурсивно до самого левого узла дерева
		freeMem(r->right); // проверяем есть ли правый узел
		delete r; // удаляем узел
		return;
	}
}

/*Функция поиска элемента в дереве*/
tnode *findValue(tnode *r, int search)
{
	if (r == NULL) {
		return NULL; // не найден нет дерева
	}
	if (r->field == search) {
		return r; // элемент найден это корень
	}
	if (search <= r->field) {
		//left
		if (r->left != NULL) {
			return findValue(r->left, search); // если значение левого потомка меньше чем
			// значение родителя то рекурсивный поиск влево
		}
		else {
			return NULL; // не найден
		}
	}
	else {
		//right
		if (r->right) {
			return findValue(r->right, search);// если значение правого потомка больше чем
			// значение родителя то рекурсивный поиск вправо
		}
		else {
			return NULL; // не найден
		}
	}
}
