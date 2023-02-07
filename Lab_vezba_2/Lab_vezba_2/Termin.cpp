#include "Termin.h"
ostream& operator<<(ostream& izlaz, const Termin& a)
{
	izlaz << "JMBG: " << a.jmbg << endl;
	return izlaz;
}
Termin::Termin()
{
	this->t = 0;
	this->jmbg = "/";
}
Termin::Termin(int a, string b)
{
	this->t = a;
	this->jmbg = b;
}
int Termin::getKey()
{
	return this->t;
}
Termin& Termin:: operator=(const Termin& a)
{
	this->jmbg = a.jmbg;
	this->t = a.t;
	this->status = a.status;
	return *this;
}
bool Termin:: operator==(const Termin& a)
{
	return a.t == this->t;
}
bool Termin::isEqualKey(const Termin& a)
{
	return a.t == this->t;
}
void Termin::print()
{
	cout << *this;
}
