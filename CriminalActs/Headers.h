#pragma once
#include <string>
#include <vector>
using namespace std;

//Enums
enum ActType {
	TrafficOffense = 1,
	Thieft = 2,
	Extortion = 3,
	Robbery = 4,
	Murder = 5,
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
void remove();
void modify(Act& act);
void modifyAct();
void filter(Act& act);
void save(Act& act);
void addActData();
Act findActByNum(int& number);
vector<Act> filterActsByType(ActType& actType);
vector<Act> filterActsByNumber(int& actNumber);
void printActs();