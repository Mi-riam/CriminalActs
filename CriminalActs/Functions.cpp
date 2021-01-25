#include "Headers.h"
#include <iostream>
#include <fstream>

vector<Act> acts;

//mutating functions
void add(Act& act)
{
	acts.push_back(act);
	saveToFile();
}

void remove(int actIndex)
{
	acts.erase(acts.begin() + actIndex);
}

void modify(Act& act, int actIndex)
{
	acts[actIndex] = act;
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

void removeAct()
{
	int actNumber;

	cout << "\nPodaj numer akta do usuniecia" << endl;
	cin >> actNumber;

	auto actIndex = getActIndex(actNumber);

	if (actIndex == -1)
	{
		cout << "\nNie ma w bazie akta z takim numerem. " << endl << endl;
	}
	else
	{
		remove(actIndex);
	}
}

void modifyAct() {
	int actNumber;
	Act actToModify;

	cout << "\nPodaj numer akta do modyfikacji" << endl;
	cin >> actNumber;

	auto actIndex = getActIndex(actNumber);

	if (actIndex == -1)
	{
		cout << "\nNie ma w bazie akta z takim numerem. " << endl << endl;
	}
	else
	{
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

		modify(actToModify, actIndex);
	}
}

void filterActs()
{
	int givenFilterType;
	cout << "\nWybierz po czym chcesz wyszukac/przefiltrowac akta:\n1 Po numerze\n2 Po typie\n" << endl;
	cin >> givenFilterType;

	if (givenFilterType == FilterType::Number)
	{
		int actNumber;
		cout << "\nPodaj numer akta: " << endl;
		cin >> actNumber;

		auto result = filterActsByNumber(actNumber);
		if (result.number == NULL)
		{
			cout << "\nBrak resultatow." << endl;
		}
		else
		{
			cout << result.number << endl;
			cout << result.type << endl;
			cout << result.caseOpenedDate << endl;
			cout << result.caseEndDate << endl;
			cout << result.leadingOficer << endl;
			cout << result.accused << endl;
			cout << result.victim << endl;
			cout << result.witness << endl;
		}
	}
	else if (givenFilterType == FilterType::Type)
	{
		int actType;
		cout << "\nWybierz po jakim typie chcesz filtrowac:\n1 Wykroczenie drogowe\n2 Kradziez\n3 Wymuszenie\n4 Rozboj\n5 Zabojstwo\n";
		cin >> actType;

		auto filteredActs = filterActsByType(actType);
		if (filteredActs.size() == 0)
		{
			cout << "\nBrak resultatow." << endl;
		}
		else
		{
			for (int i = 0; i < filteredActs.size(); i++) {
				auto act = filteredActs[i];
				cout << endl;
				cout << act.number << endl;
				cout << act.type << endl;
				cout << act.caseOpenedDate << endl;
				cout << act.caseEndDate << endl;
				cout << act.leadingOficer << endl;
				cout << act.accused << endl;
				cout << act.victim << endl;
				cout << act.witness << endl << endl;
			}
		}
	}


}

void printActs() {
	for (int i = 0; i < acts.size(); i++) {
		auto act = acts[i];
		cout << endl;
		cout << act.number << endl;
		cout << act.type << endl;
		cout << act.caseOpenedDate << endl;
		cout << act.caseEndDate << endl;
		cout << act.leadingOficer << endl;
		cout << act.accused << endl;
		cout << act.victim << endl;
		cout << act.witness << endl << endl;
	}
}
//
//void setActsData()
//{
//
//}

//OperationOnVector
int getActIndex(int& number) {
	int index = -1;
	for (int i = 0; i < acts.size(); i++) {
		if (acts[i].number == number) {
			index = i;
		}
	}
	return  index;
}


Act findActByNum(int& number) {
	Act foundedAct;
	for (int i = 0; i < acts.size(); i++) {
		if (acts[i].number == number) {
			foundedAct = acts[i];
		}
	}
	return  foundedAct;
}

vector<Act> filterActsByType(int actType) {
	vector<Act>  filteredActs;

	for (int i = 0; i < acts.size(); i++) {
		if (acts[i].type == actType) {
			filteredActs.push_back(acts[i]);
		}
	}
	return filteredActs;
}

Act filterActsByNumber(int& actNumber) {
	Act  filteredAct;

	for (int i = 0; i < acts.size(); i++) {
		if (acts[i].number == actNumber) {
			filteredAct = acts[i];
		}
	}
	return filteredAct;
}

void saveToFile()
{
	fstream outFile;
	typename vector<Act>::size_type actsSize = acts.size();

	outFile.open("../dataBase.bin", fstream::out | fstream::binary);

	if (outFile.is_open())
	{
		outFile.write((char*)&actsSize, sizeof(actsSize));
		outFile.write((char*)&acts[0], acts.size() * sizeof(Act));
		outFile.close();
	}
	else
	{
		cout << "BLAD PODCZAS OTWARCIA PLIKU. " << endl;
	}
}

void readFromFile()
{
	fstream outFile;
	typename vector<Act>::size_type actsSize = acts.size();

	outFile.open("../dataBase.bin", fstream::in | fstream::binary);

	if (outFile.is_open())
	{
		outFile.read((char*)&actsSize, sizeof(actsSize));
		acts.resize(actsSize);
		outFile.read((char*)&acts[0], (acts.size() * sizeof(Act)));
		outFile.close();
	}
	else
	{
		cout << " BLAD PODCZAS OTWARCIA DO OCZYTU Z PLIKU " << endl;

	}
}