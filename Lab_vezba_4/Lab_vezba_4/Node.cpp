#include "Node.h"
#include"Edge.h"
#include<limits>

Node::Node()
{
	this->node = 1;
	this->distance = INT32_MAX;
	this->status = 0;
	this->adj = NULL;
	this->next = NULL;
	this->parent = NULL;
}
Node::Node(int a)
{
	this->distance = INT32_MAX;
	this->node = a;
	this->adj = NULL;
	this->next = NULL;
	this->status = 0;
	this->parent = nullptr;
}
Node::Node(int a, Node* n, Edge* e, int s)
{
	this->distance = INT32_MAX;
	this->node = a;
	this->next = n;
	this->adj = e;
	this->status = s;
	this->parent = NULL;
}
Node::~Node()
{
	Edge* p = this->adj;
	while (this->adj != NULL)
	{
		this->adj = p->link;
		delete p;
		p = adj;
	}
}

void Node::visitNode()
{
	cout << this->node << endl;
}