#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	int Ruble;

	cout << "������� ���-�� ������" << endl;
	cin >> Ruble;
	cout << "� ��� " << Ruble << "\t";

	if (Ruble < 0)
	{
		return 0;
		cout << "���� �������� ������������" << endl;
	}
	if ((Ruble % 100) >= 11 && (Ruble % 100) <= 19) // ��� �� ������ ��� ��������� ����� ����� ����� �������� ��� ����� � �������� �� 100 (%)
		// ���� ��������� �� ����� �������� � �������� ��� ����� �� 10 ���� ��������� 3 ����� ����� ����� �������� �� 1000 � � � 
	{
		cout << "������" << endl;
	}
	else
	{
		switch (Ruble % 10) 
		{
			case 1: 
				cout << "�����! " << endl; break;
			case 2:
			case 3:
			case 4: 
				cout << "�����" << endl; break;

		default: 
			cout << "������" << endl; break;
		}
	}
	system("pause");
	return 0;
}