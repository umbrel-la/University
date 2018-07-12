#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*������� ����������� �������*/
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
	cout << endl <<  "����� ����������� ������� = " <<  res << endl;
	cout << "������������ ����������� ������� = " << temp << endl << endl;

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

/*������� ���������� �������*/


int dvumMass(int result, int znach, int issum, int isproizv){
	
	int M[N][N];
	 // ���������� ��� �������� ����� �� ������� ���������

	srand(time(0));

	/*�������� �������*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			M[i][j] = 1 + rand() % 3;
			if (i == j){			// �������� ���������� ��������� �� ������� ���������
				result += M[i][j]; 
			}
			if (i > j){				// �������� ���������� ��������� ���� ������� ���������
				znach += M[i][j]; 
			}
			if (i < j){				// �������� ���������� ��������� ���� ������� ���������
				issum += M[i][j]; 
			}
			if (i + j == N - 1){	// �������� ���������� ������������ �������� ���������
				isproizv *= M[i][j]; 
			}
		}

	}
	/* ������� ������� ��� ������������ */
	for (int i = 0; i < N; i++){
		cout << "|";
		for (int j = 0; j < N; j++){
			cout << M[i][j] << ' ';
		}
		cout << "|";
		cout << endl;
	}
	cout << endl << "����� ��������� �� ��������� ����� = " << result << endl;
	cout << "����� ��������� ���� ������� ��������� = " << znach << endl;
	cout << "����� ��������� ���� ������� ��������� = " << issum << endl;
	cout << "������������ ��������� �� �������� ��������� = " << isproizv << endl;
	int res[N] = { 0, 0, 0 };
	Minstr(M, res);

	cout << "Minimums";

	for (int i = 0; i < N; i++){
		cout << res[i] << ' ';
	}

	return result;
	
}
/*������� ��������� ���� ������*/



void Mass()
{
	const int N = 3;
	int M1[N][N],
		M2[N][N],
		M3[N][N];
	
	srand(time(0));

	/*��������� 1 �������*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 0; j++){
			M1[i][j] = 1 + rand() % 3;
		}
	}
	/*��������� 2 �������*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			M2[i][j] = 1 + rand() % 3;
		}
	}



	/*������� 1 ������� �� 2*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int m = 0; m < N; m++){
				M3[i][j] += M1[i][m] * M2[m][j]; // �������� ��������� ������� (1 ������� �� 1 ������ � � �)
			}
		}
+	}
	/*������ 1 � 2 ������� ��� �������*/
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
	/*������ 3 �������*/
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