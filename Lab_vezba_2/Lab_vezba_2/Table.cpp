#include "Table.h"
Table::Table()
{
	this->count = 0;
	this->length = 0;
	this->niz = NULL;
}
Table::Table(unsigned int duzina)
{
	this->length = duzina;
	this->count = 0;
	this->niz = new Termin[length];
}
unsigned int Table::getLength()
{
	return this->length;
}
unsigned int Table::h(Termin& x)
{
	unsigned const int a = 2654435769;
	int k = x.getKey();
	unsigned const ak = a * k;
	return (a * k) >> (32 - 13);
}
unsigned int Table::h(int key)
{
	unsigned const int a = 2654435769;
	int k = key;
	unsigned const ak = a * k;
	return (a * k) >> (32 - 13);
}
unsigned int Table::c(unsigned int i)
{
	return (5 * i * i);
}
double Table::getLoadFactor()
{
	return ((double)count / (double)length);
}
unsigned int Table::findUnoccupied(Termin& x)
{
	int probe = h(x);
	int hash = probe;
	if (niz[probe].getStatus() < 2)
		return probe;
	int i = 1;
	do
	{
		probe = (hash + c(i)) % length;
		if (niz[probe].getStatus() < 2)
			return probe;
		i++;
	} while (probe != hash && i < length);
	throw "Nema mesta za zadati element";

}
int Table::findMatch(int key)
{
	int probe = h(key);
	if (niz[probe].getKey() == key && niz[probe].getStatus() == 2)
		return probe;
	if (niz[probe].getStatus() < 2)
		return -1;
	int hash = probe;         //0 slobodan 1 obrisan 2 zauzet
	int i = 1;
	probe = (hash + c(i)) % length;
	while (niz[probe].getKey() != key && probe != hash)
	{
		probe = (hash + c(i)) % length;
		i++;
	}
	if (niz[probe].getStatus() < 2)
		return-1;
	if (niz[probe].getKey() == key)
		return probe;
	throw "Nema poklapanja!";
}
void Table::insert(Termin& x)
{
	if (count == length)
		throw "Tablica je puna";
	int a = findUnoccupied(x);
	niz[a] = x;
	niz[a].changeStatus(2);
	this->count++;

}
Termin Table::find(Termin& x)
{
	int a = findMatch(x.getKey());
	if (a >= 0)
		return niz[a];
	throw "Element nije nadjen!";
}
Termin Table::find(int x)
{
	long a = findMatch(x);
	if (a >= 0)
		return niz[a];
	throw "Element nije nadjen!";
}
void Table::withdraw(int key)
{
	if (count == 0)
		throw "Tablica je prazna";
	int a = findMatch(key);
	if (a < 0)
		throw "Element nije nadjen";
	niz[a].changeStatus(1);
	niz[a].~Termin();
	count--;



}
void Table::withdraw(Termin& x)
{
	if (count == 0)
		throw "Tablica je prazna";
	int a = findMatch(x.getKey());
	if (a < 0)
		throw "Element nije nadjen";
	niz[a].changeStatus(1);
	niz[a].~Termin();
	count--;

}
void Table::print()
{
	for (int i = 0; i < length; i++)
	{
		cout << i << " ";
		niz[i].print();
		cout << "------------------------" << endl;
	}
}
void Table::print(int a)
{
	if (findMatch(a) > 0)
		cout << "Pozicija:" << findMatch(a) << "  " << niz[findMatch(a)] << endl;
	else
		throw "Ne postoji takav termin u tablici!";
}
void Table::print(Termin& a)
{
	if (findMatch(a.getKey()) > 0)
	cout << "Pozicija:" << findMatch(a.getKey()) << "  " << niz[findMatch(a.getKey())] << endl;
	else
	throw "Ne postoji takav termin u tablici!";

}
unsigned int Table::getHour(int x)
{
	if (x >= 0)
	{
		cout << "Vreme trazenog klijenta je: " << endl;
		int a = (10 + (((x % (365 * 48)) % 48) / 6));
		cout << "Od " << a << " sati-";
		return a;
	}
	throw "Nije validno";
}
unsigned int Table::getTermin(int x)
{
	if (x >= 0)
	{
		int a = (x % 6) + 1;
		cout << a << ".termin, ";
		return a;
	}
	throw "Nije validno";
}
unsigned int Table::getDay(int x)
{
	if (x >= 0)
	{
		int a = ((x % 365) / 48) + 1;
		cout << a << ".dan u ";
		return a;
	}
	throw "Nije validno";
}
unsigned int Table::getYear(int x)
{
	if (x >= 0)
	{
		int a = (x / (365 * 48));
		cout << a + pocetna_godina << ".godini" << endl;
		return a;
	}
	throw "Nije validno";
}
unsigned int Table::getHour(Termin& x)
{
	if (x.getKey() >= 0)
	{
		cout << "Vreme trazenog klijenta je: " << endl;
		int a = (10 + (((x.getKey() % (365 * 48)) % 48) / 6));
		cout << "Od " << a << " sati-";
		return a;
	}
	throw "Nije validno";
}
unsigned int Table::getTermin(Termin& x)
{
	if (x.getKey() >= 0)
	{
		int a = (x.getKey() % 6) + 1;
		cout << a << ".termin, ";
		return a;
	}
	throw "Nije validno";
}
unsigned int Table::getDay(Termin& x)
{
	if (x.getKey() >= 0)
	{
		int a = ((x.getKey() % 365) / 48) + 1;
		cout << a << ".dan u ";
		return a;
	}
	throw "Nije validno";
}
unsigned int Table::getYear(Termin& x)
{
	if (x.getKey() >= 0)
	{
		int a = (x.getKey() / (365 * 48));
		cout << a + pocetna_godina << ".godini" << endl;
		return a;
	}
	throw "Nije validno";
}







