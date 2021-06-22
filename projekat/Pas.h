#pragma once
#include "Zivotinja.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

class Pas :public Zivotinja {
protected:
	int starost;
public:
	static int ukupnoPasa;
	Pas();
	Pas(string tip, string naziv, double cena, int kolicina, int starost);
	~Pas();
	static int getUkupnoPsa();
	int getStarost() const;
	void setStarost(int starost);
	void procitajZivotinju(Zivotinja* z);
	string zaUpis();
	list<Zivotinja*> dodajZivotinju(list<Zivotinja*> lista, Pas* zivotinja);
};