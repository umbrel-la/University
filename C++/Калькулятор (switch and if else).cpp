#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	int a,b;
	char c;
	int summ;
	cout << "******�����������******" << endl;
	cout << "������� �������������� �������� �������� a + b: " << endl;
	cin >> a >> c >> b;
	if (c == '+')
		summ = a + b;
	else if (c == '-')
		summ = a - b;
	else if (c == '*')
		summ = a * b;
	else if (c == '/')
		summ = a / b;
	cout << summ;

	/*switch (c)
	{
	case '+': cout << a + b; break;
	case '-': cout << a - b; break;
	case '*': cout << a * b; break;
	case '/': cout << a / b; break;
	default: cout << "���� �� �������" << endl; break;
	}
	*/


	

		
	
	system("pause");
	return 0;
}