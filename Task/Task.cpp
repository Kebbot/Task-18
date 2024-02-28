#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
#include "iomanip"
using namespace std;
const size_t N = 2;
typedef char T[N];
struct library
{
	char title[100];
	char author[100];
	char pub_house[100];
	char genre[100];
};
library L[N];
void liun() //заполнение нулями
{
	for (int t = 0; t < N; t++)
		L[t].title[0] = '\0';
}

char menu()//выбор меню, проверка выбора, через функцию strchr
{
	char ch;
	do {

		cout << "\n enter'q' Edit book";
		cout << "\n enter'e' Print all books";
		cout << "\n enter'u' Search for books by author";
		cout << "\n enter'd' Book search by title";
		cout << "\n'z' if you want to exit the program press space";
		cout << endl;
		cin >> ch;
		if (ch == 'z') { return ch; }
	} while (!strchr("eduq ", tolower(ch)));
	return ch;
}
void enter()//ввод значений
{

	int t = 0; char povtor = 'y';
	do {
		for (t = 0; t < N; t++)
			if (!L[t].title[0]) { break; }
		if (t == N) { cout << "massiv error"; return; }
		cout << "\nenter Edit book\t";
		cin >> L[t].title;
		cout << "\nenter author\t";
		cin >> L[t].author;
		cout << "\nenter pub_house\t";
		cin >> L[t].pub_house;
		cout << "\nenter  genre\t";
		cin >> L[t].genre;
		cout << "\nIf you want to enter more, press 'Y'\t";
		cin >> povtor;
	} while ((povtor) == 'Y' || povtor == 'y');
}
void print()//Печать всех книг
{
	int t = 0;
	for (t = 0; t < N; t++)
	{
		if (L[t].title[0] == '\0') { break; }
		cout << "\n" << t + 1 << "book" << endl;
		cout << "\nenter Edit book\t" << L[t].title;
		cout << "\nenter author\t" << L[t].author;
		cout << "\nenter pub_house\t" << L[t].pub_house;
		cout << "\nenter genre\t" << L[t].genre << endl;
	}
}
void Search_title()//фукция поиска по названию книги через функцию strcmp
{
	char name[100];
	cout << "\nenter book title to search";
	cin >> (name);
	int t;
	for (t = 0; t < N; t++)
		if (!(strcmp(name, L[t].title))) { break; }
	if (t == N) { cout << "\nno such book"; }
	else
	{
		cout << "\n Edit book" << setw(8) << L[t].title;
		cout << "\n author\t" << setw(10) << L[t].author;
		cout << "\n pub_house\t" << setw(2) << L[t].pub_house;
		cout << "\n genre\t" << setw(10) << L[t].genre << endl;
	}
}
void Search_author()//поиск книги по автору через функцию strcmp
{

	char name[100];
	cout << "\nenter book author to search";
	cin >> (name);
	int t;
	for (t = 0; t < N; t++)
		if (!(strcmp(name, L[t].author))) { break; }
	if (t == N) { cout << "\nno such book"; }
	cout << "\n Edit book" << setw(8) << L[t].title;
	cout << "\n author\t" << setw(10) << L[t].author;
	cout << "\n pub_house\t" << setw(2) << L[t].pub_house;
	cout << "\n  genre\t" << setw(10) << L[t].genre << endl;
}
void edit_book()
{

	char name[100];
	cout << "\nenter book title to search";
	cin >> (name);
	int t;
	for (t = 0; t < N; t++)
		if (!(strcmp(name, L[t].title))) { break; }
	if (t == N) { cout << "there is no such book"; return; }
	cout << "\nenter Edit book\t";
	cin >> L[t].title;
	cout << "\nenter author\t";
	cin >> L[t].author;
	cout << "\nenter pub_house\t";
	cin >> L[t].pub_house;
	cout << "\nenter  genre\t";
	cin >> L[t].genre;
}
int main()
{
	char choice; char vyxod = 'a';
	liun();//присваеваем нули всему массиву
	enter();// осуществляем поиск свободного элемента и делаем ввод данных

	do {

		choice = menu();// выбор действия которое необходимо провести

		switch (choice)
		{
		case 'e':

			print();

			break;
		case 'd'://Search book by title
			Search_title();
			break;
		case 'u':
			Search_author();
			break;
		case 'q':
			edit_book();
			break;
		case 'z':
			vyxod = 'z';

			break;
		default:
			vyxod = 'z';

			break;
		}
	} while (!((vyxod) == 'z'));

	/*struct type {
		char item[40];
		double cost;
		double ret;
		int on_hand;
		int lead;};
	type first;
	first.ret = 10.36;
	cout << "\n Vvedite";
	gets_s(first.item);
	cout << first.ret;
	cout << first.item;
	for (int i = 0; first.item[i]; i++)
		cout << "\n" << first.item[i];
	type arr[N];

	*/
	return 0;
}
