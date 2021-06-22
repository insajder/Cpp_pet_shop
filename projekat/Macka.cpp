#pragma once
#include "Zivotinja.h"
#include <list>
#include <string>
#include <iostream>
#include "Macka.h"
using namespace std;


int Macka::ukupnoMacaka = 0;
Macka::Macka() :Zivotinja() {
	this->boja = "Nema";
}
Macka::Macka(string tip, string naziv, double cena, int kolicina, string boja)
	:Zivotinja(tip, naziv, cena, kolicina)
{
	this->boja = boja;
	this->ukupnoMacaka += kolicina;
}
Macka::~Macka() { ukupnoMacaka = 0; }
int Macka::getUkupnoMacaka() { return ukupnoMacaka; }
string Macka::getBoju() const { return this->boja; }
void Macka::setBoju(string boja) { this->boja = boja; }
void Macka::procitajZivotinju(Zivotinja* z) {
	z->procitajZivotinju();
	cout << ", Boja: " << boja << endl;
}
string Macka::zaUpis() {
	return tip + "~" + naziv + "~" + to_string(cena) + "~" + to_string(kolicina) + "~" + boja;
}
list<Zivotinja*> Macka::dodajZivotinju(list<Zivotinja*> lista, Macka* zivotinja) {
	bool postoji = false;
	for (Zivotinja* z : lista) {
		if (z->getNaziv().compare(zivotinja->getNaziv()) == 0) {
			postoji = true;
			break;
		}
	}
	if (postoji == false) {
		lista.push_back(zivotinja);
		cout << "Uspesno ste dodali zivotinju." << endl;
	}
	else {
		cout << "Ova zivotinja vec postoji." << endl;
	}
	return lista;
}