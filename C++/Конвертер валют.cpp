#include <iostream> // ���������� ���������� iostream ���������� #include
using namespace std; // ������������ ������������ ���� � �������  ��������� (�out, cin, endl)
int main() // ����� ����� � ���������
{// ����������� ������ �-��� main
	setlocale(LC_ALL, "RUS"); // ���������� ������� ���������
	cout << "\t\t\t��������� �����\n\n"; //� ������� ��������� � �������
	double Euro, Dollar, Rub; // ��������� 3 ���������� ���� double ������� �������� 8 ���� (double ��� ��� � ������� ���������)
	const double DollarPerRub = 57.68; // ��������� ��������� � ����� double (��������� ���������)
	const double DollarPerEuro = 0.84654; // ��������� ��������� � ����� double (��������� ���������)
	

	cout << "������� �������" << endl; // ������� ���������� � ������� � ��������� ��� �� ����� ������
	cin >> Dollar; // ������ ���������� Dollar
	Rub = DollarPerRub * Dollar; // ����������� ���������� Rub ������������ (DollarPerRub * Dollar)
	Euro = DollarPerEuro * Dollar; // ����������� ���������� Euro ������������ (DollarPerEuro * Dollar)

	cout << Dollar << " = " << Rub << " ������" << endl; // ������� ���������� Dollar ������ "=" ���������� Rub ������ "������" ��������� ��������� �� ����� ������
	cout << Dollar << " = " << Euro << " ����" << endl;  // ������� ���������� Dollar ������ "=" ���������� Euro ������ "������" ��������� ��������� �� ����� ������

		system("pause"); // �������� ������ �������
		return 0; // ���������� 0 � ������� main � ��������� ��������� 
	
} // ��������� ���������� ������ ������� main