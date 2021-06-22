#pragma once
#include <list>
#include <iostream>
#include <string>
#include <ostream>
#include "Zivotinja.h"
using namespace std;

template <class T>
class Racun {
	list<T*> lista;
public:
	Racun();
	Racun(list<T*> lista);
	double ukupnaCena();
	//void ispis();
	void setRacun(list<T*> lista);
};

template <>
class Racun<Zivotinja*> {
	list<Zivotinja*> lista;
public:
	Racun() {
		this->lista = {};
	}
	Racun(list<Zivotinja*> lista) {
		this->lista = lista;
	}
	double ukupnaCena() {
		double suma = 0;
		for (Zivotinja* z : lista) {
			suma += (z->getCena()*z->getKolicina());
		}
		return suma;
	}
	ostream& operator<<(ostream &s){
		s << "-----------------------------" << endl;
		s << "|   USPESNA KUPOVINA" << endl;
		s << "|   Vas racun:" << endl;
		for (Zivotinja* z : lista) {
			s << "|   " << z->getNaziv() << ": " << z->getCena() << " x " << z->getKolicina() << " = " << (z->getCena() * z->getKolicina()) << endl;
		}
		s << "-----------------------------" << endl;
		s << "|   Ukupno: " << ukupnaCena() << " dinara" << endl;
		s << "-----------------------------" << endl;
		return s;
	}
	void setRacun(list<Zivotinja*> lista) {
		this->lista = lista;
	}
};