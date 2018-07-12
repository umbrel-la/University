#include "Header.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <time.h>
const int nmax = 10;

using namespace std;

// �������� �� Header.h ��� ���������
namespace Poisk // ����� ���� ������������ ���� � ����������� ������� ��� �� �� ���� �������� � ����������� �������
{
	
	/*ALGORITMI POISKA*/
//==================================================================

	// FILL ARRAYS 
	void FillArr1(vector<int>& Arr1, const int& N)
	{
		system("cls");
		for (int i = 0; i < N; i++)
		{
			Arr1.at(i) = rand() % 54;
		}
	}
	void FillArr2(vector<int>& Arr2, const int& N)
	{
		system("cls");
		int counter = 1;
		for (int i = 0; i < N; i++)
		{
			Arr2.at(i) = counter;
			counter++;
		}
	}
	void FillArr3(vector<int>& Arr3, const int& N)
	{
		system("cls");
		for (int i = 0; i < N; i++)
		{
			Arr3.at(i) = rand() % 54;
		}
	}


	// OUTPUT ARRAYS
	void OutPutArr1(vector<int>& Arr1, const int& N)

	{
		cout << "Elements Lineynogo Poiska " << endl;
		for (int i = 0; i < N; i++)
		{
			cout << Arr1[i] << " ";
		}
		cout << endl;
	}
	void OutPutArr2(vector<int>& Arr2, const int& N)

	{

		cout << "Elements Binarnogo Poiska " << endl;
		for (int i = 0; i < N; i++)
		{
			cout << Arr2[i] << " ";
		}
		cout << endl;
	}
	void OutPutArr3(vector<int>& Arr3, const int& N)

	{
		cout << "Elements Poiska s Barierom";
		cout << endl;
		for (int i = 0; i < N; i++)
		{
			cout << Arr3[i] << " ";
		}
		cout << endl;
	}


	// SEARCH ELEMETS
	void Lineyniy(vector<int>& Arr1, const int& N)
	{
		int tmp;
		int counter = 0;
		cout << "Enter value, which do you want find " << endl;
		cin >> tmp;
		for (int i = 0; i < N; i++)
		{
			if (tmp == Arr1[i])
			{
				counter++;
			}
		}
		cout << "Sovpadeniy  Chisla " << tmp << " = " << counter << endl;
	}
	void Bunarny(vector<int>& Arr2, const int& N)
	{
		bool FlagBunary = false;
		int Key;
		cout << "Enter Key which do you want to find" << endl;
		cin >> Key;
		int left = 0;
		int right = N - 1;
		int midd = 0;
		while ((left <= right) && (FlagBunary != true)) {
			midd = (left + right) / 2; // ��������� ��������� ������ ������� [l,r]

			if (Arr2[midd] == Key) FlagBunary = true; //��������� ���� �� ���������� ���������
			if (Arr2[midd] > Key) right = midd - 1; // ���������, ����� ����� ����� ���������
			else left = midd + 1;
		}

		if (FlagBunary)
		{
			cout << "Index elementa " << Key << " = " << midd << endl;

		}
		else
		{
			cout << "Sorry element not found" << endl;
		}
	}
	void Barier(vector<int>& Arr3, const int& N)
	{

		int find_el;
		int position = 0;
		cout << "inter element  which do you want to find ";
		cin >> find_el;
		if (Arr3[N - 1] != find_el)
		{
			Arr3[N - 1] = find_el; // ��������� ��� ������ � ����� �������
			for (; Arr3[position] != find_el; ++position);
			++position; // �������������� �������
		}
		else
		{
			cout << "Index elementa " << find_el << " = " << position;
		}
		cout << "Index elementa " << find_el << position;
	}
	//===================================================================
		// Menu
	int FirstMenu()
	{
		int inpitAnsver;
		cout << "*****************Hello My dear friend *************************" << endl;
		cout << "\t\t [1] Search Algorithms  " << endl;
		cout << "\t\t [2] Sorting Algorithms  " << endl;
		cout << "\t\t [3] �alculate the speed of Algorithms" << endl;
		cin >> inpitAnsver;
		return inpitAnsver;
	}
	int MenuSearch()
	{
		system("cls");
		int SecondAnswer;
		cout << "\tChoice " << endl;
		cout << "1 Lineyniy Poisk " << endl;
		cout << "2 Binarniy Poisk" << endl;
		cout << "3 Poisk s Barierom" << endl;
		cin >> SecondAnswer;
		return SecondAnswer;
	}
	int MenuSort()
	{
		system("cls");
		int Answer;
		cout << "\tChoise" << endl;
		cout << "\t[1] Sorting Bubble" << endl;
		cout << "\t[2] Sorting Sheker" << endl;
		cout << "\t[3] Sorting Insertion (Shell)" << endl;
		cout << "\t[4] Sorting Quick (Xoara)" << endl;
		cout << "\t[5] Sorting Merger " << endl;
		cout << "\t[6] Sorting Pyramidal " << endl;
		cout << "\t[7] Sort All Arrays" << endl;
		cin >> Answer;
		return Answer;
	}
	//===================================================================

