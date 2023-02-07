#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	int info;
	Node* next;
public:
	Node();
	Node(int a);
	Node(int a, Node* b);
	~Node() {};
	int print() { return info; };
	bool isEqual(int a);
};

