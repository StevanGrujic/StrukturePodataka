#include "Node.h"
Node::Node(int a)
{
	this->info = a;
	this->next = NULL;
}
Node::Node()
{
	this->next = NULL;
}
Node::Node(int a, Node* b)
{
	this->info = a;
	this->next = b;
}
bool Node::isEqual(int a)
{
	return (this->info == a);
}


