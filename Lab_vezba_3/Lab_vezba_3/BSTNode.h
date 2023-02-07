#pragma once
#include<iostream>
using namespace std;
class BSTNode
{
public:
	int info;
	BSTNode* levi;
	BSTNode* desni;
public:
	BSTNode();
	BSTNode(int a);
	BSTNode(int a, BSTNode* b, BSTNode* c);
	int getInfo() { return info; }
	bool isLT(int el) { return info < el; }
	bool isGT(int el) { return info > el; }
	bool isEq(int el) { return info == el; }

};

