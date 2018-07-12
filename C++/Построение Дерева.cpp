#include <iostream> 
#include <string> 

using namespace std;

struct student
{
	string name;//слово 
	student *left = nullptr;
	student *right = nullptr;
};

struct city
{
	string NAME;//слово 
	city *left = nullptr;
	city *right = nullptr;
	student *root = nullptr;
};


void Addstd(student* &studBranch, string namestud)
{
	if (!studBranch) {
		studBranch = new student;
		studBranch->name = namestud;
	}
	else if (studBranch->name > namestud) {
		Addstd(studBranch->left, namestud);
	}
	else if (studBranch->name < namestud) {
		Addstd(studBranch->right, namestud);
	}
}

void Add(city* &cityBranch, string &namecity, string &namestud)
{
	if (!cityBranch) {
		cityBranch = new city;
		cityBranch->NAME = namecity;
		Addstd(cityBranch->root, namestud);
	}
	else if (cityBranch->NAME > namecity) {
		Add(cityBranch->left, namecity, namestud);
	}
	else if (cityBranch->NAME < namecity) {
		Add(cityBranch->right, namecity, namestud);
	}
	else {
		Addstd(cityBranch->root, namestud);
	}
}



void printstd(student* stdBranch)
{
	if (!stdBranch) return;

	printstd(stdBranch->left);
	cout << " " << stdBranch->name << endl;

	printstd(stdBranch->right);

	return;
}


void print(city* cityBranch)
{
	if (!cityBranch) return;

	print(cityBranch->left);
	cout << cityBranch->NAME << endl;
	printstd(cityBranch->root);
	print(cityBranch->right);
	return;
}


void FreeTreeSTD(student* stdBranch)
{
	if (!stdBranch) return;
	FreeTreeSTD(stdBranch->left);
	FreeTreeSTD(stdBranch->right);
	delete stdBranch;
	return;
}

void FreeTree(city* cityBranch)
{
	if (!cityBranch) return;
	FreeTreeSTD(cityBranch->root);
	FreeTree(cityBranch->left);
	FreeTree(cityBranch->right);
	delete cityBranch;
	return;
}

int main() {
	city *root = nullptr;
	student *rootstd = nullptr;
	string namecity, namestud;
	int n;
	cout <<"¬ведите количество слов:";
	cin >> n;
	cin.get();//пропускаем 1 символ (см. ниже дл€ чего) 
			  //(cin >> n).get();//вводим число и пропускаем 1 символ,чтобы гетлайн читал 1ую строку 
	for (int i = 0; i < n; i++) {
		cout << "¬ведите название города:" << endl;
		getline(cin, namecity);
		cout << "¬ведите »м€ студента:" << endl;
		getline(cin, namestud);
		Add(root, namecity, namestud);
	}
	print(root);
	FreeTree(root);
	return(0);
}