#include <iostream> 
#include <list> 
#include <iterator> 

using namespace std;



int main()
{
	list<int> List;
	list<int>::iterator it, it1;
	int n;
	cout <<"������� ��������� �������� � ����� ������?" <<endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		List.push_back(i);
	}
	cout <<"������ � ����������� � �����: ";
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	cout <<endl;

	for (int i = 10; i > n - 1; i--) {
		List.push_front(i);
		List.push_front(3);
	}
	cout <<"������ � ����������� � ������: ";
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	cout <<endl;

	List.sort();
	cout <<"������ ���������������: ";
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	cout <<endl;


	List.unique();//�������� ������������� ��������� 
	cout <<"������ � ��������� �������������� ����������: ";
	for (it = List.begin(); it != List.end(); it++)
		cout <<" " <<*it;
	cout <<endl;

	it = List.begin();
	++it;
	List.insert(it, 34);

	cout <<"������ � ����������� �������� � �������� �����: ";
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	cout <<endl;


	it = List.begin();
	advance(it, 6);
	it = List.erase(it);
	//cout <<*it <<endl; 

	cout <<"������ �������� ��������� �� ��������� �����: ";
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	cout <<endl;

}