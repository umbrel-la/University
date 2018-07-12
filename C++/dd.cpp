#include <iostream>
#include <string>

using namespace std;

struct Eploy{
	int t_num; // номер карточки
	string name; // имя рабочего храним в строке
	int salary; // зарпата
	string post; // должность 
	string gender; // пол

};

void enteremlp(Eploy mass[], int count) // это кол-во работников)) // передаю массив в который записываю работников
{
	for (int i = 0; i < count; i++){
		Eploy rab1;
		cout << "Введите номер карты" << endl;
		cin >> rab1.t_num; // в cin вводим номер карты
		cout << "Введите Имя рабочего" << endl;
		cin >> rab1.name; // в cin вводим номер имя рабочего
		cout << "Введите зарплату" << endl;
		cin >> rab1.salary; // из cin вводим зарплату рабочего
		cout << "Введите должность" << endl;
		cin >> rab1.post; // из cin вводим должность рабочего
		cout << "Введите пол" << endl;
		cin >> rab1.gender; // из cin вводим пол рабочего
		mass[i] = rab1; // добавил в массив этого работника

	}
}

/* сумма зарплат*/
int all_salary(Eploy mass[], int count) // считаем зарлаты всех работников в массиве
{
	int res = 0;
	for (int i = 0; i < count; i++){
		res += mass[i].salary;
	}
	return res;
}

/*функция для подсчета кол-ва мужчин*/
int sum_men(Eploy mass[], int count) // считаем кол-во всех мужчин и заносим в массиве
{
	int res = 0;
	for (int i = 0; i < count; i++){
		if (mass[i].gender == "man"){
			res++; // если работник это мужчина то мы прибавляем к res (к кол-ву наших работников) 
		}
	}
	return res;
}

/*функция для подсчета кол-ва женщин*/
int sum_women(Eploy mass[], int count) // считаем кол-во всех женщин и заносим в массив
{
	int res = 0;
	for (int i = 0; i < count; i++){
		if (mass[i].gender == "women"){
			res++; // если работник это женщина то мы прибавляем к res (к кол -ву наих работников) 
		}
	}
	return res;
}

/*функция подсчитывает сумму зарплат мужчин*/
int salary_men(Eploy mass[], int count) // считаем зарлаты мужчин и заносим в массиве
{
	int res = 0;
	for (int i = 0; i < count; i++){
		if (mass[i].gender == "man"){
			res += mass[i].salary; // если работник это мужчина то мы прибавляем к ress (к кол -ву наих работников) 
		}
	}
	return res;
}
/*функция подсчитывает сумму зарплат женщин*/
int salary_women(Eploy mass[], int count) // считаем зарлаты всех работников в массиве
{
	int res = 0;
	for (int i = 0; i < count; i++){
		if (mass[i].gender == "women"){
			res += mass[i].salary; // если работник это женщина то мы прибавляем к ress (к кол -ву наих работников) 
		}
	}
	return res;
}

int main()
{
	setlocale(LC_ALL, "");
	const int n = 2;
	Eploy mass[n]; //  создал массим работников
	enteremlp(mass, n); // вызвал функцию заполнения массива
	int summ = all_salary(mass, n); //считаем сумму зарплат всех работников и загружаем сумму в перменную summ
	int amount_men = sum_men(mass, n); // функция сумма мужчин (в переменную sum загружаю кол-во мужчин)
	int amount_girl = sum_women(mass, n); // функция сумма женшин (в переменную sum загружаю кол-во женщин)
	int amount_salary_men = salary_men(mass, n); // функция суммы зарплат мужчин (вызываю функцию и передаю агрументы, а тоесть массив и загружаю все это в salary)
	int amount_salary_women = salary_women(mass, n); // вызываю функцию, передаю аргументы в ф-цию main (массив в котором содержиться сумма зарплат женщин)
	cout << "Сумма зарплат всех работников " << summ << endl;
	cout << "Кол-во мужчин " << amount_men << endl;
	cout << "Кол-во женщин " << amount_girl << endl;
	cout << "Сумма зарплат мужчин " << amount_salary_men << endl;
	cout << "Сумма зарплат женщин " << amount_salary_women << endl;
	system("pause");
	return 0;
}