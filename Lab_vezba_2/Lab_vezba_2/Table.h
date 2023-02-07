#pragma once
#include"Termin.h"
#define pocetna_godina 2019
class Table
{
private:
	unsigned int length;//velicina tablice
	unsigned int count;//trenutan broj zauzetih mesta u tablici
	Termin* niz;//niz termina
public:
	Table();
	Table(unsigned int duzina);
	~Table()
	{
		delete[] niz;
	}
	unsigned int getLength();
	unsigned int h(Termin& x);
	unsigned int h(int jm);
	unsigned int c(unsigned int);
	double getLoadFactor();
	unsigned int findUnoccupied(Termin& x);
	int findMatch(int key);
	void insert(Termin& x);
	Termin find(Termin& x);
	Termin find(int x);
	void withdraw(int key);
	void withdraw(Termin& x);
	void print(Termin& a);
	void print(int a);
	void print();
	unsigned int getHour(int x);
	unsigned int getTermin(int x);
	unsigned int getDay(int x);
	unsigned int getYear(int x);
	unsigned int getHour(Termin& x);
	unsigned int getTermin(Termin& x);
	unsigned int getDay(Termin& x);
	unsigned int getYear(Termin& x);
};








