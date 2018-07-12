#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "RUS");
	const int N = 5; // объ€вл€ю константу N = 5
	int A[N]; // объ€вл€ю массив ј из [n] тоесть 5

	cout << "******«аполнение массива********\t\n"; // выводу сообщение в консоль

	for (int i = 0; i < 5; i++){ //проходу цикл, заполн€ю массив
		cout << "¬ведите число" << endl; // вывожу сообщение в консоль
		cin >> A[i]; // заполн€ю массив с клавиатуры
	}
	for (int j = 0; j < 5; j++){ // прохожу цикл, 
		cout << "[" << j << "] = " << A[j] << endl; // вывожу в консоль элементы массива которые пользователь ввел с клавиатуры
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