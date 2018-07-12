#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*Функция одномерного массива*/
void _odnMass(int res, int temp)
{
	const int N = 3;
	int Arr[N];
	srand(time(0));
	for (int i = 0; i < N; i++){
		Arr[i] = 1 + rand() % 3;
		res += Arr[i];
		temp *= Arr[i];
	}
	for (int i = 0; i < N; i++){
		cout << "[" << i << "]= " << Arr[i] << ' ' << endl;
	}
	cout << endl <<  "Сумма одномерного массива = " <<  res << endl;
	cout << "Произведение одномерного массива = " << temp << endl << endl;

}

const int N = 3;

void Minstr(int Mass[N][N], int res[N])
{
	for (int i = 1; i < M; i += 2) {
		for (int j = 0; j < N; j++) {
			if (res[j] < mat[i][j]) {
				res[j] = mat[i][j];
			}
		}
	}
}

/*Функция Двумерного массива*/


int dvumMass(int result, int znach, int issum, int isproizv){
	
	int M[N][N];
	 // Переменная для подсчета суммы на главной диагонали

	srand(time(0));

	/*Заполняю матрицу*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			M[i][j] = 1 + rand() % 3;
			if (i == j){			// алгоритм нахождения элементов на главной диагонали
				result += M[i][j]; 
			}
			if (i > j){				// алгоритм нахождения элементов ниже главной диагонали
				znach += M[i][j]; 
			}
			if (i < j){				// алгоритм нахождения элементов выше главной диагонали
				issum += M[i][j]; 
			}
			if (i + j == N - 1){	// алгоритм нахождения произведения побочной диагонали
				isproizv *= M[i][j]; 
			}
		}

	}
	/* выводим матрицу для демонстрации */
	for (int i = 0; i < N; i++){
		cout << "|";
		for (int j = 0; j < N; j++){
			cout << M[i][j] << ' ';
		}
		cout << "|";
		cout << endl;
	}
	cout << endl << "Сумма элементов на диагонали равна = " << result << endl;
	cout << "Сумма элементов ниже главной диагонали = " << znach << endl;
	cout << "Сумма элементов выше главной диагонали = " << issum << endl;
	cout << "Произведение элементов на побочной диагонали = " << isproizv << endl;
	int res[N] = { 0, 0, 0 };
	Minstr(M, res);

	cout << "Minimums";

	for (int i = 0; i < N; i++){
		cout << res[i] << ' ';
	}

	return result;
	
}
/*Функция умножения двух матриц*/



void Mass()
{
	const int N = 3;
	int M1[N][N],
		M2[N][N],
		M3[N][N];
	
	srand(time(0));

	/*Заполняем 1 матрицу*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 0; j++){
			M1[i][j] = 1 + rand() % 3;
		}
	}
	/*Заполняем 2 матрицу*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			M2[i][j] = 1 + rand() % 3;
		}
	}



	/*Умножаю 1 матрицу на 2*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int m = 0; m < N; m++){
				M3[i][j] += M1[i][m] * M2[m][j]; // алгоритм умножения матрицы (1 столбец на 1 строку и т д)
			}
		}
+	}
	/*Вывожу 1 и 2 матрицу для примера*/
	for (int i = 0; i < N; i++){
		cout << "|";
		for (int j = 0; j < N; j++){
			cout << M1[i][j] << ' ';
		}
		cout << "|";
		cout << "   ";
		cout << "|";
		for (int j = 0; j < N; j++){
			cout << M2[i][j];
		}
		cout << "|";
		cout << endl;
	}
	/*Вывожу 3 матрицу*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
	
			cout << M3[i][j] << ' ';
		}
	}
	

}





int main()
{

	setlocale(LC_ALL, "RUS");
	_odnMass(0,1);
	dvumMass(0,0,0,1);
	Mass();

	system("pause");
}