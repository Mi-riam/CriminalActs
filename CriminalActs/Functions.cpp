#include "Headers.h"
#include <iostream>

vector<Act> acts;

void add(Act& act)
{
	acts.push_back(act);
}

void remove()
{
	acts.clear();
}

void addActData() {
	int typeCase;
	Act act;

	cout << "\nPodaj numer akt sprawy:\n";
	cin >> act.number;
	cout << "\nWybierz typ akt:\n1 Wykroczenie drogowe\n2 Kradziez\n3 Wymuszenie\n4 Rozboj\n5 Zabojstwo\n";
	cin >> typeCase;

	switch (typeCase)
	{
	case 1: {
		act.type = ActType::TrafficOffense;
		break;
	}

	case 2: {
		act.type = ActType::Thieft;
		break;
	}

	case 3: {
		act.type = ActType::Extortion;
		break;
	}

	case 4: {
		act.type = ActType::Robbery;
		break;
	}

	case 5: {
		act.type = ActType::Murder;
		break;
	}

	default: {
		cout << "Bledny wybor.";
		break;
	}
	}

	cout << "\nPodaj date wszczecia sprawy (dzien/miesiac/rok): " << endl;
	cin >> act.caseOpenedDate;
	cout << "\nPodaj date zakonczenia sprawy - puste jesli sprawa w toku (dzien/miesiac/rok):  " << endl;
	cin >> act.caseEndDate;
	cout << "\nPodaj imie i nazwisko oficera prowadzacego:" << endl;
	cin >> act.leadingOficer;
	cout << "\nPodaj imie i nazwisko oskarzonego (jesli nie ma pozostawic puste):" << endl;
	cin >> act.accused;
	cout << "\nPodaj imie i nazwisko poszkodowanego (puste jezeli nie dotyczy):" << endl;
	cin >> act.victim;
	cout << "\nPodaj imie i nazwisko swiadka: " << endl;
	cin >> act.witness;

	add(act);
}

void modifyAct() {
	int actNumber;
	cout << "Podaj numer akta do modyfikacji";
	cin >> actNumber;

	cout << "\nPodaj numer akta do modyfikacji" << endl;
	auto actToModify = findActByNum(actNumber);


	cout << "\nPodaj date wszczecia sprawy (dzien/miesiac/rok): " << endl;
	cin >> actToModify.caseOpenedDate;
	cout << "\nPodaj date zakonczenia sprawy - puste jesli sprawa w toku (dzien/miesiac/rok):  " << endl;
	cin >> actToModify.caseEndDate;
	cout << "\nPodaj imie i nazwisko oficera prowadzacego:" << endl;
	cin >> actToModify.leadingOficer;
	cout << "\nPodaj imie i nazwisko oskarzonego (jesli nie ma pozostawic puste):" << endl;
	cin >> actToModify.accused;
	cout << "\nPodaj imie i nazwisko poszkodowanego (puste jezeli nie dotyczy):" << endl;
	cin >> actToModify.victim;
	cout << "\nPodaj imie i nazwisko swiadka: " << endl;
	cin >> actToModify.witness;

	modify(actToModify);
}

void printActs() {
	for (int i = 0; i < acts.size(); i++) {
		cout << acts[i].leadingOficer;
	}
}

//OperationOnVector
Act findActByNum(int& number) {
	Act foundedAct;
	for (int i = 0; i < acts.size(); i++) {
		if (acts[i].number == number) {
			foundedAct = acts[i];
		}
	}
	return  foundedAct;
}

vector<Act> filterActsByType(ActType& actType) {
	vector<Act>  filteredActs;

	for (int i = 0; i < acts.size(); i++) {
		if (acts[i].type == actType) {
			filteredActs.push_back(acts[i]);
		}
	}
	return filteredActs;
}

vector<Act> filterActsByNumber(int& actNumber) {
	vector<Act>  filteredActs;

	for (int i = 0; i < acts.size(); i++) {
		if (acts[i].number == actNumber) {
			filteredActs.push_back(acts[i]);
		}
	}
	return filteredActs;
}