#pragma once
#include<iostream>
using namespace std;
class Edge;
class Node
{
public:
	int node;
	Node* next;
	Edge* adj;
	int status;
	int distance;
	Node* parent;
public:
	Node();
	Node(int a);
	Node(int a, Node* n, Edge* e, int s);
	~Node();
	void visitNode();
};

