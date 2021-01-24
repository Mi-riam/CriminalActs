#include <iostream>
#include "Headers.h"

using namespace std;


int main()
{
	int choice = 0;

	while (choice != 5)
	{
		cout << "\tARCHIWUM KRYMINALNE" << endl;
		cout << "Wybierz funkcje:\n1 Dodanie akt\n2 Usuniecie akt\n3 Zmiana danych akt\n4 Wyszukaj\n5 Koniec programu/wyjscie\n6 Pokaz Dane" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			addActData();
			break;
		}

		case 2:
		{
			remove();
			break;

		}

		case 3:
		{
			modifyAct();
			break;
		}

		/*

		case 4:
		{
			WYSZUKAJ(archiwum[n]);
			break;
		}
		case 5:
		{
			return 0;
		}*/
		case 6:
		{
			printActs();
			break;
		}
		default:
		{
			cout << "Bledny wybor funkcji.\n\n";
		}
		}
	}
}
