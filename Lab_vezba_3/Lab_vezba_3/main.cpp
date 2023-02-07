#include"Heap.h"
#include"BSTree.h"
int main()
{
	Heap x(15);
	x.insert(1);
	x.insert(2);
	x.insert(3);
	x.insert(17);
	x.insert(19);
	x.insert(36);
	x.insert(7);
	x.insert(25);
	x.insert(100);
	x.insert(33);
	x.insert(40);
	x.insert(14);
	x.show();
	cout << "Izbrisani koren heapa je:" << x.deleteRoot() << endl;
	cout << "Preorder obilazak heapa nakon brisanja korena: " << endl;
	x.preorder();
	cout << endl;
	cout << "Obilazak heapa po sirini: " << endl;
	x.show();
	cout << "Mirror kopija heapa: " << endl;
	x.mirrorCopy();
	cout << "-------------------------" << endl;

	Heap y(8);
	y.insert(6);
	y.insert(8);
	y.insert(4);
	y.insert(1);
	y.insert(2);
	y.insert(9);
	y.show();
	cout << "Mirror kopija heapa: " << endl;
	y.mirrorCopy();
	cout << "--------------------------" << endl;

	BSTree q;
	q.insert(6);
	q.insert(9);
	q.insert(2);
	q.insert(1);
	q.insert(4);
	q.insert(8);
	cout << "Preorder obilazak binarnog stabla: " << endl;
	q.preorder();
	cout << endl;
	cout << "Obilazak po sirini: " << endl;
	q.poSirini();
	cout << endl;
	cout << "Nakon brisanja listova: " << endl;
	q.deleteExternalNodes();
	q.poSirini();
	cout << endl;
	cout << "---------------------------" << endl;

	BSTree t;
	t.insert(8);
	t.insert(14);
	t.insert(10);
	t.insert(7);
	t.insert(4);
	t.insert(6);
	t.insert(1);
	t.insert(3);
	t.insert(13);

	BSTNode* root = t.vratiRoot();
	int suma = INT32_MIN;
	BSTNode* a = new BSTNode();
	t.maxChildrenSum(root, &suma, &a);
	cout << "Najveca suma je: " << suma << "Cvor: " << a->info << endl;
	cout << "Obilazak stabla po sirini: " << endl;
	t.poSirini();
	cout << endl;
	cout << "Preorder obilazak stabla: " << endl;
	t.preorder();

	cout << "(Brisanje listova...) " << endl;
	t.deleteExternalNodes();
	cout << "Nakon brisanja listova: " << endl;
	t.poSirini();



	return 0;
}