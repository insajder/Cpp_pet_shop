#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <cctype>
#include <locale>

#include "Zivotinja.h"
#include "Pas.h"
#include "Macka.h"

using namespace std;

list<Zivotinja*> procitajIzDatoteke() {
	list<Zivotinja*> lista;
	fstream f;
	f.open("zivotinje.txt", ios::in | ios::_Nocreate);
	if (!f) {
		cout << "Ne postoji datoteka!";
	}

	stack<Zivotinja*> mojStek;

	string red = "";
	while (getline(f, red)) {
		string tip = "";
		string naziv = "";
		string cena = "";
		string kolicina = "";
		string podatak = "";
		int br = 0;

		for (int i = 0; i < red.length(); i++) {
			if (red[i] == '~') {
				br++;
				continue;
			}
			if (br == 0) tip += red[i];
			if (br == 1) naziv += red[i];
			if (br == 2) cena += red[i];
			if (br == 3) kolicina += red[i];
			if (br == 4) podatak += red[i];
		}

		if (tip.compare("Pas") == 0) {
			Zivotinja* z = new Pas(tip, naziv, stod(cena), stoi(kolicina), stoi(podatak));
			//lista.push_back(z);
			mojStek.push(z);
		}
		else {
			Zivotinja* z = new Macka(tip, naziv, stod(cena), stoi(kolicina), podatak);
			//lista.push_back(z);
			mojStek.push(z);
		}
	}
	while (!mojStek.empty()) {
		lista.push_back(mojStek.top());
		mojStek.pop();
	}

	f.close();
	return lista;
}

void upisiUDatoteku(list<Zivotinja*> lista) {
	fstream f;
	f.open("zivotinje.txt", ios::out);
	if (!f) {
		cout << "Ne postoji datoteka!";
	}

	for (Zivotinja* z : lista) {
		string upis = "";
		if (z->getTip().compare("Pas") == 0) {
			Pas* pas = static_cast<Pas*>(z);
			upis = pas->zaUpis();
		}
		else {
			Macka* macka = static_cast<Macka*>(z);
			upis = macka->zaUpis();
		}
		f << upis << "\n";
	}

	f.close();
}