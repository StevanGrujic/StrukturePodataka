#include "Edge.h"
#include"Node.h"
Edge::Edge()
{
	this->dest = NULL;
	this->link = NULL;
}
Edge::Edge(Edge* e, Node* n)
{
	this->link = e;
	this->dest = n;
}