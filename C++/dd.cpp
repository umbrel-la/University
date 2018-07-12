#include <iostream>
#include <string>

using namespace std;

struct Eploy{
	int t_num; // ����� ��������
	string name; // ��� �������� ������ � ������
	int salary; // �������
	string post; // ��������� 
	string gender; // ���

};

void enteremlp(Eploy mass[], int count) // ��� ���-�� ����������)) // ������� ������ � ������� ��������� ����������
{
	for (int i = 0; i < count; i++){
		Eploy rab1;
		cout << "������� ����� �����" << endl;
		cin >> rab1.t_num; // � cin ������ ����� �����
		cout << "������� ��� ��������" << endl;
		cin >> rab1.name; // � cin ������ ����� ��� ��������
		cout << "������� ��������" << endl;
		cin >> rab1.salary; // �� cin ������ �������� ��������
		cout << "������� ���������" << endl;
		cin >> rab1.post; // �� cin ������ ��������� ��������
		cout << "������� ���" << endl;
		cin >> rab1.gender; // �� cin ������ ��� ��������
		mass[i] = rab1; // ������� � ������ ����� ���������

	}
}

/* ����� �������*/
int all_salary(Eploy mass[], int count) // ������� ������� ���� ���������� � �������
{
	int res = 0;
	for (int i = 0; i < count; i++){
		res += mass[i].salary;
	}
	return res;
}

/*������� ��� �������� ���-�� ������*/
int sum_men(Eploy mass[], int count) // ������� ���-�� ���� ������ � ������� � �������
{
	int res = 0;
	for (int i = 0; i < count; i++){
		if (mass[i].gender == "man"){
			res++; // ���� �������� ��� ������� �� �� ���������� � res (� ���-�� ����� ����������) 
		}
	}
	return res;
}

/*������� ��� �������� ���-�� ������*/
int sum_women(Eploy mass[], int count) // ������� ���-�� ���� ������ � ������� � ������
{
	int res = 0;
	for (int i = 0; i < count; i++){
		if (mass[i].gender == "women"){
			res++; // ���� �������� ��� ������� �� �� ���������� � res (� ��� -�� ���� ����������) 
		}
	}
	return res;
}

/*������� ������������ ����� ������� ������*/
int salary_men(Eploy mass[], int count) // ������� ������� ������ � ������� � �������
{
	int res = 0;
	for (int i = 0; i < count; i++){
		if (mass[i].gender == "man"){
			res += mass[i].salary; // ���� �������� ��� ������� �� �� ���������� � ress (� ��� -�� ���� ����������) 
		}
	}
	return res;
}
/*������� ������������ ����� ������� ������*/
int salary_women(Eploy mass[], int count) // ������� ������� ���� ���������� � �������
{
	int res = 0;
	for (int i = 0; i < count; i++){
		if (mass[i].gender == "women"){
			res += mass[i].salary; // ���� �������� ��� ������� �� �� ���������� � ress (� ��� -�� ���� ����������) 
		}
	}
	return res;
}

int main()
{
	setlocale(LC_ALL, "");
	const int n = 2;
	Eploy mass[n]; //  ������ ������ ����������
	enteremlp(mass, n); // ������ ������� ���������� �������
	int summ = all_salary(mass, n); //������� ����� ������� ���� ���������� � ��������� ����� � ��������� summ
	int amount_men = sum_men(mass, n); // ������� ����� ������ (� ���������� sum �������� ���-�� ������)
	int amount_girl = sum_women(mass, n); // ������� ����� ������ (� ���������� sum �������� ���-�� ������)
	int amount_salary_men = salary_men(mass, n); // ������� ����� ������� ������ (������� ������� � ������� ���������, � ������ ������ � �������� ��� ��� � salary)
	int amount_salary_women = salary_women(mass, n); // ������� �������, ������� ��������� � �-��� main (������ � ������� ����������� ����� ������� ������)
	cout << "����� ������� ���� ���������� " << summ << endl;
	cout << "���-�� ������ " << amount_men << endl;
	cout << "���-�� ������ " << amount_girl << endl;
	cout << "����� ������� ������ " << amount_salary_men << endl;
	cout << "����� ������� ������ " << amount_salary_women << endl;
	system("pause");
	return 0;
}