#pragma once
#include "Zivotinja.h"
#include <list>
#include <string>
#include <iostream>
#include "Pas.h"
using namespace std;


int Pas::ukupnoPasa = 0;
Pas::Pas() :Zivotinja() {
	this->starost = 0;
}
Pas::Pas(string tip, string naziv, double cena, int kolicina, int starost)
	:Zivotinja(tip, naziv, cena, kolicina)
{
	this->starost = starost;
	this->ukupnoPasa += kolicina;
}
Pas::~Pas() { ukupnoPasa = 0; }
int Pas::getUkupnoPsa() { return ukupnoPasa; }
int Pas::getStarost() const { return this->starost; }
void Pas::setStarost(int starost) { this->starost = starost; }
void Pas::procitajZivotinju(Zivotinja* z) {
	z->procitajZivotinju();
	cout << ", Starost: " << starost << endl;
}
string Pas::zaUpis() {
	return getTip() + "~" + getNaziv() + "~" + to_string(getCena()) + "~" + to_string(getKolicina()) + "~" + to_string(getStarost());
}
list<Zivotinja*> Pas::dodajZivotinju(list<Zivotinja*> lista, Pas* zivotinja) {

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