#pragma once
#include <iostream>
#include <vector>
// содержит только прототипы функций
namespace Poisk
{
	/*ALGORITMI POISKA*/
	//======================================================

	// FILL ARRAYS 
	void FillArr1(std::vector<int>&, const int&);
	void FillArr2(std::vector<int>&, const int&);
	void FillArr3(std::vector<int>&, const int&);

	// OUTPUT ARRAYS
	void OutPutArr1(std::vector<int>&, const int&);
	void OutPutArr2(std::vector<int>&, const int&);
	void OutPutArr3(std::vector<int>&, const int&);

	// SEARCH ELEMENTS
	void Lineyniy(std::vector<int>&, const int&);
	void Bunarny(std::vector<int>&, const int&);
	void Barier(std::vector<int>&, const int&);
	//======================================================
	// MENU
	int FirstMenu();
	int MenuSearch();
	int MenuSort();
	//======================================================

	/*Soring Arrays*/

	// FILL Arrays
	void FillArr4(std::vector<int>&, const int&, bool);
	void FillArr5(std::vector<int>&, const int&, bool);
	void FillArr6(std::vector<int>&, const int&, bool);
	void FillArr7(std::vector<int>&, const int&, bool);
	void FillArr8(std::vector<int>&, const int&, bool);
	void FillArr9(std::vector<int>&, const int&, bool);

	//  OUTPUT ARRAYS
	void OutPutArr4(std::vector<int>&, const int&);
	void OutPutArr5(std::vector<int>&, const int&);
	void OutPutArr6(std::vector<int>&, const int&);
	void OutPutArr7(std::vector<int>&, const int&);
	void OutPutArr8(std::vector<int>&, const int&);
	void OutPutArr9(std::vector<int>&, const int&);


	// ALGORITMI SORTIROVKI
	void SortBubble(std::vector<int>&, const int&);
	void SortSheker(std::vector<int>&, const int&);
	void SortInsert(std::vector<int>&, const int&);
	void QuickSort(std::vector<int>&, int, int);
	void MergerSort(std::vector<int>&, int, int);
	void Merg(std::vector<int>&, int, int);
	void PidamidalSort(std::vector<int>&, int);
	void siftDownPiramidal(std::vector<int>&, int, int);
}