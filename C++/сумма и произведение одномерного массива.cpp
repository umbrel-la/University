#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "RUS");
	const int N = 5; // �������� ��������� N = 5
	int A[N]; // �������� ������ � �� [n] ������ 5

	cout << "******���������� �������********\t\n"; // ������ ��������� � �������

	for (int i = 0; i < 5; i++){ //������� ����, �������� ������
		cout << "������� �����" << endl; // ������ ��������� � �������
		cin >> A[i]; // �������� ������ � ����������
	}
	for (int j = 0; j < 5; j++){ // ������� ����, 
		cout << "[" << j << "] = " << A[j] << endl; // ������ � ������� �������� ������� ������� ������������ ���� � ����������
	}
	int summ = 0;
	int proizv = 1;
	for (int k = 0; k < 5; k++){
		summ += A[k];
		proizv *= A[k];
	}

	cout << summ << endl;
	cout << proizv << endl;


	


	system("pause");
	return 0;
}