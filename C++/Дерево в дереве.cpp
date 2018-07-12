#include <iostream> 
#include <list> 
#include <iterator> 

using namespace std;



int main()
{
	list<int> List;
	list<int>::iterator it, it1;
	int n;
	cout <<"Сколько элементов добавить в конец списка?" <<endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		List.push_back(i);
	}
	cout <<"Список с добавлением в конец: ";
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	cout <<endl;

	for (int i = 10; i > n - 1; i--) {
		List.push_front(i);
		List.push_front(3);
	}
	cout <<"Список с добавлением в начало: ";
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	cout <<endl;

	List.sort();
	cout <<"Список отсортированный: ";
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	cout <<endl;


	List.unique();//удаление повторяющихся элементов 
	cout <<"Список с удалёнными повторябщимися элементами: ";
	for (it = List.begin(); it != List.end(); it++)
		cout <<" " <<*it;
	cout <<endl;

	it = List.begin();
	++it;
	List.insert(it, 34);

	cout <<"Список с добавлением элемента в заданное место: ";
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	cout <<endl;


	it = List.begin();
	advance(it, 6);
	it = List.erase(it);
	//cout <<*it <<endl; 

	cout <<"Список удалённым элементом из заданного места: ";
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	cout <<endl;

}