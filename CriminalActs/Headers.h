#pragma once
#include <string>
#include <vector>
using namespace std;

//Enums
enum ActType
{
	TrafficOffense = 1,
	Thieft = 2,
	Extortion = 3,
	Robbery = 4,
	Murder = 5,
};

enum FilterType
{
	Number = 1,
	Type = 2
};

//Structures
struct Act
{
	int number;
	ActType type;
	string caseOpenedDate;
	string caseEndDate;
	string leadingOficer;
	string accused;
	string victim;
	string witness;
};

//Functions
void add(Act& act);
void remove(int actIndex);
void modify(Act& act, int actIndex);
void modifyAct();
void filter(Act& act);
void save(Act& act);
void addActData();
Act findActByNum(int& number);
vector<Act> filterActsByType(int actType);
Act filterActsByNumber(int& actNumber);
void printActs();
int getActIndex(int& number);
void removeAct();
void filterActs();
void saveToFile();
void readFromFile();