#pragma once
#include<string>
#include<iostream>
using namespace std;
class Termin
{
private:
	int t;//na onsovu t dobijam dan, godinu, termin i sat
	string jmbg;
	int status;//0-slobodan,1-obrisan,2-zauzet
public:
	Termin();
	Termin(int a, string jmbg);
	int getKey();
	bool isEqualKey(Termin& a);
	int getStatus()
	{
		return this->status;
	}
	void changeStatus(int a)
	{
		this->status = a;
	}
	void changeKey(int a)
	{
		this->t = a;
	}
	Termin& operator=(const Termin& a);
	bool isEqualKey(const Termin& a);
	bool operator==(const Termin& a);
	void print();
	friend ostream& operator<<(ostream& izlaz, const Termin& a);
};

