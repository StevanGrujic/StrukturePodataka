#include "Heap.h"
Heap::Heap()
{
	this->tren = 0;
	this->length = 0;
	this->niz = NULL;
}
Heap::Heap(int a)
{
	this->tren = 0;
	this->length = a;
	this->niz = new int[a + 1];
}
void Heap::insert(int el)
{
	tren++;
	int i = tren;
	while (i > 1 && niz[i / 2] > el)
	{
		niz[i] = niz[i / 2];
		i /= 2;
	}
	niz[i] = el;
}
int Heap::deleteRoot()
{
	if (tren == 0)
		throw "Prazno stablo";
	int result = niz[1];
	int last = niz[tren];
	tren--;
	int i = 1;
	while (2 * i <= tren)
	{
		int child = 2 * i;
		if (child + 1 <= tren && niz[child + 1] < niz[child])
			child += 1;
		if (last <= niz[child])
			break;
		niz[i] = niz[child];
		i = child;
	}
	niz[i] = last;
	return result;
}
void Heap::show()
{
	for (int i = 1; i <= tren; i++)
		cout << niz[i] << " ";
	cout << endl;
}
void Heap::preorder(int i)
{
	if (i <= tren)
	{
		cout << niz[i] << " ";
		preorder(2 * i);
		preorder(2 * i + 1);
	}
}
void Heap::mirrorCopy()
{
	int* niz2 = new int[tren + 1];
	if (tren == 0)
		return;
	niz2[1] = niz[1];
	int i = 2;
	while (i <= tren)
	{
		int k = 2 * i - 1;
		int l = i;
		while (l <= k)
		{
			if (k > tren)
				k = tren;
			niz2[i] = niz[k];
			k--;
			i++;
		}
	}
	for (int i = 1; i <= tren; i++)
		cout << niz2[i] << " ";
	cout << endl;
}
