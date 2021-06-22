#pragma once
#include <list>
#include <string>
#include <iostream>
#include <stack>
#include "Zivotinja.h"
#include <algorithm>
using namespace std;

int Zivotinja::ukupnoZivotinja = 0;
Zivotinja::Zivotinja() {
	this->tip = "Nema";
	this->naziv = "Nema";
	this->cena = 0.0;
	this->kolicina = 0;
}
Zivotinja::Zivotinja(string tip, string naziv, double cena, int kolicina) {
	this->tip = tip;
	this->naziv = naziv;
	this->cena = cena;
	this->kolicina = kolicina;
	this->ukupnoZivotinja += kolicina;
}
Zivotinja::~Zivotinja() { ukupnoZivotinja = 0; }
int Zivotinja::getUkupnoZivotinja() { return ukupnoZivotinja; }
string Zivotinja::getTip() const { return this->tip; }
string Zivotinja::getNaziv() const { return this->naziv; }
double Zivotinja::getCena() const { return this->cena; }
int Zivotinja::getKolicina() const { return this->kolicina; }
void Zivotinja::setTip(string tip) { this->tip = tip; }
void Zivotinja::setNaziv(string naziv) { this->naziv = naziv; }
void Zivotinja::setCena(double cena) { this->cena = cena; }
void Zivotinja::setKolicina(int kolicina) { this->kolicina = kolicina; }

void Zivotinja::procitajZivotinju() {
	cout << tip << " - " << naziv << ", Cena: " << cena << ", Kolicina: " << kolicina;
}

string Zivotinja::zaUpis() { return " "; }
list<Zivotinja*> Zivotinja::dodajZivotinju(list<Zivotinja*> lista, Zivotinja* zivotinja) { return lista; }
list<Zivotinja*> Zivotinja::obrisiZivotinju(list<Zivotinja*> lista, string naziv) {
	bool postoji = false;
	for (Zivotinja* z : lista) {
		if (z->getNaziv().compare(naziv) == 0) {
			postoji = true;
			lista.remove(z);
			cout << "Uspesno ste obrisali zivotinju." << endl;
			break;
		}
	}
	if (postoji == false) {
		cout << "Ova zivotinja ne postoji." << endl;
	}
	return lista;
}
bool Zivotinja::kupiZivotinju(list<Zivotinja*> lista, string naziv, int kolicina) {
	bool postoji = false;
	transform(naziv.begin(), naziv.end(), naziv.begin(), ::tolower);
	naziv[0] = toupper(naziv[0]);

	for (Zivotinja* z : lista) {
		if (z->getNaziv().compare(naziv) == 0) {
			postoji = true;
			if (z->getKolicina() >= kolicina) {
				z->setKolicina(z->getKolicina() - kolicina);
				break;
			}
			else {
				cout << "Nema dovoljno" << endl;
				return false;
				break;
			}
		}
	}
	if (postoji == false) {
		cout << "Ova zivotinja ne postoji." << endl;
		return false;
	}
	else {
		return true;
	}
	//return lista;
}
double Zivotinja::vratiCenu(list<Zivotinja*> lst, string naziv) {
	bool postoji = false;
	double cena = 0;
	for (Zivotinja* z : lst) {
		if (z->getNaziv().compare(naziv) == 0) {
			postoji = true;
			cena = z->getCena();
			break;
		}
	}
	if (postoji == false) {
		cout << "Ova zivotinja ne postoji." << endl;
	}
	return cena;
}
