#include <iostream>

using namespace std;

/*=======================================================================*/
struct tnode {
	int field; // �������� ������� ��������� � ������ ���� ������ //���� ������
	tnode *left; //��������� �� �������� �������
	tnode *right;
};
/*=======================================================================*/
/*��������� �������*/
tnode *addtree(tnode *r, int value);
void treePrint(tnode *r);
void freeMem(tnode *r);
tnode *findValue(tnode *r, int search);
/*======================================*/
int main()
{
	setlocale(0, "rus");
	int value; // ���������� ��� �����, ��������� ���� ������
	int searchElem; // ���������� ��� ������ �������� � ������
	tnode *root = NULL; // ����� ������ ����������� NULL
	do {
		cin >> value; // ������ ��������
		root = addtree(root, value); // �������� ������� addtree �������� ���� ��������� �� ��� ������ � �� �������� ������� �����
	} while (value != 0); // ���� ������������ ������ 0 ������� �� �����

	treePrint(root); // ������� �� ����� ���� ������
	
	cout << "����� �������� ������� ������ �����";
	cin >> searchElem; // ������ ������� ��� ������
	if (findValue(root, searchElem)) { // ���� �������� true �� ������� ������� � 1 if
		cout << "�������� �������" << endl;
	}
	else { // ���� �������� NULL �� �������
		cout << "�������� �� �������" << endl;
	}
	freeMem(root); // ����������� ������
	system("pause");
}

/* ������� ���������� ���� � ������*/
tnode *addtree(tnode *r, int value)
{
	//���� ����� �� ����������
	if (r == NULL) {  //�������� �� � ������� � ��� ������
		r = new tnode; // �������� ������ ��� ���� ������
		r->field = value; // ����������� � ���� field ������������ ��������
		r->left = NULL; // �������, ��� ���� ��� ������ ��������� 
		r->right = NULL; // �������, ��� ���� ��� ������� ���������
	}
	//���� ��� ������ ����, ��� � ���� ����� - ������� �����
	else if (r->field > value) { // 
		r->left = addtree(r->left, value);
		
	}
	else {//����� � ����� ������
		r->right = addtree(r->right, value);
	}
	return r; // ���������� ��������� �� ������
}

/* ������� ������ ������*/ 
void treePrint(tnode *r)
{
	if (r != NULL) { // ���� ������ ���������� �� ������� ���
		treePrint(r->left); // ������� ���������� ���������� �� ������ ������ ���� ������
		cout << r->field << " "; // ������� 
		treePrint(r->right); // ����� ���� � ������ ����� � ������� ���������� ���� ��� ����
	}
}

/* ������� �������� ���������*/
void freeMem(tnode *r)
{
	if (r != NULL) { // ���� ������ ���� �� ������ ���
		freeMem(r->left); // ���������� ���������� �� ������ ������ ���� ������
		freeMem(r->right); // ��������� ���� �� ������ ����
		delete r; // ������� ����
		return;
	}
}

/*������� ������ �������� � ������*/
tnode *findValue(tnode *r, int search)
{
	if (r == NULL) {
		return NULL; // �� ������ ��� ������
	}
	if (r->field == search) {
		return r; // ������� ������ ��� ������
	}
	if (search <= r->field) {
		//left
		if (r->left != NULL) {
			return findValue(r->left, search); // ���� �������� ������ ������� ������ ���
			// �������� �������� �� ����������� ����� �����
		}
		else {
			return NULL; // �� ������
		}
	}
	else {
		//right
		if (r->right) {
			return findValue(r->right, search);// ���� �������� ������� ������� ������ ���
			// �������� �������� �� ����������� ����� ������
		}
		else {
			return NULL; // �� ������
		}
	}
}