		/*SORTING ARRAYS*/
	//===================================================================


		// FILL ARRAYS 
	void FillArr4(vector<int>& Arr4, const int& M, bool clear)
	{
		if (clear)
		{
			system("cls");
		}
		for (int i = 0; i < M; i++)
		{
			Arr4.at(i) = rand() % 54;
		}
	}
	void FillArr5(vector<int>& Arr5, const int& M, bool clear)
	{
		if (clear)
		{
			system("cls");
		}
		for (int i = 0; i < M; i++)
		{
			Arr5.at(i) = rand() % 54;
		}
	}
	void FillArr6(vector<int>& Arr6, const int& M, bool clear)
	{
		if (clear)
		{
			system("cls");
		}
		for (int i = 0; i < M; i++)
		{
			Arr6.at(i) = rand() % 55;
		}
	}
	void FillArr7(vector<int>& Arr7, const int& M, bool clear)
	{
		if (clear)
		{
			system("cls");
		}
		for (int i = 0; i < M; i++)
		{
			Arr7.at(i) = rand() % 41; 
		}
	}
	void FillArr8(vector<int>& Arr8, const int& M, bool clear)
	{
		if (clear)
		{
			system("cls");
		}
		for (int i = 0; i < M; i++)
		{
			Arr8.at(i) = rand() % 41;
		}
	}
	void FillArr9(vector<int>& Arr9, const int& M, bool clear)
	{
		if (clear)
		{
			system("cls");
		}
		for (int i = 0; i < M; i++)
		{
			Arr9.at(i) = rand() % 41;
		}
	}

	// OUTPUT ARRAYS
	void OutPutArr4(vector<int>& Arr4, const int& M)

	{
		for (int i = 0; i < M; i++)
		{
			cout << Arr4[i] << " ";
		}
		cout << endl;
	}
	void OutPutArr5(vector<int>& Arr5, const int& M)

	{
		for (int i = 0; i < M; i++)
		{
			cout << Arr5[i] << " ";
		}
		cout << endl;
	}
	void OutPutArr6(vector<int>& Arr6, const int& M)

	{
		for (int i = 0; i < M; i++)
		{
			cout << Arr6[i] << " ";
		}
		cout << endl;
	}
	void OutPutArr7(vector<int>& Arr7, const int& M)

	{
		
		for (int i = 0; i < M; i++)
		{
			cout << Arr7[i] << " ";
		}
		cout << endl;
	}
	void OutPutArr8(vector<int>& Arr8, const int& M)

	{
		for (int i = 0; i < M; i++)
		{
			cout << Arr8[i] << " ";
		}
		cout << endl;
	}
	void OutPutArr9(vector<int>& Arr9, const int& M)

	{
		for (int i = 0; i < M; i++)
		{
			cout << Arr9[i] << " ";
		}
		cout << endl;
	}
	// SORTING

