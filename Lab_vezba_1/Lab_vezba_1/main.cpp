#include "List.h"
int main()
{
	List a;
	a.addToHead(5);
	a.addToHead(4);
	a.addToHead(2);
	a.addToTail(16);
	a.addToTail(18);
	a.print();
	a.update(4,19);
	cout << endl;
	a.print();
	a.update(19, 1);
	cout << endl;
	a.print();
	a.update(1, 6);
	cout << endl;
	a.print();
	return 0;
}