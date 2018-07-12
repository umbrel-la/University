#include <vector>
#include "Header.h"
#include <iostream>
#include <time.h>
using namespace Poisk;


int main()
{
	setlocale(0, "rus");
	const int N = 10;
	const int M = 1000;
	bool speed = false;
	bool CLEAR = true;
	double t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
	std::vector <int> Arr1(N); // Линейный поиск
	std::vector <int> Arr2(N); // Бинарный поиск
	std::vector <int> Arr3(N); // Поиск с Барьером
	/*ВСЕ МАССИВЫ(алгоритмы сортировки) ТЕСТИРУЮТСЯ НА 2000 ЭЛЕМЕНТАХ*/
	std::vector <int> Arr4(M); // Сортировка Пузырьком
	std::vector <int> Arr5(M); // Сортировка Шейкер
	std::vector <int> Arr6(M); // Сортировка Вставками
	std::vector <int> Arr7(M); // Сортировка Быстрая Хоара
	std::vector <int> Arr8(M); // Сортировка Слиянием
	std::vector <int> Arr9(M); // Сортировка Пирамидальная
	int FirstAnswer = FirstMenu();
	int SearchAnswer;
	int SortAnswer;
	int SpeedAnswer;
	switch (FirstAnswer)
	{
	case 1:
		SearchAnswer = MenuSearch();
			switch (SearchAnswer)
			{
			case 1:
				FillArr1(Arr1, N);
				OutPutArr1(Arr1, N);
				Lineyniy(Arr1, N);
				break;
			case 2:
				FillArr2(Arr2, N);
				OutPutArr2(Arr2, N);
				Bunarny(Arr2, N);
				break;
			case 3:
				FillArr3(Arr3, N);
				OutPutArr3(Arr3, N);
				Barier(Arr3, N);
				break;
			}
			break;
	case 2:
		SortAnswer = MenuSort();
		switch (SortAnswer)
		{
		case 1:
			FillArr4(Arr4, 10, CLEAR);
			OutPutArr4(Arr4, 10);
			SortBubble(Arr4, 10);
			std::cout << std::endl;
			std::cout << "Elementi Posle Sortirovki Bubble Sort" << std::endl;
			OutPutArr4(Arr4, 10);
			break;
		case 2:
			FillArr5(Arr5, 10, CLEAR);
			OutPutArr5(Arr5, 10);
			SortSheker(Arr5, 10);
			std::cout << std::endl;
			std::cout << "Elementi Posle Sortirovki Sheker Sort" << std::endl;
			OutPutArr5(Arr5, 10);
			break;
		case 3:
			FillArr6(Arr6, 10, CLEAR);
			OutPutArr6(Arr6, 10);
			SortInsert(Arr6, 10);
			std::cout << std::endl;
			std::cout << "Elementi Posle Sortirovki Insertion(Shella) Sort" << std::endl;
			OutPutArr6(Arr6, 10);
			break;
		case 4:
			FillArr7(Arr7, 10, CLEAR);
			OutPutArr7(Arr7, 10);
			QuickSort(Arr7, 0, 9);
			std::cout << std::endl;
			std::cout << "Elementi Posle Sortirovki Quick Sort (Xoara)" << std::endl;
			OutPutArr7(Arr7, 10);
			break;
		case 5:
			FillArr8(Arr8, 10, CLEAR);
			OutPutArr8(Arr8, 10);
			MergerSort(Arr8, 0, 9);
			std::cout << std::endl;
			std::cout << "Elementi Posle Sortirovki Merger Sort" << std::endl;
			OutPutArr8(Arr8, 10);
			break;
		case 6:
			FillArr9(Arr9, 10, CLEAR);
			OutPutArr9(Arr9, 10);
			PidamidalSort(Arr9, 10);
			std::cout << std::endl;
			std::cout << "Elementi Posle Sortirovki Piramidal Sort" << std::endl;
			OutPutArr9(Arr9, 10);
			break;
		case 7:
			std::cout << "================================================" << std::endl;
			CLEAR = false;
			FillArr4(Arr4, 10, CLEAR);
			OutPutArr4(Arr4, 10);
			SortBubble(Arr4, 10);
			std::cout << "Elementi Posle Sortirovki Bubble Sort" << std::endl;
			OutPutArr4(Arr4, 10);
			FillArr5(Arr5, 10, CLEAR);
			std::cout << "================================================" << std::endl;
			OutPutArr5(Arr5, 10);
			SortSheker(Arr5, 10);
			std::cout << "Elementi Posle Sortirovki Sheker Sort" << std::endl;
			OutPutArr5(Arr5, 10);
			FillArr6(Arr6, 10, CLEAR);
			std::cout << "================================================" << std::endl;
			OutPutArr6(Arr6, 10);
			SortInsert(Arr6, 10);
			std::cout << "Elementi Posle Sortirovki Insertion(Shella) Sort" << std::endl;
			OutPutArr6(Arr6, 10);
			FillArr7(Arr7, 10, CLEAR);
			std::cout << "================================================" << std::endl;
			OutPutArr7(Arr7, 10);
			QuickSort(Arr7, 0, 9);
			std::cout << "Elementi Posle Sortirovki Quick Sort (Xoara)" << std::endl;
			OutPutArr7(Arr7, 10);
			FillArr8(Arr8, 10, CLEAR);
			std::cout << "================================================" << std::endl;
			OutPutArr8(Arr8, 10);
			MergerSort(Arr8, 0, 9);
			std::cout << "Elementi Posle Sortirovki Merger Sort" << std::endl;
			OutPutArr8(Arr8, 10);
			FillArr9(Arr9, 10, CLEAR);
			std::cout << "================================================" << std::endl;
			OutPutArr9(Arr9, 10);
			PidamidalSort(Arr9, 10);
			std::cout << "Elementi Posle Sortirovki Piramidal Sort" << std::endl;
			OutPutArr9(Arr9, 10);
			std::cout << "================================================" << std::endl;
			break;
		}
		break;
	case 3:
		speed = true;
		FillArr4(Arr4, M, CLEAR);
		t1 = clock();
		SortBubble(Arr4, M);
		t2 = clock() - t1;
		FillArr5(Arr5, M - 1, CLEAR);
		t3 = clock();
		SortSheker(Arr5, M);
		t4 = clock() - t3;
		FillArr6(Arr6, M, CLEAR);
		t5 = clock();
		SortInsert(Arr6, M);
		t6 = clock() - t5;
		FillArr7(Arr7, M, CLEAR);
		t7 = clock();
		QuickSort(Arr7, 0, M - 1);
		t8 = clock() - t7;
		FillArr7(Arr7, M, CLEAR);
		t9 = clock();
		MergerSort(Arr8, 0, M - 1);
		t10 = clock() - t9;
		FillArr9(Arr9, M, CLEAR);
		t11 = clock();
		PidamidalSort(Arr9, M);
		t12 = clock() - t11;
		break;
	}
	if (speed)
	{
		std::cout << "===========================================" << std::endl;
		std::cout << "Bubble Speed = " << t2 / CLOCKS_PER_SEC << std::endl;
		std::cout << "===========================================" << std::endl;
		std::cout << "Sheker Speed = " << t4 / CLOCKS_PER_SEC << std::endl;
		std::cout << "===========================================" << std::endl;
		std::cout << "PidamidalSort Speed = " << t12 / CLOCKS_PER_SEC << std::endl;
		std::cout << "===========================================" << std::endl;
		std::cout << "MergerSort Speed = " << t10 / CLOCKS_PER_SEC << std::endl;
		std::cout << "===========================================" << std::endl;
		std::cout << "Shell(insert) Speed = " << t6 / CLOCKS_PER_SEC << std::endl;
		std::cout << "===========================================" << std::endl;
		std::cout << "QuickSort(Xoara) Speed = " << t8 / CLOCKS_PER_SEC << std::endl;
		std::cout << "===========================================" << std::endl;
	}
	system("pause");
}