	void SortBubble(vector<int>& Arr4, const int& M)
	{
		int tmp = 0;
		for (int i = M - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (Arr4[j] > Arr4[j + 1])
				{
					tmp = Arr4[j];
					Arr4[j] = Arr4[j + 1];
					Arr4[j + 1] = tmp;
				}
			}
		}
	}
	void SortSheker(vector<int>& Arr5, const int& M)
	{
		int temp = 0;
		int leftMark = 1;
		int rightMark = M - 1;
		while (leftMark < rightMark)
		{
			for (int i = rightMark; i >= leftMark; i--)
			{
				if (Arr5[i - 1] > Arr5[i])
				{
					temp = Arr5[i];
					Arr5[i] = Arr5[i - 1];
					Arr5[i - 1] = temp;
				}
			}
			leftMark++;


			for (int i = leftMark; i <= rightMark; i++)
			{
				if (Arr5[i - 1] > Arr5[i])
				{
					temp = Arr5[i];
					Arr5[i] = Arr5[i - 1];
					Arr5[i - 1] = temp;
				}
			}
			rightMark--;
		}
	}
	void SortInsert(vector<int>& Arr6, const int& M)
	{
		// ��������� �������� ��������� ���� �� ����� �� ��������� ���������� step
		// ������ �� 1000 ����� �� 500
		int i, j, step;
		int tmp;
		for (step = M / 2; step > 0; step /= 2)
			for (i = step; i < M; i++)
			{
				tmp = Arr6[i];
				for (j = i; j >= step; j -= step)
				{
  					if (tmp < Arr6[j - step])
						Arr6[j] = Arr6[j - step];
					else
						break;
				}
				Arr6[j] = tmp;
			}

	}
	void QuickSort(vector<int>& Arr7, int left, int right)
	{
		// ���������� ������� ������� ���������� ����������� 
		// �� ���������� �������� � ����������� � � ����� ����� �� ������������
		// �������� ����� �������� ������ � ������ ������
		int pivot; // ����������� �������
		int l_hold = left; //����� �������
		int r_hold = right; // ������ �������
		pivot = Arr7[left];
		while (left < right) // ���� ������� �� ���������
		{
			while ((Arr7[right] >= pivot) && (left < right))
				right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
			if (left != right) // ���� ������� �� ����������
			{
				Arr7[left] = Arr7[right]; // ���������� ������� [right] �� ����� ������������
				left++; // �������� ����� ������� ������ 
			}
			while ((Arr7[left] <= pivot) && (left < right))
				left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
			if (left != right) // ���� ������� �� ����������
			{
				Arr7[right] = Arr7[left]; // ���������� ������� [left] �� ����� [right]
				right--; // �������� ������ ������� ������ 
			}
		}
		Arr7[left] = pivot; // ������ ����������� ������� �� �����
		pivot = left;
		left = l_hold;
		right = r_hold;
		if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
   			QuickSort(Arr7, left, pivot - 1);
		if (right > pivot)
			QuickSort(Arr7, pivot + 1, right);

	}
	void MergerSort(vector<int>& Arr8, int left, int right)
	{
		// ��������� ��� ������ �� ����������
		int  temp;
		if (left<right)// ��������� ������ ���� ������ � ��� ��� ���
			if (right - left == 1) { // ��������� ���� 2 �� � ������� �� ������ �� �������
				if (Arr8[right]< Arr8[left]) {
					temp = Arr8[left];
					Arr8[left] = Arr8[right];
					Arr8[right] = temp;
				}
			}
		// ���� ��� ������� �� �������� ���������� ���� �������
		// ��������� �� ������� ��� ������
			else {
				MergerSort(Arr8, left, left + (right - left) / 2);
				MergerSort(Arr8, left + (right - left) / 2 + 1, right);
				Merg(Arr8, left, right);
			}

	}
	void Merg(vector<int>& Arr8, int begin, int end)
	{
		// ����� ������ ���������� ���������� �������� � 
		// ������� �� � ���� ������
		int i = begin,
			t = 0,
			mid = begin + (end - begin) / 2,
			j = mid + 1;
			vector <int> d(Arr8.size());

		while (i <= mid && j <= end) {

			if (Arr8[i] <= Arr8[j]) {
				d[t] = Arr8[i]; i++;
			}
			else {
				d[t] = Arr8[j]; j++;
			}
			t++;
		}

		while (i <= mid) {
			d[t] = Arr8[i]; i++; t++;
		}

		while (j <= end) {
			d[t] = Arr8[j]; j++; t++;
		}

		for (i = 0; i < t; i++)
			Arr8[begin + i] = d[i];

	}
	void PidamidalSort(vector<int>& Arr9, int SizeArray)
	{
		// ��������� ������ ��� ��������
		for (int i = (SizeArray / 2) - 1; i >= 0; i--)
			siftDownPiramidal(Arr9, i, SizeArray);
		// ���������� ����� �������� ��������� ��������
		for (int i = SizeArray - 1; i >= 1; i--)
		{
			int temp = Arr9[0];
			Arr9[0] = Arr9[i];
			Arr9[i] = temp;
			siftDownPiramidal(Arr9, 0, i - 1);
		}
	}
	void siftDownPiramidal(vector<int>& Arr9, int root, int bottom)
	{
		//  ��������� ����������� ���������� �������� 
		//  �� ���������: a[k+1]...a[n]  - �������� 
		//  �����:  a[k]...a[n]  - �������� 
		int new_elem;
		long child;
		new_elem = Arr9[root];

		while (root <= bottom / 2) {  		// ���� � a[k] ���� ���� 
			child = 2 * root;
			//  �������� �������� ���� 
			if (child < bottom && Arr9[child] < Arr9[child + 1])
				child++;
			if (new_elem >= Arr9[child]) break;
			// ����� 
			Arr9[root] = Arr9[child]; 	// ��������� ���� ������ 
			root = child;
		}
		Arr9[root] = new_elem;
	}
}