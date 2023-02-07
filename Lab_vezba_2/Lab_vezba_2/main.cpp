#include"Table.h"
int main()
{
	try {
		Termin s(3, "1508999780013");
		Termin s1(36, "1501996340013");
		Termin s2(2415, "0308999780013");
		Termin s3(3000, "1508993480013");
		Termin s4(1256, "1304997894413");
		Termin s5(1417, "0101972780025");
		Termin s6(18346, "1309979780047");//prelazi u sledecu godinu jer je 18346>365*48, 48 je broj termina u jednom danu
		Table q(8192);
		cout << q.h(3) << endl;
		q.insert(s);
		cout << q.findUnoccupied(s) << endl;
		q.insert(s);//test kolizije
		cout << q.findUnoccupied(s) << endl;//test za findUnoccupied funkciju,
		q.insert(s1);
		q.insert(s2);
		q.insert(s3);
		q.insert(s4);
		q.insert(s5);
		q.insert(s6);
		cout << "-------------" << endl;
		q.print(s);
		q.print(s1);  
		q.print(s2);
		q.print(s3);
		q.print(s4);
		q.print(s5);
		q.print(s6);
		q.withdraw(s4);
		q.getHour(s6);
		q.getTermin(s6);
		q.getDay(s6);
		q.getYear(s6);
		q.getHour(s1);
		q.getTermin(s1);
		q.getDay(s1);
		q.getYear(s1);
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	return 0;
}