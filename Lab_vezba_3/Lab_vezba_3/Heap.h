#pragma once
#include<iostream>
using namespace std;
class Heap
{
private:
	int* niz;
	unsigned int length;
	unsigned int tren;
public:
	Heap();
	Heap(int a);
	void insert(int a);
	int deleteRoot();
	void preorder(int i);
	void preorder() { preorder(1); }
	void show();
	void mirrorCopy();
};

