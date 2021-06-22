#pragma once
#include "Zivotinja.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

class Macka :public Zivotinja {
protected:
	string boja;
public:
	static int ukupnoMacaka;
	Macka();
	Macka(string tip, string naziv, double cena, int kolicina, string boja);
	~Macka();
	static int getUkupnoMacaka();
	string getBoju() const;
	void setBoju(string boja);
	void procitajZivotinju(Zivotinja* z);
	string zaUpis();
	list<Zivotinja*> dodajZivotinju(list<Zivotinja*> lista, Macka* zivotinja);
};