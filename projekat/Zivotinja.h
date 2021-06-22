#pragma once
#include <list>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Zivotinja {
protected:
	string tip;
	string naziv;
	double cena;
	int kolicina;
	
public:	
	static int ukupnoZivotinja;
	Zivotinja();
	Zivotinja(string tip, string naziv, double cena, int kolicina);
	~Zivotinja();
	static int getUkupnoZivotinja();
	string getTip() const;
	string getNaziv() const;
	double getCena() const;
	int getKolicina() const;
	void setTip(string tip);
	void setNaziv(string naziv);
	void setCena(double cena);
	void setKolicina(int kolicina);
	virtual void procitajZivotinju();
	virtual string zaUpis();
	virtual list<Zivotinja*> dodajZivotinju(list<Zivotinja*> lista, Zivotinja* zivotinja);
	static list<Zivotinja*> obrisiZivotinju(list<Zivotinja*> lista, string naziv);
	static bool kupiZivotinju(list<Zivotinja*> lista, string naziv, int kolicina);
	static double vratiCenu(list<Zivotinja*> lst, string naziv);

};
