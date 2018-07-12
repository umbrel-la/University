#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	int Ruble;

	cout << "Введите кол-во рублей" << endl;
	cin >> Ruble;
	cout << "У вас " << Ruble << "\t";

	if (Ruble < 0)
	{
		return 0;
		cout << "Ваше значение отицательное" << endl;
	}
	if ((Ruble % 100) >= 11 && (Ruble % 100) <= 19) // что бы узнать две последние цифры числа нужно поделить это число с остатком на 100 (%)
		// если последнюю то нужно поделить с остатком это число на 10 если последние 3 цифры числа нужно поделить на 1000 и т д 
	{
		cout << "Рублей" << endl;
	}
	else
	{
		switch (Ruble % 10) 
		{
			case 1: 
				cout << "Рубль! " << endl; break;
			case 2:
			case 3:
			case 4: 
				cout << "Рубля" << endl; break;

		default: 
			cout << "Рублей" << endl; break;
		}
	}
	system("pause");
	return 0;
}