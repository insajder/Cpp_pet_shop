#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include "Zivotinja.h"
#include "Pas.h"
#include "Macka.h"
#include "Racun.h"
#include <map>
#include <algorithm>
using namespace std;

extern list<Zivotinja*> procitajIzDatoteke();
extern void upisiUDatoteku(list<Zivotinja*> lista);

bool ptrsorter(Zivotinja* a, Zivotinja* b) {
	return a->getNaziv().compare(b->getNaziv()) < 0;
}

int main() {
	string opcija;
	cout << "PRODAJA KUCNIH LJUBIMACA" << endl;
	while (1) {
		list<Zivotinja*> lista = procitajIzDatoteke();
		cout << "*************************" << endl;
		cout << "1 - Izlistaj sve zivotinje" << endl;
		cout << "2 - Dodaj zivotinju" << endl;
		cout << "3 - Obrisi zivotinju" << endl;
		cout << "4 - Kupi zivotinju" << endl;
		cout << "5 - Izvestaj" << endl;
		cout << "6 - Pretrazi po nazivu" << endl;
		cout << "X - Izadji iz aplikacije" << endl;
		cout << "*************************" << endl;
		getline(cin, opcija);

		multimap<string, double> mojaMapa;
		deque<Zivotinja*> mojDeque;
		bool izlaz = false;
		string tip = "";
		string naziv = "";
		double cena = 0.0;
		int kolicina = 0;
		int starost = 0;
		string boja = "";
		bool postoji = false;
		list<Zivotinja*> lst_kupi;
		Racun<Zivotinja*> racun;

		switch (opcija[0]) {
		case '1':
			lista.sort(ptrsorter);
			for (Zivotinja* z : lista) {
				mojDeque.emplace_back(z);
			}
			for (auto& x : mojDeque) {
				if (x->getTip().compare("Pas") == 0) {
					Pas* pas = static_cast<Pas*>(x);
					pas->procitajZivotinju(x); cout << endl;
				}
				else {
					Macka* macka = static_cast<Macka*>(x);
					macka->procitajZivotinju(x); cout << endl;
				}
			}
			break;
		case '2':
			cout << "Uneti tip (macka/pas):" << endl;
			getline(cin, tip);
			transform(tip.begin(), tip.end(), tip.begin(), ::tolower);
			tip[0] = toupper(tip[0]);
			if (tip == "Pas" || tip == "Macka") {

				cout << "Uneti naziv:" << endl;
				getline(cin, naziv);
				transform(naziv.begin(), naziv.end(), naziv.begin(), ::tolower);
				naziv[0] = toupper(naziv[0]);

				cout << "Uneti cenu:" << endl;
				cin >> cena;
				while (!(cin.good())) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Pogresan unos, pokusajte ponovo: ";
				}
				cout << "Uneti kolicinu:" << endl;
				cin >> kolicina;
				while (!(cin.good())) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Pogresan unos, pokusajte ponovo: ";
				}
				if (tip.compare("Pas") == 0) {
					cout << "Uneti starost(m):" << endl;
					cin >> starost;
					while (!(cin.good())) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Pogresan unos, pokusajte ponovo: ";
					}
					Pas* p = new Pas(tip, naziv, cena, kolicina, starost);
					lista = p->dodajZivotinju(lista, p);
				}
				else {
					cin.ignore();
					cout << "Uneti boju:" << endl;
					getline(cin, boja);
					Macka* m = new Macka(tip, naziv, cena, kolicina, boja);
					lista = m->dodajZivotinju(lista, m);
				}
				cin.ignore();
				upisiUDatoteku(lista);
			}
			else {
				cout << "Ovaj tip ne postoji" << endl;
			}
			break;
		case '3':
			cout << "Uneti naziv:" << endl;
			getline(cin, naziv);
			transform(naziv.begin(), naziv.end(), naziv.begin(), ::tolower);
			naziv[0] = toupper(naziv[0]);

			lista = Zivotinja::obrisiZivotinju(lista, naziv);
			upisiUDatoteku(lista);
			break;
		case '4':
			while (1) {
				cout << "Uneti naziv (X - za kraj kupovine):" << endl;
				getline(cin, naziv);
				transform(naziv.begin(), naziv.end(), naziv.begin(), ::tolower);
				naziv[0] = toupper(naziv[0]);

				if (naziv[0] == 'X' || naziv[0] == 'x') break;

				cout << "Uneti kolicinu:" << endl;
				cin >> kolicina;
				while (!(cin.good())) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Pogresan unos, pokusajte ponovo: ";
				}
				cin.ignore();
				if (Zivotinja::kupiZivotinju(lista, naziv, kolicina)) {
					//lista = Zivotinja::kupiZivotinju(lista, naziv, kolicina);
					cena = Zivotinja::vratiCenu(lista, naziv);
					lst_kupi.push_back(new Zivotinja("", naziv, cena, kolicina));
					upisiUDatoteku(lista);
				}
			}
			if (!lst_kupi.empty()) {
				racun.setRacun(lst_kupi);
				racun << cout << endl;
			}
			break;
		case '5':
			cout << "Ukupan broj zivotinja: " << Zivotinja::getUkupnoZivotinja() << endl;
			cout << "Ukupno psa: " << Pas::getUkupnoPsa() << endl;
			cout << "Ukupno macaka: " << Macka::getUkupnoMacaka() << endl;
			break;
		case '6':
			for (Zivotinja* z : lista) {
				mojaMapa.insert(make_pair(z->getNaziv(), z->getCena()));
			}
			cout << "Uneti naziv:" << endl;
			getline(cin, naziv);
			transform(naziv.begin(), naziv.end(), naziv.begin(), ::tolower);
			naziv[0] = toupper(naziv[0]);
			for (multimap<string, double>::iterator it = mojaMapa.begin(); it != mojaMapa.end(); it++) {
				if (it->first == naziv) {
					cout << "Pronadjena: " << endl;
					cout << it->first << ", cena: " << it->second << endl;
					postoji = true;
					break;
				}
			}
			if (postoji == false) cout << "Nije pronadjena." << endl;

			break;
		case 'X': case 'x':
			izlaz = true;
			break;
		default:
			cout << "Neispravna opcija" << endl;
			break;
		}

		if (izlaz == true) break;
		Zivotinja zzz;
		zzz.~Zivotinja();
		Pas ppp;
		ppp.~Pas();
		Macka mmm;
		mmm.~Macka();
	}

	system("pause");
	return 0;
}